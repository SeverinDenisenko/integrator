//
// Created by Severin on 23.09.2022.
//

#ifndef INTEGRATOR_EXTERN_FUNCTIONS_H
#define INTEGRATOR_EXTERN_FUNCTIONS_H

#include "string_utils.h"

extern double cos_f_(double *value);

extern double sin_f_(double *value);

extern double log_f_(double *value, double *base);

extern double rectangle_(void *function, double *low_lim, double *high_lim, int *steps);

extern double trapezium_(double *value, double *low_lim, double *high_lim, int *steps);

extern double simpson_(double *value, double *low_lim, double *high_lim, int *steps);

struct function
{
    void *pointer;
    char *name;
    char **args;
    int args_amount;
};

typedef struct function function;

struct program
{
    function *func;
    double low_lim;
    double high_lim;
    int steps;
    double args[MAX_PARAMETERS];
};

typedef struct program program;

double run_program(program prog);

function *func_from_string(char *s);

#endif //INTEGRATOR_EXTERN_FUNCTIONS_H
