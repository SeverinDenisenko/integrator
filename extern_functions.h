//
// Created by Severin on 23.09.2022.
//

#ifndef INTEGRATOR_EXTERN_FUNCTIONS_H
#define INTEGRATOR_EXTERN_FUNCTIONS_H

#include "string_utils.h"
#include "logger.h"

extern double cos_f_(double *value);

extern double sin_f_(double *value);

extern double log_f_(double *value);

extern double rectangle_(double (*function)(double *value), double *low_lim, double *high_lim, int *steps);

extern double trapezium_(double (*function)(double *value), double *low_lim, double *high_lim, int *steps);

extern double simpson_(double (*function)(double *value), double *low_lim, double *high_lim, int *steps);

struct function
{
    double (*pointer)(double *value);
    char name[MAX_BUFFER_LENGTH];
};

typedef struct function function;

struct method
{
    double (*pointer)(double (*function)(double *value), double *low_lim, double *high_lim, int *steps);
    char name[MAX_BUFFER_LENGTH];
};

typedef struct method method;

struct program
{
    function *func;
    method *meth;
    double low_lim;
    double high_lim;
    int steps;
};

function functions[3];
method methods[3];

typedef struct program program;

double run_program(program prog);

function *func_from_string(char s[MAX_BUFFER_LENGTH]);

method *method_from_string(char s[MAX_BUFFER_LENGTH]);

#endif //INTEGRATOR_EXTERN_FUNCTIONS_H
