/*
    MANGO Multimedia Development Platform
    Copyright (C) 2012-2017 Twilight Finland 3D Oy Ltd. All rights reserved.
*/
#pragma once

#include "simd.hpp"

namespace mango {
namespace simd {

#define SET_COMPONENT(vec, value, mask, index) \
    if (index <= mask) vec.lo = set_component<index & mask>(vec.lo, value); \
    else               vec.hi = set_component<index & mask>(vec.hi, value)

#define GET_COMPONENT(vec, mask, index) \
        Index <= mask ? get_component<index & mask>(vec.lo) \
                      : get_component<index & mask>(vec.hi)

    // -----------------------------------------------------------------
    // uint8x32
    // -----------------------------------------------------------------

    template <unsigned int Index>
    static inline uint8x32 set_component(uint8x32 a, uint8 b)
    {
        static_assert(Index < 32, "Index out of range.");
        SET_COMPONENT(a, b, 15, Index);
        return a;
    }

    template <unsigned int Index>
    static inline uint8 get_component(uint8x32 a)
    {
        static_assert(Index < 32, "Index out of range.");
        return GET_COMPONENT(a, 15, Index);
    }

    static inline uint8x32 uint8x32_zero()
    {
        uint8x32 result;
        result.lo = uint8x16_zero();
        result.hi = uint8x16_zero();
        return result;
    }

    static inline uint8x32 uint8x32_set1(uint8 s)
    {
        uint8x32 result;
        result.lo = uint8x16_set1(s);
        result.hi = uint8x16_set1(s);
        return result;
    }

    static inline uint8x32 unpacklo(uint8x32 a, uint8x32 b)
    {
        uint8x32 result;
        result.lo = unpacklo(a.lo, b.lo);
        result.hi = unpacklo(a.hi, b.hi);
        return result;
    }

    static inline uint8x32 unpackhi(uint8x32 a, uint8x32 b)
    {
        uint8x32 result;
        result.lo = unpackhi(a.lo, b.lo);
        result.hi = unpackhi(a.hi, b.hi);
        return result;
    }

    static inline uint8x32 add(uint8x32 a, uint8x32 b)
    {
        uint8x32 result;
        result.lo = add(a.lo, b.lo);
        result.hi = add(a.hi, b.hi);
        return result;
    }

    static inline uint8x32 sub(uint8x32 a, uint8x32 b)
    {
        uint8x32 result;
        result.lo = sub(a.lo, b.lo);
        result.hi = sub(a.hi, b.hi);
        return result;
    }

    static inline uint8x32 mullo(uint8x32 a, uint8x32 b)
    {
        uint8x32 result;
        result.lo = mullo(a.lo, b.lo);
        result.hi = mullo(a.hi, b.hi);
        return result;
    }

    // saturated

    static inline uint8x32 adds(uint8x32 a, uint8x32 b)
    {
        uint8x32 result;
        result.lo = adds(a.lo, b.lo);
        result.hi = adds(a.hi, b.hi);
        return result;
    }

    static inline uint8x32 subs(uint8x32 a, uint8x32 b)
    {
        uint8x32 result;
        result.lo = subs(a.lo, b.lo);
        result.hi = subs(a.hi, b.hi);
        return result;
    }

    // bitwise

    static inline uint8x32 bitwise_nand(uint8x32 a, uint8x32 b)
    {
        uint8x32 result;
        result.lo = bitwise_nand(a.lo, b.lo);
        result.hi = bitwise_nand(a.hi, b.hi);
        return result;
    }

    static inline uint8x32 bitwise_and(uint8x32 a, uint8x32 b)
    {
        uint8x32 result;
        result.lo = bitwise_and(a.lo, b.lo);
        result.hi = bitwise_and(a.hi, b.hi);
        return result;
    }

    static inline uint8x32 bitwise_or(uint8x32 a, uint8x32 b)
    {
        uint8x32 result;
        result.lo = bitwise_or(a.lo, b.lo);
        result.hi = bitwise_or(a.hi, b.hi);
        return result;
    }

    static inline uint8x32 bitwise_xor(uint8x32 a, uint8x32 b)
    {
        uint8x32 result;
        result.lo = bitwise_xor(a.lo, b.lo);
        result.hi = bitwise_xor(a.hi, b.hi);
        return result;
    }

    // compare

    static inline uint8x32 compare_eq(uint8x32 a, uint8x32 b)
    {
        uint8x32 result;
        result.lo = compare_eq(a.lo, b.lo);
        result.hi = compare_eq(a.hi, b.hi);
        return result;
    }

    static inline uint8x32 compare_gt(uint8x32 a, uint8x32 b)
    {
        uint8x32 result;
        result.lo = compare_gt(a.lo, b.lo);
        result.hi = compare_gt(a.hi, b.hi);
        return result;
    }

    static inline uint8x32 select(uint8x32 mask, uint8x32 a, uint8x32 b)
    {
        uint8x32 result;
        result.lo = select(mask.lo, a.lo, b.lo);
        result.hi = select(mask.hi, a.hi, b.hi);
        return result;
    }

    static inline uint8x32 min(uint8x32 a, uint8x32 b)
    {
        uint8x32 result;
        result.lo = min(a.lo, b.lo);
        result.hi = min(a.hi, b.hi);
        return result;
    }

    static inline uint8x32 max(uint8x32 a, uint8x32 b)
    {
        uint8x32 result;
        result.lo = max(a.lo, b.lo);
        result.hi = max(a.hi, b.hi);
        return result;
    }

    // -----------------------------------------------------------------
    // uint16x16
    // -----------------------------------------------------------------

    template <unsigned int Index>
    static inline uint16x16 set_component(uint16x16 a, uint16 b)
    {
        static_assert(Index < 16, "Index out of range.");
        SET_COMPONENT(a, b, 7, Index);
        return a;
    }

    template <unsigned int Index>
    static inline uint16 get_component(uint16x16 a)
    {
        static_assert(Index < 16, "Index out of range.");
        return GET_COMPONENT(a, 7, Index);
    }

    static inline uint16x16 uint16x16_zero()
    {
        uint16x16 result;
        result.lo = uint16x8_zero();
        result.hi = uint16x8_zero();
        return result;
    }

    static inline uint16x16 uint16x16_set1(uint16 s)
    {
        uint16x16 result;
        result.lo = uint16x8_set1(s);
        result.hi = uint16x8_set1(s);
        return result;
    }

    static inline uint16x16 unpacklo(uint16x16 a, uint16x16 b)
    {
        uint16x16 result;
        result.lo = unpacklo(a.lo, b.lo);
        result.hi = unpacklo(a.hi, b.hi);
        return result;
    }

    static inline uint16x16 unpackhi(uint16x16 a, uint16x16 b)
    {
        uint16x16 result;
        result.lo = unpackhi(a.lo, b.lo);
        result.hi = unpackhi(a.hi, b.hi);
        return result;
    }

    static inline uint16x16 add(uint16x16 a, uint16x16 b)
    {
        uint16x16 result;
        result.lo = add(a.lo, b.lo);
        result.hi = add(a.hi, b.hi);
        return result;
    }

    static inline uint16x16 sub(uint16x16 a, uint16x16 b)
    {
        uint16x16 result;
        result.lo = sub(a.lo, b.lo);
        result.hi = sub(a.hi, b.hi);
        return result;
    }

    static inline uint16x16 mullo(uint16x16 a, uint16x16 b)
    {
        uint16x16 result;
        result.lo = mullo(a.lo, b.lo);
        result.hi = mullo(a.hi, b.hi);
        return result;
    }

    // saturated

    static inline uint16x16 adds(uint16x16 a, uint16x16 b)
    {
        uint16x16 result;
        result.lo = adds(a.lo, b.lo);
        result.hi = adds(a.hi, b.hi);
        return result;
    }

    static inline uint16x16 subs(uint16x16 a, uint16x16 b)
    {
        uint16x16 result;
        result.lo = subs(a.lo, b.lo);
        result.hi = subs(a.hi, b.hi);
        return result;
    }

    // bitwise

    static inline uint16x16 bitwise_nand(uint16x16 a, uint16x16 b)
    {
        uint16x16 result;
        result.lo = bitwise_nand(a.lo, b.lo);
        result.hi = bitwise_nand(a.hi, b.hi);
        return result;
    }

    static inline uint16x16 bitwise_and(uint16x16 a, uint16x16 b)
    {
        uint16x16 result;
        result.lo = bitwise_and(a.lo, b.lo);
        result.hi = bitwise_and(a.hi, b.hi);
        return result;
    }

    static inline uint16x16 bitwise_or(uint16x16 a, uint16x16 b)
    {
        uint16x16 result;
        result.lo = bitwise_or(a.lo, b.lo);
        result.hi = bitwise_or(a.hi, b.hi);
        return result;
    }

    static inline uint16x16 bitwise_xor(uint16x16 a, uint16x16 b)
    {
        uint16x16 result;
        result.lo = bitwise_xor(a.lo, b.lo);
        result.hi = bitwise_xor(a.hi, b.hi);
        return result;
    }

    // compare

    static inline uint16x16 compare_eq(uint16x16 a, uint16x16 b)
    {
        uint16x16 result;
        result.lo = compare_eq(a.lo, b.lo);
        result.hi = compare_eq(a.hi, b.hi);
        return result;
    }

    static inline uint16x16 compare_gt(uint16x16 a, uint16x16 b)
    {
        uint16x16 result;
        result.lo = compare_gt(a.lo, b.lo);
        result.hi = compare_gt(a.hi, b.hi);
        return result;
    }

    static inline uint16x16 select(uint16x16 mask, uint16x16 a, uint16x16 b)
    {
        uint16x16 result;
        result.lo = select(mask.lo, a.lo, b.lo);
        result.hi = select(mask.hi, a.hi, b.hi);
        return result;
    }

    // shift

    template <int Count>
    static inline uint16x16 slli(uint16x16 a)
    {
        uint16x16 result;
        result.lo = slli<Count>(a.lo);
        result.hi = slli<Count>(a.hi);
        return result;
    }

    template <int Count>
    static inline uint16x16 srli(uint16x16 a)
    {
        uint16x16 result;
        result.lo = srli<Count>(a.lo);
        result.hi = srli<Count>(a.hi);
        return result;
    }

    template <int Count>
    static inline uint16x16 srai(uint16x16 a)
    {
        uint16x16 result;
        result.lo = srai<Count>(a.lo);
        result.hi = srai<Count>(a.hi);
        return result;
    }

    static inline uint16x16 sll(uint16x16 a, int count)
    {
        uint16x16 result;
        result.lo = sll(a.lo, count);
        result.hi = sll(a.hi, count);
        return result;
    }

    static inline uint16x16 srl(uint16x16 a, int count)
    {
        uint16x16 result;
        result.lo = srl(a.lo, count);
        result.hi = srl(a.hi, count);
        return result;
    }

    static inline uint16x16 sra(uint16x16 a, int count)
    {
        uint16x16 result;
        result.lo = sra(a.lo, count);
        result.hi = sra(a.hi, count);
        return result;
    }

    static inline uint16x16 min(uint16x16 a, uint16x16 b)
    {
        uint16x16 result;
        result.lo = min(a.lo, b.lo);
        result.hi = min(a.hi, b.hi);
        return result;
    }

    static inline uint16x16 max(uint16x16 a, uint16x16 b)
    {
        uint16x16 result;
        result.lo = max(a.lo, b.lo);
        result.hi = max(a.hi, b.hi);
        return result;
    }

    // -----------------------------------------------------------------
    // uint32x8
    // -----------------------------------------------------------------

    template <unsigned int Index>
    static inline uint32x8 set_component(uint32x8 a, uint32 b)
    {
        static_assert(Index < 8, "Index out of range.");
        SET_COMPONENT(a, b, 3, Index);
        return a;
    }

    template <unsigned int Index>
    static inline uint32 get_component(uint32x8 a)
    {
        static_assert(Index < 8, "Index out of range.");
        return GET_COMPONENT(a, 3, Index);
    }

    static inline uint32x8 uint32x8_zero()
    {
        uint32x8 result;
        result.lo = uint32x4_zero();
        result.hi = uint32x4_zero();
        return result;
    }

    static inline uint32x8 uint32x8_set1(uint32 s)
    {
        uint32x8 result;
        result.lo = uint32x4_set1(s);
        result.hi = uint32x4_set1(s);
        return result;
    }

    static inline uint32x8 uint32x8_set8(uint32 s0, uint32 s1, uint32 s2, uint32 s3, uint32 s4, uint32 s5, uint32 s6, uint32 s7)
    {
        uint32x8 result;
        result.lo = uint32x4_set4(s0, s1, s2, s3);
        result.hi = uint32x4_set4(s4, s5, s6, s7);
        return result;
    }

    static inline uint32x8 uint32x8_uload(const uint32* source)
    {
        uint32x8 result;
        result.lo = uint32x4_uload(source + 0);
        result.hi = uint32x4_uload(source + 4);
        return result;
    }

    static inline void uint32x8_ustore(uint32* dest, uint32x8 a)
    {
        uint32x4_ustore(dest + 0, a.lo);
        uint32x4_ustore(dest + 4, a.hi);
    }

    static inline uint32x8 unpacklo(uint32x8 a, uint32x8 b)
    {
        uint32x8 result;
        result.lo = unpacklo(a.lo, b.lo);
        result.hi = unpacklo(a.hi, b.hi);
        return result;
    }

    static inline uint32x8 unpackhi(uint32x8 a, uint32x8 b)
    {
        uint32x8 result;
        result.lo = unpackhi(a.lo, b.lo);
        result.hi = unpackhi(a.hi, b.hi);
        return result;
    }

    static inline uint32x8 add(uint32x8 a, uint32x8 b)
    {
        uint32x8 result;
        result.lo = add(a.lo, b.lo);
        result.hi = add(a.hi, b.hi);
        return result;
    }

    static inline uint32x8 sub(uint32x8 a, uint32x8 b)
    {
        uint32x8 result;
        result.lo = sub(a.lo, b.lo);
        result.hi = sub(a.hi, b.hi);
        return result;
    }

    static inline uint32x8 mullo(uint32x8 a, uint32x8 b)
    {
        uint32x8 result;
        result.lo = mullo(a.lo, b.lo);
        result.hi = mullo(a.hi, b.hi);
        return result;
    }

    // saturated

    static inline uint32x8 adds(uint32x8 a, uint32x8 b)
    {
        uint32x8 result;
        result.lo = adds(a.lo, b.lo);
        result.hi = adds(a.hi, b.hi);
        return result;
    }

    static inline uint32x8 subs(uint32x8 a, uint32x8 b)
    {
        uint32x8 result;
        result.lo = subs(a.lo, b.lo);
        result.hi = subs(a.hi, b.hi);
        return result;
    }

    // bitwise

    static inline uint32x8 bitwise_nand(uint32x8 a, uint32x8 b)
    {
        uint32x8 result;
        result.lo = bitwise_nand(a.lo, b.lo);
        result.hi = bitwise_nand(a.hi, b.hi);
        return result;
    }

    static inline uint32x8 bitwise_and(uint32x8 a, uint32x8 b)
    {
        uint32x8 result;
        result.lo = bitwise_and(a.lo, b.lo);
        result.hi = bitwise_and(a.hi, b.hi);
        return result;
    }

    static inline uint32x8 bitwise_or(uint32x8 a, uint32x8 b)
    {
        uint32x8 result;
        result.lo = bitwise_or(a.lo, b.lo);
        result.hi = bitwise_or(a.hi, b.hi);
        return result;
    }

    static inline uint32x8 bitwise_xor(uint32x8 a, uint32x8 b)
    {
        uint32x8 result;
        result.lo = bitwise_xor(a.lo, b.lo);
        result.hi = bitwise_xor(a.hi, b.hi);
        return result;
    }

    // compare

    static inline uint32x8 compare_eq(uint32x8 a, uint32x8 b)
    {
        uint32x8 result;
        result.lo = compare_eq(a.lo, b.lo);
        result.hi = compare_eq(a.hi, b.hi);
        return result;
    }

    static inline uint32x8 compare_gt(uint32x8 a, uint32x8 b)
    {
        uint32x8 result;
        result.lo = compare_gt(a.lo, b.lo);
        result.hi = compare_gt(a.hi, b.hi);
        return result;
    }

    static inline uint32x8 select(uint32x8 mask, uint32x8 a, uint32x8 b)
    {
        uint32x8 result;
        result.lo = select(mask.lo, a.lo, b.lo);
        result.hi = select(mask.hi, a.hi, b.hi);
        return result;
    }

    // shift

    template <int Count>
    static inline uint32x8 slli(uint32x8 a)
    {
        uint32x8 result;
        result.lo = slli<Count>(a.lo);
        result.hi = slli<Count>(a.hi);
        return result;
    }

    template <int Count>
    static inline uint32x8 srli(uint32x8 a)
    {
        uint32x8 result;
        result.lo = srli<Count>(a.lo);
        result.hi = srli<Count>(a.hi);
        return result;
    }

    template <int Count>
    static inline uint32x8 srai(uint32x8 a)
    {
        uint32x8 result;
        result.lo = srai<Count>(a.lo);
        result.hi = srai<Count>(a.hi);
        return result;
    }

    static inline uint32x8 sll(uint32x8 a, int count)
    {
        uint32x8 result;
        result.lo = sll(a.lo, count);
        result.hi = sll(a.hi, count);
        return result;
    }

    static inline uint32x8 srl(uint32x8 a, int count)
    {
        uint32x8 result;
        result.lo = srl(a.lo, count);
        result.hi = srl(a.hi, count);
        return result;
    }

    static inline uint32x8 sra(uint32x8 a, int count)
    {
        uint32x8 result;
        result.lo = sra(a.lo, count);
        result.hi = sra(a.hi, count);
        return result;
    }

    static inline uint32x8 min(uint32x8 a, uint32x8 b)
    {
        uint32x8 result;
        result.lo = min(a.lo, b.lo);
        result.hi = min(a.hi, b.hi);
        return result;
    }

    static inline uint32x8 max(uint32x8 a, uint32x8 b)
    {
        uint32x8 result;
        result.lo = max(a.lo, b.lo);
        result.hi = max(a.hi, b.hi);
        return result;
    }

    // -----------------------------------------------------------------
    // uint64x4
    // -----------------------------------------------------------------

    template <unsigned int Index>
    static inline uint64x4 set_component(uint64x4 a, uint64 b)
    {
        static_assert(Index < 4, "Index out of range.");
        SET_COMPONENT(a, b, 1, Index);
        return a;
    }

    template <unsigned int Index>
    static inline uint64 get_component(uint64x4 a)
    {
        static_assert(Index < 4, "Index out of range.");
        return GET_COMPONENT(a, 1, Index);
    }

    static inline uint64x4 uint64x4_zero()
    {
        uint64x4 result;
        result.lo = uint64x2_zero();
        result.hi = uint64x2_zero();
        return result;
    }

    static inline uint64x4 uint64x4_set1(uint64 s)
    {
        uint64x4 result;
        result.lo = uint64x2_set1(s);
        result.hi = uint64x2_set1(s);
        return result;
    }

    static inline uint64x4 uint64x4_set4(uint64 x, uint64 y, uint64 z, uint64 w)
    {
        uint64x4 result;
        result.lo = uint64x2_set2(x, y);
        result.hi = uint64x2_set2(z, w);
        return result;
    }

    static inline uint64x4 unpacklo(uint64x4 a, uint64x4 b)
    {
        uint64x4 result;
        result.lo = unpacklo(a.lo, b.lo);
        result.hi = unpacklo(a.hi, b.hi);
        return result;
    }

    static inline uint64x4 unpackhi(uint64x4 a, uint64x4 b)
    {
        uint64x4 result;
        result.lo = unpackhi(a.lo, b.lo);
        result.hi = unpackhi(a.hi, b.hi);
        return result;
    }

    static inline uint64x4 add(uint64x4 a, uint64x4 b)
    {
        uint64x4 result;
        result.lo = add(a.lo, b.lo);
        result.hi = add(a.hi, b.hi);
        return result;
    }

    static inline uint64x4 sub(uint64x4 a, uint64x4 b)
    {
        uint64x4 result;
        result.lo = sub(a.lo, b.lo);
        result.hi = sub(a.hi, b.hi);
        return result;
    }

    static inline uint64x4 bitwise_nand(uint64x4 a, uint64x4 b)
    {
        uint64x4 result;
        result.lo = bitwise_nand(a.lo, b.lo);
        result.hi = bitwise_nand(a.hi, b.hi);
        return result;
    }

    static inline uint64x4 bitwise_and(uint64x4 a, uint64x4 b)
    {
        uint64x4 result;
        result.lo = bitwise_and(a.lo, b.lo);
        result.hi = bitwise_and(a.hi, b.hi);
        return result;
    }

    static inline uint64x4 bitwise_or(uint64x4 a, uint64x4 b)
    {
        uint64x4 result;
        result.lo = bitwise_or(a.lo, b.lo);
        result.hi = bitwise_or(a.hi, b.hi);
        return result;
    }

    static inline uint64x4 bitwise_xor(uint64x4 a, uint64x4 b)
    {
        uint64x4 result;
        result.lo = bitwise_xor(a.lo, b.lo);
        result.hi = bitwise_xor(a.hi, b.hi);
        return result;
    }

    static inline uint64x4 select(uint64x4 mask, uint64x4 a, uint64x4 b)
    {
        uint64x4 result;
        result.lo = select(mask.lo, a.lo, b.lo);
        result.hi = select(mask.hi, a.hi, b.hi);
        return result;
    }

    // shift

    template <int Count>
    static inline uint64x4 slli(uint64x4 a)
    {
        uint64x4 result;
        result.lo = slli<Count>(a.lo);
        result.hi = slli<Count>(a.hi);
        return result;
    }

    template <int Count>
    static inline uint64x4 srli(uint64x4 a)
    {
        uint64x4 result;
        result.lo = srli<Count>(a.lo);
        result.hi = srli<Count>(a.hi);
        return result;
    }

    static inline uint64x4 sll(uint64x4 a, int count)
    {
        uint64x4 result;
        result.lo = sll(a.lo, count);
        result.hi = sll(a.hi, count);
        return result;
    }

    static inline uint64x4 srl(uint64x4 a, int count)
    {
        uint64x4 result;
        result.lo = srl(a.lo, count);
        result.hi = srl(a.hi, count);
        return result;
    }

    // -----------------------------------------------------------------
    // int8x32
    // -----------------------------------------------------------------

    template <unsigned int Index>
    static inline int8x32 set_component(int8x32 a, int8 b)
    {
        static_assert(Index < 32, "Index out of range.");
        SET_COMPONENT(a, b, 15, Index);
        return a;
    }

    template <unsigned int Index>
    static inline int8 get_component(int8x32 a)
    {
        static_assert(Index < 32, "Index out of range.");
        return GET_COMPONENT(a, 15, Index);
    }

    static inline int8x32 int8x32_zero()
    {
        int8x32 result;
        result.lo = int8x16_zero();
        result.hi = int8x16_zero();
        return result;
    }

    static inline int8x32 int8x32_set1(int8 s)
    {
        int8x32 result;
        result.lo = int8x16_set1(s);
        result.hi = int8x16_set1(s);
        return result;
    }

    static inline int8x32 unpacklo(int8x32 a, int8x32 b)
    {
        int8x32 result;
        result.lo = unpacklo(a.lo, b.lo);
        result.hi = unpacklo(a.hi, b.hi);
        return result;
    }

    static inline int8x32 unpackhi(int8x32 a, int8x32 b)
    {
        int8x32 result;
        result.lo = unpackhi(a.lo, b.lo);
        result.hi = unpackhi(a.hi, b.hi);
        return result;
    }

    static inline int8x32 add(int8x32 a, int8x32 b)
    {
        int8x32 result;
        result.lo = add(a.lo, b.lo);
        result.hi = add(a.hi, b.hi);
        return result;
    }

    static inline int8x32 sub(int8x32 a, int8x32 b)
    {
        int8x32 result;
        result.lo = sub(a.lo, b.lo);
        result.hi = sub(a.hi, b.hi);
        return result;
    }

    static inline int8x32 mullo(int8x32 a, int8x32 b)
    {
        int8x32 result;
        result.lo = mullo(a.lo, b.lo);
        result.hi = mullo(a.hi, b.hi);
        return result;
    }

    // saturated

    static inline int8x32 adds(int8x32 a, int8x32 b)
    {
        int8x32 result;
        result.lo = adds(a.lo, b.lo);
        result.hi = adds(a.hi, b.hi);
        return result;
    }

    static inline int8x32 subs(int8x32 a, int8x32 b)
    {
        int8x32 result;
        result.lo = subs(a.lo, b.lo);
        result.hi = subs(a.hi, b.hi);
        return result;
    }

    static inline int8x32 abs(int8x32 a)
    {
        int8x32 result;
        result.lo = abs(a.lo);
        result.hi = abs(a.hi);
        return result;
    }

    static inline int8x32 neg(int8x32 a)
    {
        int8x32 result;
        result.lo = neg(a.lo);
        result.hi = neg(a.hi);
        return result;
    }

    // bitwise

    static inline int8x32 bitwise_nand(int8x32 a, int8x32 b)
    {
        int8x32 result;
        result.lo = bitwise_nand(a.lo, b.lo);
        result.hi = bitwise_nand(a.hi, b.hi);
        return result;
    }

    static inline int8x32 bitwise_and(int8x32 a, int8x32 b)
    {
        int8x32 result;
        result.lo = bitwise_and(a.lo, b.lo);
        result.hi = bitwise_and(a.hi, b.hi);
        return result;
    }

    static inline int8x32 bitwise_or(int8x32 a, int8x32 b)
    {
        int8x32 result;
        result.lo = bitwise_or(a.lo, b.lo);
        result.hi = bitwise_or(a.hi, b.hi);
        return result;
    }

    static inline int8x32 bitwise_xor(int8x32 a, int8x32 b)
    {
        int8x32 result;
        result.lo = bitwise_xor(a.lo, b.lo);
        result.hi = bitwise_xor(a.hi, b.hi);
        return result;
    }

    // compare

    static inline int8x32 compare_eq(int8x32 a, int8x32 b)
    {
        int8x32 result;
        result.lo = compare_eq(a.lo, b.lo);
        result.hi = compare_eq(a.hi, b.hi);
        return result;
    }

    static inline int8x32 compare_gt(int8x32 a, int8x32 b)
    {
        int8x32 result;
        result.lo = compare_gt(a.lo, b.lo);
        result.hi = compare_gt(a.hi, b.hi);
        return result;
    }

    static inline int8x32 select(int8x32 mask, int8x32 a, int8x32 b)
    {
        int8x32 result;
        result.lo = select(mask.lo, a.lo, b.lo);
        result.hi = select(mask.hi, a.hi, b.hi);
        return result;
    }

    static inline int8x32 min(int8x32 a, int8x32 b)
    {
        int8x32 result;
        result.lo = min(a.lo, b.lo);
        result.hi = min(a.hi, b.hi);
        return result;
    }

    static inline int8x32 max(int8x32 a, int8x32 b)
    {
        int8x32 result;
        result.lo = max(a.lo, b.lo);
        result.hi = max(a.hi, b.hi);
        return result;
    }

    // -----------------------------------------------------------------
    // int16x16
    // -----------------------------------------------------------------

    template <unsigned int Index>
    static inline int16x16 set_component(int16x16 a, int16 b)
    {
        static_assert(Index < 16, "Index out of range.");
        SET_COMPONENT(a, b, 7, Index);
        return a;
    }

    template <unsigned int Index>
    static inline int16 get_component(int16x16 a)
    {
        static_assert(Index < 16, "Index out of range.");
        return GET_COMPONENT(a, 7, Index);
    }

    static inline int16x16 int16x16_zero()
    {
        int16x16 result;
        result.lo = int16x8_zero();
        result.hi = int16x8_zero();
        return result;
    }

    static inline int16x16 int16x16_set1(int16 s)
    {
        int16x16 result;
        result.lo = int16x8_set1(s);
        result.hi = int16x8_set1(s);
        return result;
    }

    static inline int16x16 unpacklo(int16x16 a, int16x16 b)
    {
        int16x16 result;
        result.lo = unpacklo(a.lo, b.lo);
        result.hi = unpacklo(a.hi, b.hi);
        return result;
    }

    static inline int16x16 unpackhi(int16x16 a, int16x16 b)
    {
        int16x16 result;
        result.lo = unpackhi(a.lo, b.lo);
        result.hi = unpackhi(a.hi, b.hi);
        return result;
    }

    static inline int16x16 add(int16x16 a, int16x16 b)
    {
        int16x16 result;
        result.lo = add(a.lo, b.lo);
        result.hi = add(a.hi, b.hi);
        return result;
    }

    static inline int16x16 sub(int16x16 a, int16x16 b)
    {
        int16x16 result;
        result.lo = sub(a.lo, b.lo);
        result.hi = sub(a.hi, b.hi);
        return result;
    }

    static inline int16x16 mullo(int16x16 a, int16x16 b)
    {
        int16x16 result;
        result.lo = mullo(a.lo, b.lo);
        result.hi = mullo(a.hi, b.hi);
        return result;
    }

    // saturated

    static inline int16x16 adds(int16x16 a, int16x16 b)
    {
        int16x16 result;
        result.lo = adds(a.lo, b.lo);
        result.hi = adds(a.hi, b.hi);
        return result;
    }

    static inline int16x16 subs(int16x16 a, int16x16 b)
    {
        int16x16 result;
        result.lo = subs(a.lo, b.lo);
        result.hi = subs(a.hi, b.hi);
        return result;
    }

    static inline int16x16 abs(int16x16 a)
    {
        int16x16 result;
        result.lo = abs(a.lo);
        result.hi = abs(a.hi);
        return result;
    }

    static inline int16x16 neg(int16x16 a)
    {
        int16x16 result;
        result.lo = neg(a.lo);
        result.hi = neg(a.hi);
        return result;
    }

    // bitwise

    static inline int16x16 bitwise_nand(int16x16 a, int16x16 b)
    {
        int16x16 result;
        result.lo = bitwise_nand(a.lo, b.lo);
        result.hi = bitwise_nand(a.hi, b.hi);
        return result;
    }

    static inline int16x16 bitwise_and(int16x16 a, int16x16 b)
    {
        int16x16 result;
        result.lo = bitwise_and(a.lo, b.lo);
        result.hi = bitwise_and(a.hi, b.hi);
        return result;
    }

    static inline int16x16 bitwise_or(int16x16 a, int16x16 b)
    {
        int16x16 result;
        result.lo = bitwise_or(a.lo, b.lo);
        result.hi = bitwise_or(a.hi, b.hi);
        return result;
    }

    static inline int16x16 bitwise_xor(int16x16 a, int16x16 b)
    {
        int16x16 result;
        result.lo = bitwise_xor(a.lo, b.lo);
        result.hi = bitwise_xor(a.hi, b.hi);
        return result;
    }

    // compare

    static inline int16x16 compare_eq(int16x16 a, int16x16 b)
    {
        int16x16 result;
        result.lo = compare_eq(a.lo, b.lo);
        result.hi = compare_eq(a.hi, b.hi);
        return result;
    }

    static inline int16x16 compare_gt(int16x16 a, int16x16 b)
    {
        int16x16 result;
        result.lo = compare_gt(a.lo, b.lo);
        result.hi = compare_gt(a.hi, b.hi);
        return result;
    }

    static inline int16x16 select(int16x16 mask, int16x16 a, int16x16 b)
    {
        int16x16 result;
        result.lo = select(mask.lo, a.lo, b.lo);
        result.hi = select(mask.hi, a.hi, b.hi);
        return result;
    }

    // shift

    template <int Count>
    static inline int16x16 slli(int16x16 a)
    {
        int16x16 result;
        result.lo = slli<Count>(a.lo);
        result.hi = slli<Count>(a.hi);
        return result;
    }

    template <int Count>
    static inline int16x16 srli(int16x16 a)
    {
        int16x16 result;
        result.lo = srli<Count>(a.lo);
        result.hi = srli<Count>(a.hi);
        return result;
    }

    template <int Count>
    static inline int16x16 srai(int16x16 a)
    {
        int16x16 result;
        result.lo = srai<Count>(a.lo);
        result.hi = srai<Count>(a.hi);
        return result;
    }

    static inline int16x16 sll(int16x16 a, int count)
    {
        int16x16 result;
        result.lo = sll(a.lo, count);
        result.hi = sll(a.hi, count);
        return result;
    }

    static inline int16x16 srl(int16x16 a, int count)
    {
        int16x16 result;
        result.lo = srl(a.lo, count);
        result.hi = srl(a.hi, count);
        return result;
    }

    static inline int16x16 sra(int16x16 a, int count)
    {
        int16x16 result;
        result.lo = sra(a.lo, count);
        result.hi = sra(a.hi, count);
        return result;
    }

    static inline int16x16 min(int16x16 a, int16x16 b)
    {
        int16x16 result;
        result.lo = min(a.lo, b.lo);
        result.hi = min(a.hi, b.hi);
        return result;
    }

    static inline int16x16 max(int16x16 a, int16x16 b)
    {
        int16x16 result;
        result.lo = max(a.lo, b.lo);
        result.hi = max(a.hi, b.hi);
        return result;
    }

    // -----------------------------------------------------------------
    // int32x8
    // -----------------------------------------------------------------

    template <unsigned int Index>
    static inline int32x8 set_component(int32x8 a, int32 b)
    {
        static_assert(Index < 8, "Index out of range.");
        SET_COMPONENT(a, b, 3, Index);
        return a;
    }

    template <unsigned int Index>
    static inline int32 get_component(int32x8 a)
    {
        static_assert(Index < 8, "Index out of range.");
        return GET_COMPONENT(a, 3, Index);
    }

    static inline int32x8 int32x8_zero()
    {
        int32x8 result;
        result.lo = int32x4_zero();
        result.hi = int32x4_zero();
        return result;
    }

    static inline int32x8 int32x8_set1(int32 s)
    {
        int32x8 result;
        result.lo = int32x4_set1(s);
        result.hi = int32x4_set1(s);
        return result;
    }

    static inline int32x8 int32x8_set8(int32 s0, int32 s1, int32 s2, int32 s3, int32 s4, int32 s5, int32 s6, int32 s7)
    {
        int32x8 result;
        result.lo = int32x4_set4(s0, s1, s2, s3);
        result.hi = int32x4_set4(s4, s5, s6, s7);
        return result;
    }

    static inline int32x8 int32x8_uload(const int32* source)
    {
        int32x8 result;
        result.lo = int32x4_uload(source + 0);
        result.hi = int32x4_uload(source + 4);
        return result;
    }

    static inline void int32x8_ustore(int32* dest, int32x8 a)
    {
        int32x4_ustore(dest + 0, a.lo);
        int32x4_ustore(dest + 4, a.hi);
    }

    static inline int32x8 unpacklo(int32x8 a, int32x8 b)
    {
        int32x8 result;
        result.lo = unpacklo(a.lo, b.lo);
        result.hi = unpacklo(a.hi, b.hi);
        return result;
    }

    static inline int32x8 unpackhi(int32x8 a, int32x8 b)
    {
        int32x8 result;
        result.lo = unpackhi(a.lo, b.lo);
        result.hi = unpackhi(a.hi, b.hi);
        return result;
    }

    static inline int32x8 abs(int32x8 a)
    {
        int32x8 result;
        result.lo = abs(a.lo);
        result.hi = abs(a.hi);
        return result;
    }

    static inline int32x8 neg(int32x8 a)
    {
        int32x8 result;
        result.lo = neg(a.lo);
        result.hi = neg(a.hi);
        return result;
    }

    static inline int32x8 add(int32x8 a, int32x8 b)
    {
        int32x8 result;
        result.lo = add(a.lo, b.lo);
        result.hi = add(a.hi, b.hi);
        return result;
    }

    static inline int32x8 sub(int32x8 a, int32x8 b)
    {
        int32x8 result;
        result.lo = sub(a.lo, b.lo);
        result.hi = sub(a.hi, b.hi);
        return result;
    }

    static inline int32x8 mullo(int32x8 a, int32x8 b)
    {
        int32x8 result;
        result.lo = mullo(a.lo, b.lo);
        result.hi = mullo(a.hi, b.hi);
        return result;
    }

    // saturated

    static inline int32x8 adds(int32x8 a, int32x8 b)
    {
        int32x8 result;
        result.lo = adds(a.lo, b.lo);
        result.hi = adds(a.hi, b.hi);
        return result;
    }

    static inline int32x8 subs(int32x8 a, int32x8 b)
    {
        int32x8 result;
        result.lo = subs(a.lo, b.lo);
        result.hi = subs(a.hi, b.hi);
        return result;
    }

    // bitwise

    static inline int32x8 bitwise_nand(int32x8 a, int32x8 b)
    {
        int32x8 result;
        result.lo = bitwise_nand(a.lo, b.lo);
        result.hi = bitwise_nand(a.hi, b.hi);
        return result;
    }

    static inline int32x8 bitwise_and(int32x8 a, int32x8 b)
    {
        int32x8 result;
        result.lo = bitwise_and(a.lo, b.lo);
        result.hi = bitwise_and(a.hi, b.hi);
        return result;
    }

    static inline int32x8 bitwise_or(int32x8 a, int32x8 b)
    {
        int32x8 result;
        result.lo = bitwise_or(a.lo, b.lo);
        result.hi = bitwise_or(a.hi, b.hi);
        return result;
    }

    static inline int32x8 bitwise_xor(int32x8 a, int32x8 b)
    {
        int32x8 result;
        result.lo = bitwise_xor(a.lo, b.lo);
        result.hi = bitwise_xor(a.hi, b.hi);
        return result;
    }

    // compare

    static inline int32x8 compare_eq(int32x8 a, int32x8 b)
    {
        int32x8 result;
        result.lo = compare_eq(a.lo, b.lo);
        result.hi = compare_eq(a.hi, b.hi);
        return result;
    }

    static inline int32x8 compare_gt(int32x8 a, int32x8 b)
    {
        int32x8 result;
        result.lo = compare_gt(a.lo, b.lo);
        result.hi = compare_gt(a.hi, b.hi);
        return result;
    }

    static inline int32x8 select(int32x8 mask, int32x8 a, int32x8 b)
    {
        int32x8 result;
        result.lo = select(mask.lo, a.lo, b.lo);
        result.hi = select(mask.hi, a.hi, b.hi);
        return result;
    }

    // shift

    template <int Count>
    static inline int32x8 slli(int32x8 a)
    {
        int32x8 result;
        result.lo = slli<Count>(a.lo);
        result.hi = slli<Count>(a.hi);
        return result;
    }

    template <int Count>
    static inline int32x8 srli(int32x8 a)
    {
        int32x8 result;
        result.lo = srli<Count>(a.lo);
        result.hi = srli<Count>(a.hi);
        return result;
    }

    template <int Count>
    static inline int32x8 srai(int32x8 a)
    {
        int32x8 result;
        result.lo = srai<Count>(a.lo);
        result.hi = srai<Count>(a.hi);
        return result;
    }

    static inline int32x8 sll(int32x8 a, int count)
    {
        int32x8 result;
        result.lo = sll(a.lo, count);
        result.hi = sll(a.hi, count);
        return result;
    }

    static inline int32x8 srl(int32x8 a, int count)
    {
        int32x8 result;
        result.lo = srl(a.lo, count);
        result.hi = srl(a.hi, count);
        return result;
    }

    static inline int32x8 sra(int32x8 a, int count)
    {
        int32x8 result;
        result.lo = sra(a.lo, count);
        result.hi = sra(a.hi, count);
        return result;
    }

    static inline int32x8 min(int32x8 a, int32x8 b)
    {
        int32x8 result;
        result.lo = min(a.lo, b.lo);
        result.hi = min(a.hi, b.hi);
        return result;
    }

    static inline int32x8 max(int32x8 a, int32x8 b)
    {
        int32x8 result;
        result.lo = max(a.lo, b.lo);
        result.hi = max(a.hi, b.hi);
        return result;
    }

    // -----------------------------------------------------------------
    // int64x4
    // -----------------------------------------------------------------

    template <unsigned int Index>
    static inline int64x4 set_component(int64x4 a, int64 b)
    {
        static_assert(Index < 4, "Index out of range.");
        SET_COMPONENT(a, b, 1, Index);
        return a;
    }

    template <unsigned int Index>
    static inline int64 get_component(int64x4 a)
    {
        static_assert(Index < 4, "Index out of range.");
        return GET_COMPONENT(a, 1, Index);
    }

    static inline int64x4 int64x4_zero()
    {
        int64x4 result;
        result.lo = int64x2_zero();
        result.hi = int64x2_zero();
        return result;
    }

    static inline int64x4 int64x4_set1(int64 s)
    {
        int64x4 result;
        result.lo = int64x2_set1(s);
        result.hi = int64x2_set1(s);
        return result;
    }

    static inline int64x4 int64x4_set4(int64 x, int64 y, int64 z, int64 w)
    {
        int64x4 result;
        result.lo = int64x2_set2(x, y);
        result.hi = int64x2_set2(z, w);
        return result;
    }

    static inline int64x4 unpacklo(int64x4 a, int64x4 b)
    {
        int64x4 result;
        result.lo = unpacklo(a.lo, b.lo);
        result.hi = unpacklo(a.hi, b.hi);
        return result;
    }

    static inline int64x4 unpackhi(int64x4 a, int64x4 b)
    {
        int64x4 result;
        result.lo = unpackhi(a.lo, b.lo);
        result.hi = unpackhi(a.hi, b.hi);
        return result;
    }

    static inline int64x4 add(int64x4 a, int64x4 b)
    {
        int64x4 result;
        result.lo = add(a.lo, b.lo);
        result.hi = add(a.hi, b.hi);
        return result;
    }

    static inline int64x4 sub(int64x4 a, int64x4 b)
    {
        int64x4 result;
        result.lo = sub(a.lo, b.lo);
        result.hi = sub(a.hi, b.hi);
        return result;
    }

    static inline int64x4 bitwise_nand(int64x4 a, int64x4 b)
    {
        int64x4 result;
        result.lo = bitwise_nand(a.lo, b.lo);
        result.hi = bitwise_nand(a.hi, b.hi);
        return result;
    }

    static inline int64x4 bitwise_and(int64x4 a, int64x4 b)
    {
        int64x4 result;
        result.lo = bitwise_and(a.lo, b.lo);
        result.hi = bitwise_and(a.hi, b.hi);
        return result;
    }

    static inline int64x4 bitwise_or(int64x4 a, int64x4 b)
    {
        int64x4 result;
        result.lo = bitwise_or(a.lo, b.lo);
        result.hi = bitwise_or(a.hi, b.hi);
        return result;
    }

    static inline int64x4 bitwise_xor(int64x4 a, int64x4 b)
    {
        int64x4 result;
        result.lo = bitwise_xor(a.lo, b.lo);
        result.hi = bitwise_xor(a.hi, b.hi);
        return result;
    }

    static inline int64x4 select(int64x4 mask, int64x4 a, int64x4 b)
    {
        int64x4 result;
        result.lo = select(mask.lo, a.lo, b.lo);
        result.hi = select(mask.hi, a.hi, b.hi);
        return result;
    }

    // shift

    template <int Count>
    static inline int64x4 slli(int64x4 a)
    {
        int64x4 result;
        result.lo = slli<Count>(a.lo);
        result.hi = slli<Count>(a.hi);
        return result;
    }

    template <int Count>
    static inline int64x4 srli(int64x4 a)
    {
        int64x4 result;
        result.lo = srli<Count>(a.lo);
        result.hi = srli<Count>(a.hi);
        return result;
    }

    static inline int64x4 sll(int64x4 a, int count)
    {
        int64x4 result;
        result.lo = sll(a.lo, count);
        result.hi = sll(a.hi, count);
        return result;
    }

    static inline int64x4 srl(int64x4 a, int count)
    {
        int64x4 result;
        result.lo = srl(a.lo, count);
        result.hi = srl(a.hi, count);
        return result;
    }

#undef SET_COMPONENT
#undef GET_COMPONENT

} // namespace simd
} // namespace mango
