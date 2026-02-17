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


