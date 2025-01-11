cmake_minimum_required(VERSION 3.29)
project(mankala)

set(CMAKE_CXX_STANDARD 23)



set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Ofast -flto")
set(CMAKE_CXX_FLAGS "${GCC_COVERAGE_COMPILE_FLAGS}" )


include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-march=native" COMPILER_SUPPORTS_MARCH_NATIVE)
if(COMPILER_SUPPORTS_MARCH_NATIVE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
endif()

CHECK_CXX_COMPILER_FLAG("-mtune=native" COMPILER_SUPPORTS_MTUNE_NATIVE)
if(COMPILER_SUPPORTS_MTUNE_NATIVE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mtune=native")
endif()

add_executable(mankala main.cpp
        BoardState.cpp
        BoardState.h
        AI.h
        AI.cpp
        Mankala.cpp
        Mankala.h
        Helper.h
)
