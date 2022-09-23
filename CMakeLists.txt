cmake_minimum_required(VERSION 3.22)
project(integrator C Fortran)

set(CMAKE_C_STANDARD 11)

add_definitions(-DDEBUG_BUILD=1)

add_executable(integrator
        main.c
        logger.c logger.h
        extern_functions.h
        Fortran/cos_f.f90 Fortran/sin_f.f90 Fortran/log_f.f90
        Fortran/rectangle.f90 Fortran/trapezium.f90 Fortran/simpson.f90)
