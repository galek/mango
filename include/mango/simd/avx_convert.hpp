/*
    MANGO Multimedia Development Platform
    Copyright (C) 2012-2017 Twilight Finland 3D Oy Ltd. All rights reserved.
*/
#pragma once

#include "simd.hpp"
#include "common.hpp"

namespace mango {
namespace simd {
namespace detail {

	template <int bits>
	struct reinterpret_vector;

	template <>
	struct reinterpret_vector<128>
	{
		__m128 data;

	    template <typename ScalarType, int Size, typename VectorType>
	    reinterpret_vector(hardware_vector<ScalarType, Size, VectorType> v)
        : data(v)
	    {
	    }

	    template <typename ScalarType, int Size>
	    reinterpret_vector(hardware_vector<ScalarType, Size, __m128i> v)
        : data(_mm_castsi128_ps(v))
	    {
	    }

	    template <typename ScalarType, int Size>
	    reinterpret_vector(hardware_vector<ScalarType, Size, __m128d> v)
        : data(_mm_castpd_ps(v))
	    {
	    }

		template <typename ScalarType, int Size, typename VectorType>
		operator hardware_vector<ScalarType, Size, VectorType> ()
		{
			return hardware_vector<ScalarType, Size, VectorType>(data);
		}

		template <typename ScalarType, int Size>
		operator hardware_vector<ScalarType, Size, __m128i> ()
		{
			return hardware_vector<ScalarType, Size, __m128i>(_mm_castps_si128(data));
		}

		template <typename ScalarType, int Size>
		operator hardware_vector<ScalarType, Size, __m128d> ()
		{
			return hardware_vector<ScalarType, Size, __m128d>(_mm_castps_pd(data));
		}
	};

	template <>
	struct reinterpret_vector<256>
	{
	    __m256 data;

	    template <typename ScalarType, int Size, typename VectorType>
	    reinterpret_vector(hardware_vector<ScalarType, Size, VectorType> v)
        : data(v)
	    {
	    }

	    template <typename ScalarType, int Size>
	    reinterpret_vector(hardware_vector<ScalarType, Size, __m256i> v)
        : data(_mm256_castsi256_ps(v))
	    {
	    }

	    template <typename ScalarType, int Size>
	    reinterpret_vector(hardware_vector<ScalarType, Size, __m256d> v)
        : data(_mm256_castpd_ps(v))
	    {
	    }

	    template <typename T>
	    reinterpret_vector(composite_vector<T> v)
	    {
		    std::memcpy(this, &v, 32);
	    }

    	template <typename ScalarType, int Size, typename VectorType>
    	operator hardware_vector<ScalarType, Size, VectorType> ()
	    {
		    return hardware_vector<ScalarType, Size, VectorType>(data);
	    }

	    template <typename ScalarType, int Size>
	    operator hardware_vector<ScalarType, Size, __m256i> ()
	    {
		    return hardware_vector<ScalarType, Size, __m256i>(_mm256_castps_si256(data));
	    }

	    template <typename ScalarType, int Size>
	    operator hardware_vector<ScalarType, Size, __m256d> ()
	    {
		    return hardware_vector<ScalarType, Size, __m256d>(_mm256_castps_pd(data));
	    }

	    template <typename T>
	    operator composite_vector<T> ()
	    {
    		composite_vector<T> temp;
		    std::memcpy(&temp, this, 32);
		    return temp;
	    }
    };

} // namespace detail

    // -----------------------------------------------------------------
    // reinterpret
    // -----------------------------------------------------------------

	template <typename D, typename S0, int S1, typename S2>
	inline D reinterpret(hardware_vector<S0, S1, S2> s)
	{
        static_assert(sizeof(hardware_vector<S0, S1, S2>) == sizeof(D), "Vectors must be same size.");
		return D(detail::reinterpret_vector<hardware_vector<S0, S1, S2>::vector_bits>(s));
	}

	template <typename D, typename S>
	inline D reinterpret(composite_vector<S> s)
	{
        static_assert(sizeof(composite_vector<S>) == sizeof(D), "Vectors must be same size.");
		return D(detail::reinterpret_vector<composite_vector<S>::vector_bits>(s));
	}

    // -----------------------------------------------------------------
    // convert
    // -----------------------------------------------------------------

	template <typename D, typename S>
	inline D convert(S)
	{
		D::undefined_conversion();
	}

	template <typename D, typename S>
	inline D truncate(S)
	{
		D::undefined_conversion();
	}

    // -----------------------------------------------------------------
    // zero extend
    // -----------------------------------------------------------------

#if defined(MANGO_ENABLE_SSE4_1)

    static inline uint16x8 extend16(uint8x16 s)
    {
        return _mm_cvtepu8_epi16(s);
    }

    static inline uint32x4 extend32(uint8x16 s)
    {
        return _mm_cvtepu8_epi32(s);
    }

    static inline uint32x4 extend32(uint16x8 s)
    {
        return _mm_cvtepu16_epi32(s);
    }

#else

    static inline uint16x8 extend16(uint8x16 s)
    {
        return _mm_unpacklo_epi8(s, _mm_setzero_si128());
    }

    static inline uint32x4 extend32(uint8x16 s)
    {
        const __m128i temp = _mm_unpacklo_epi8(s, _mm_setzero_si128());
        return _mm_unpacklo_epi16(temp, _mm_setzero_si128());
    }

    static inline uint32x4 extend32(uint16x8 s)
    {
        return _mm_unpacklo_epi16(s, _mm_setzero_si128());
    }

#endif

    // -----------------------------------------------------------------
    // sign extend
    // -----------------------------------------------------------------

#if defined(MANGO_ENABLE_SSE4_1)

    static inline int16x8 extend16(int8x16 s)
    {
        return _mm_cvtepi8_epi16(s);
    }

    static inline int32x4 extend32(int8x16 s)
    {
        return _mm_cvtepi8_epi32(s);
    }

    static inline int32x4 extend32(int16x8 s)
    {
        return _mm_cvtepi16_epi32(s);
    }

#else

    static inline int16x8 extend16(int8x16 s)
    {
        const __m128i sign = _mm_cmpgt_epi8(_mm_setzero_si128(), s);
        return _mm_unpacklo_epi8(s, sign);
    }

    static inline int32x4 extend32(int8x16 s)
    {
        const __m128i temp = _mm_unpacklo_epi8(s, _mm_cmpgt_epi8(_mm_setzero_si128(), s));
        return _mm_unpacklo_epi16(temp, _mm_cmpgt_epi16(_mm_setzero_si128(), temp));
    }

    static inline int32x4 extend32(int16x8 s)
    {
        const __m128i sign = _mm_cmpgt_epi16(_mm_setzero_si128(), s);
        return _mm_unpacklo_epi16(s, sign);
    }

#endif

    // -----------------------------------------------------------------
    // pack
    // -----------------------------------------------------------------

    static inline uint8x16 pack(uint16x8 a, uint16x8 b)
    {
        return _mm_packus_epi16(a, b);
    }

    static inline uint16x8 pack(uint32x4 a, uint32x4 b)
    {
        return simd128_packus_epi32(a, b);
    }

    static inline int8x16 pack(int16x8 a, int16x8 b)
    {
        return _mm_packs_epi16(a, b);
    }

    static inline int16x8 pack(int32x4 a, int32x4 b)
    {
        return _mm_packs_epi32(a, b);
    }

    // -----------------------------------------------------------------
    // float32
    // -----------------------------------------------------------------

    static inline float32x2 get_low(float32x4 a)
    {
        float x = get_x(a);
        float y = get_y(a);
        return float32x2_set2(x, y);
    }

    static inline float32x2 get_high(float32x4 a)
    {
        float z = get_z(a);
        float w = get_w(a);
        return float32x2_set2(z, w);
    }

    static inline float32x4 set_low(float32x4 a, float32x2 low)
    {
        a = set_x(a, get_x(low));
        a = set_y(a, get_y(low));
        return a;
    }

    static inline float32x4 set_high(float32x4 a, float32x2 high)
    {
        a = set_z(a, get_x(high));
        a = set_w(a, get_y(high));
        return a;
    }

    static inline float32x4 combine(float32x2 a, float32x2 b)
    {
        float x = get_x(a);
        float y = get_y(a);
        float z = get_x(b);
        float w = get_y(b);
        return float32x4_set4(x, y, z, w);
    }

    static inline float32x4 get_low(float32x8 a)
    {
        return _mm256_extractf128_ps(a, 0);
    }

    static inline float32x4 get_high(float32x8 a)
    {
        return _mm256_extractf128_ps(a, 1);
    }

    static inline float32x8 set_low(float32x8 a, float32x4 low)
    {
        return _mm256_insertf128_ps(a, low, 0);
    }

    static inline float32x8 set_high(float32x8 a, float32x4 high)
    {
        return _mm256_insertf128_ps(a, high, 1);
    }

    static inline float32x8 combine(float32x4 a, float32x4 b)
    {
        return _mm256_insertf128_ps(_mm256_castps128_ps256(a), b, 1);
    }

    template <>
    inline float32x2 convert<float32x2>(float64x2 s)
    {
        float32x4 temp = _mm_cvtpd_ps(s);
        float x = get_x(temp);
        float y = get_y(temp);
        return float32x2_set2(x, y);
    }

    template <>
    inline float32x4 convert<float32x4>(uint32x4 s)
    {
        const __m128i mask = _mm_set1_epi32(0x0000ffff);
        const __m128i onep39 = _mm_set1_epi32(0x53000000);
        const __m128i x0 = _mm_or_si128(_mm_srli_epi32(s, 16), onep39);
        const __m128i x1 = _mm_and_si128(s, mask);
        const __m128 f1 = _mm_cvtepi32_ps(x1);
        const __m128 f0 = _mm_sub_ps(_mm_castsi128_ps(x0), _mm_castsi128_ps(onep39));
        return _mm_add_ps(f0, f1);
    }

    template <>
    inline float32x4 convert<float32x4>(int32x4 s)
    {
        return _mm_cvtepi32_ps(s);
    }

    template <>
    inline uint32x4 convert<uint32x4>(float32x4 s)
    {
	    __m128 x2 = _mm_castsi128_ps(_mm_set1_epi32(0x4f000000));
	    __m128 x1 = _mm_cmple_ps(x2, s);
  	    __m128i x0 = _mm_cvtps_epi32(_mm_sub_ps(s, _mm_and_ps(x2, x1)));
  	    return _mm_or_si128(x0, _mm_slli_epi32(_mm_castps_si128(x1), 31));
    }

    template <>
    inline int32x4 convert<int32x4>(float32x4 s)
    {
        return _mm_cvtps_epi32(s);
    }

    template <>
    inline int32x4 truncate<int32x4>(float32x4 s)
    {
        return _mm_cvttps_epi32(s);
    }

#if defined(MANGO_ENABLE_AVX2)

    template <>
    inline int32x8 convert<int32x8>(float32x8 s)
    {
        return _mm256_cvtps_epi32(s);
    }

    template <>
    inline float32x8 convert<float32x8>(int32x8 s)
    {
        return _mm256_cvtepi32_ps(s);
    }

    template <>
    inline uint32x8 convert<uint32x8>(float32x8 s)
    {
	    __m256 x2 = _mm256_castsi256_ps(_mm256_set1_epi32(0x4f000000));
	    __m256 x1 = _mm256_cmp_ps(x2, s, 2);
  	    __m256i x0 = _mm256_cvtps_epi32(_mm256_sub_ps(s, _mm256_and_ps(x2, x1)));
  	    return _mm256_or_si256(x0, _mm256_slli_epi32(_mm256_castps_si256(x1), 31));
    }

    template <>
    inline float32x8 convert<float32x8>(uint32x8 s)
    {
        const __m256i mask = _mm256_set1_epi32(0x0000ffff);
        const __m256i onep39 = _mm256_set1_epi32(0x53000000);
        const __m256i x0 = _mm256_or_si256(_mm256_srli_epi32(s, 16), onep39);
        const __m256i x1 = _mm256_and_si256(s, mask);
        const __m256 f1 = _mm256_cvtepi32_ps(x1);
        const __m256 f0 = _mm256_sub_ps(_mm256_castsi256_ps(x0), _mm256_castsi256_ps(onep39));
        return _mm256_add_ps(f0, f1);
    }

#else

    template <>
    inline int32x8 convert<int32x8>(float32x8 s)
    {
        int32x8 result;
        result.lo = convert<int32x4>(get_low(s));
        result.hi = convert<int32x4>(get_high(s));
        return result;
    }

    template <>
    inline float32x8 convert<float32x8>(int32x8 s)
    {
        float32x4 lo = convert<float32x4>(s.lo);
        float32x4 hi = convert<float32x4>(s.hi);
        return combine(lo, hi);
    }

    template <>
    inline uint32x8 convert<uint32x8>(float32x8 s)
    {
        uint32x8 result;
        result.lo = convert<uint32x4>(get_low(s));
        result.hi = convert<uint32x4>(get_high(s));
        return result;
    }

    template <>
    inline float32x8 convert<float32x8>(uint32x8 s)
    {
        float32x4 lo = convert<float32x4>(s.lo);
        float32x4 hi = convert<float32x4>(s.hi);
        return combine(lo, hi);
    }

#endif

    // -----------------------------------------------------------------
    // float64
    // -----------------------------------------------------------------

    static inline float64x2 get_low(float64x4 a)
    {
        return _mm256_extractf128_pd(a, 0);
    }

    static inline float64x2 get_high(float64x4 a)
    {
        return _mm256_extractf128_pd(a, 1);
    }

    static inline float64x4 set_low(float64x4 a, float64x2 low)
    {
        return _mm256_insertf128_pd(a, low, 0);
    }

    static inline float64x4 set_high(float64x4 a, float64x2 high)
    {
        return _mm256_insertf128_pd(a, high, 1);
    }

    static inline float64x4 combine(float64x2 a, float64x2 b)
    {
        return _mm256_insertf128_pd(_mm256_castpd128_pd256(a), b, 1);
    }

    template <>
    inline float64x2 convert<float64x2>(float32x2 s)
    {
        float x = s[0];
        float y = s[1];
        const __m128 temp = _mm_setr_ps(x, y, x, y);
        return _mm_cvtps_pd(temp);
    }

    template <>
    inline float64x4 convert<float64x4>(int32x4 s)
    {
        return _mm256_cvtepi32_pd(s);
    }

    template <>
    inline float64x4 convert<float64x4>(float32x4 s)
    {
        return _mm256_cvtps_pd(s);
    }

    template <>
    inline int32x4 convert<int32x4>(float64x4 s)
    {
        return _mm256_cvtpd_epi32(s);
    }

    template <>
    inline float32x4 convert<float32x4>(float64x4 s)
    {
        return _mm256_cvtpd_ps(s);
    }

#if defined(MANGO_ENABLE_AVX2)

    template <>
    inline float64x4 convert<float64x4>(uint32x4 ui)
    {
        const __m256d bias = _mm256_set1_pd((1ll << 52) * 1.5);
        const __m256i xyzw = _mm256_cvtepu32_epi64(ui);
        __m256d v = _mm256_castsi256_pd(xyzw);
        v = _mm256_or_pd(v, bias);
        v = _mm256_sub_pd(v, bias);
        return v;
    }

#else

    template <>
    inline float64x4 convert<float64x4>(uint32x4 ui)
    {
        const __m256d bias = _mm256_set1_pd((1ll << 52) * 1.5);
        const __m128i mask = _mm_set1_epi32(0x43380000);
        const __m128i xy = _mm_unpacklo_epi32(ui, mask);
        const __m128i zw = _mm_unpackhi_epi32(ui, mask);
        const __m256i xyzw = _mm256_insertf128_si256(_mm256_castsi128_si256(xy), zw, 1);
        __m256d v = _mm256_castsi256_pd(xyzw);
        v = _mm256_sub_pd(v, bias);
        return v;
    }

#endif

    template <>
    inline uint32x4 convert<uint32x4>(float64x4 d)
    {
        const __m256d bias = _mm256_set1_pd((1ll << 52) * 1.5);
        const __m256d v = _mm256_add_pd(d, bias);
        const __m128d xxyy = _mm256_castpd256_pd128(v);
        const __m128d zzww = _mm256_extractf128_pd(v, 1);
        __m128 xyzw = _mm_shuffle_ps(_mm_castpd_ps(xxyy), _mm_castpd_ps(zzww), 0x88);
        return _mm_castps_si128(xyzw);
    }

    static inline int32x4 int32x4_truncate(float64x4 s)
    {
        return _mm256_cvttpd_epi32(s);
    }

    // -----------------------------------------------------------------
    // float16
    // -----------------------------------------------------------------

#ifdef MANGO_ENABLE_F16C

    template <>
    inline float32x4 convert<float32x4>(float16x4 h)
    {
        const __m128i* p = reinterpret_cast<const __m128i *>(&h);
        return _mm_cvtph_ps(_mm_loadl_epi64(p));
    }

    template <>
    inline float16x4 convert<float16x4>(float32x4 f)
    {
        float16x4 h;
        __m128i* p = reinterpret_cast<__m128i *>(&h);
        _mm_storel_epi64(p, _mm_cvtps_ph(f, 0));
        return h;
    }

#else

    template <>
    inline float32x4 convert<float32x4>(float16x4 h)
    {
        const __m128i* p = reinterpret_cast<const __m128i *>(&h);
        const int32x4 u = _mm_unpacklo_epi16(_mm_loadl_epi64(p), _mm_setzero_si128());

        int32x4 no_sign  = bitwise_and(u, int32x4_set1(0x7fff));
        int32x4 sign     = bitwise_and(u, int32x4_set1(0x8000));
        int32x4 exponent = bitwise_and(u, int32x4_set1(0x7c00));
        int32x4 mantissa = bitwise_and(u, int32x4_set1(0x03ff));

        // NaN or Inf
        int32x4 a = bitwise_or(int32x4_set1(0x7f800000), slli(mantissa, 13));

        // Zero or Denormal
        const int32x4 magic = int32x4_set1(0x3f000000);
        int32x4 b;
        b = add(magic, mantissa);
        b = reinterpret<int32x4>(sub(reinterpret<float32x4>(b), reinterpret<float32x4>(magic)));

        // Numeric Value
        int32x4 c = add(int32x4_set1(0x38000000), slli(no_sign, 13));

        // Select a, b, or c based on exponent
        int32x4 mask;
        int32x4 result;

        mask = compare_eq(exponent, int32x4_zero());
        result = select(mask, b, c);

        mask = compare_eq(exponent, int32x4_set1(0x7c00));
        result = select(mask, a, result);

        // Sign
        result = bitwise_or(result, slli(sign, 16));

        return reinterpret<float32x4>(result);
    }

    template <>
    inline float16x4 convert<float16x4>(float32x4 f)
    {
        const float32x4 magic = float32x4_set1(Float(0, 15, 0).f);
        const int32x4 vinf = int32x4_set1(31 << 23);

        const int32x4 u = reinterpret<int32x4>(f);
        const int32x4 sign = srli(bitwise_and(u, int32x4_set1(0x80000000)), 16);

        const int32x4 vexponent = int32x4_set1(0x7f800000);

        // Inf / NaN
        const int32x4 s0 = compare_eq(bitwise_and(u, vexponent), vexponent);
        int32x4 mantissa = bitwise_and(u, int32x4_set1(0x007fffff));
        int32x4 x0 = compare_eq(mantissa, int32x4_zero());
        mantissa = select(x0, int32x4_zero(), srai(mantissa, 13));
        const int32x4 v0 = bitwise_or(int32x4_set1(0x7c00), mantissa);

        int32x4 v1 = bitwise_and(u, int32x4_set1(0x7ffff000));
        v1 = reinterpret<int32x4>(mul(reinterpret<float32x4>(v1), magic));
        v1 = add(v1, int32x4_set1(0x1000));

#if defined(MANGO_ENABLE_SSE4_1)
        v1 = _mm_min_epi32(v1, vinf);
        v1 = srai(v1, 13);

        int32x4 v = select(s0, v0, v1);
        v = bitwise_or(v, sign);
        v = _mm_packus_epi32(v, v);
#else
        v1 = int32x4_select(compare_gt(v1, vinf), vinf, v1);
        v1 = srai(v1, 13);

        int32x4 v = select(s0, v0, v1);
        v = bitwise_or(v, sign);
        v = _mm_slli_epi32 (v, 16);
        v = _mm_srai_epi32 (v, 16);
        v = _mm_packs_epi32 (v, v);
#endif

        float16x4 h;
        _mm_storel_epi64(reinterpret_cast<__m128i *>(&h), v);
        return h;
    }

#endif // MANGO_ENABLE_F16C

} // namespace simd
} // namespace mango
