cmake_minimum_required(VERSION 3.10)
project(CVM_PlusPlus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Professional compiler flags for a high-quality build
# -Wall and -Wextra enforce strict code quality
# -O3 optimizes the final Virtual Machine for maximum speed
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -O3")

# Add all source files dynamically
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(cvm ${SOURCES})
