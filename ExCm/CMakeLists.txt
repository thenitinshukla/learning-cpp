cmake_minimum_required(VERSION 3.10)

project(test)

# Set compiler-specific options
if(CMAKE_C_COMPILER_ID MATCHES "GNU")
    # For GCC
    message(STATUS "Using GCC")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -fopenmp")  # Add GCC specific flags
elseif(CMAKE_C_COMPILER_ID MATCHES "Clang")
    # For Clang
    message(STATUS "Using Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Weverything -fopenmp")   # Add Clang specific flags
elseif(CMAKE_C_COMPILER_ID MATCHES "NVHPC")
    # For NVHPC
    message(STATUS "Using NVHPC")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -acc")  # Add NVHPC specific flags for OpenACC
else()
    message(FATAL_ERROR "Unsupported compiler")
endif()




# Add all your source files
add_executable(
	${PROJECT_NAME}
	src/main.c
   	src/funcall.c
)

# Include directories containing header files
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    # Add more include directories if necessary
)



