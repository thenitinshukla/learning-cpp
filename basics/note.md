#Understanding mdspan

mdspan is a C++ standard library feature (added in C++23) that provides a non-owning, multi-dimensional array view over contiguous memory 
1 
2. Think of it as a way to interpret a flat block of memory as a multi-dimensional structure (like a matrix or tensor) without actually copying or owning that data.

Key Concepts
Non-Owning View: mdspan doesn't manage memory lifetime - it just provides a structured way to access existing memory. This is similar to std::span (for 1D arrays) or std::string_view 

## Four Template Parameters
mdspan has four customization points

 - Element Type (T): The data type being stored
 - Extents: Dimensions - can be static (compile-time) or dynamic (runtime)
 - LayoutPolicy: How data is arranged in memory (row-major, column-major, etc.)
 - AccessorPolicy: How to access the data (atomic operations, restrict pointers, etc.)

## Why Use mdspan?

- Performance Portability: The layout abstraction lets you write one algorithm that works efficiently on different hardware. CPUs prefer row-major layouts for vectorization, while GPUs prefer column-major for memory coalescing
- Zero Overhead: When properly optimized, mdspan has negligible performance cost compared to raw pointer arithmetic
- Interoperability: It serves as a common vocabulary type that different libraries can use without forcing users to adopt specific container types


==========================================
# AOS vs SOA 
========================================
1. AOS

# ==========================================
# AOS vs SOA
# ==========================================

## 1. AOS — Array of Structures

```text
particles:
┌───────────────┐
│ x │ y │ z     │  ← particle 0
├───────────────┤
│ x │ y │ z     │  ← particle 1
├───────────────┤
│ x │ y │ z     │  ← particle 2
└───────────────┘
```
The important difference
AoS:

```bash
Particle 0     Particle 1     Particle 2
[x][y][z]      [x][y][z]      [x][y][z]
```

```basg
x: [x0][x1][x2]
y: [y0][y1][y2]
z: [z0][z1][z2]
```

## A simple rule

| Workload | Usually preferable |
|---|---|
| Process complete objects | **AoS** |
| Process one/few fields across many objects | **SoA** |
| Object-oriented design | **AoS** |
| SIMD/vectorized processing | **SoA** |
| Randomly access individual objects | **AoS** |
| GPU-style data-parallel processing | **SoA often** |


One important caveat
For a serious performance comparison, don't benchmark only one run. Run each test multiple times and take the minimum/median. Also test different access patterns.

The most interesting comparison is:

```bash
             AoS                         SoA

X only:      [X Y Z][X Y Z][X Y Z]      [X][X][X][X][X]
                    ↑
               unwanted Y/Z

X only:      more memory traffic        contiguous X data
```
- With AoS, accessing only X means the CPU loads Y and Z data that may not be needed.
- With SoA, all X values are contiguous, which can improve cache utilization and SIMD/vectorization.
