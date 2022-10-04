cmake_minimum_required(VERSION 3.22)
project(integrator C Fortran)

set(CMAKE_CXX_COMPILER g++-11)
add_compile_options(-Wall -Wextra -Wfloat-equal -Wundef -Wcast-align -Wwrite-strings -Wmissing-declarations -Wlogical-op -Wredundant-decls -Woverloaded-virtual -pedantic)
set(CMAKE_C_STANDARD 11)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG_BUILD=1)
endif ()

add_executable(integrator
        main.c
        logger.c logger.h
        extern_functions.c extern_functions.h
        Fortran/cos_f.f90 Fortran/sin_f.f90 Fortran/log_f.f90
        Fortran/rectangle.f90 Fortran/trapezium.f90 Fortran/simpson.f90 string_utils.c string_utils.h)
