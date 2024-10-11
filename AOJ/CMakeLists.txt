cmake_minimum_required(VERSION 3.26)

project(aoj)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")

add_executable(ITP1_7_B ITP1_7_B.cpp)
add_executable(ALDS1_5_A ALDS1_5_A.cpp)
add_executable(ALDS1_13_A ALDS1_13_A.cpp)
add_executable(ALDS1_4_B ALDS1_4_B.cpp)
add_executable(ALDS1_11_B ALDS1_11_B.cpp)
add_executable(1160 1160.cpp)
