//
// Created by Severin on 23.09.2022.
//

#include "extern_functions.h"

#define FUNCTIONS_AMOUNT 3
#define METHODS_AMOUNT 3

extern double cos_f_(double *value);

extern double sin_f_(double *value);

extern double log_f_(double *value);

extern double rectangle_(double (*function)(double *value), double *low_lim, double *high_lim, int *steps);

extern double trapezium_(double (*function)(double *value), double *low_lim, double *high_lim, int *steps);

extern double simpson_(double (*function)(double *value), double *low_lim, double *high_lim, int *steps);

function functions[FUNCTIONS_AMOUNT] = {{sin_f_, "sin"},
                         {cos_f_, "cos"},
                         {log_f_, "log"}};

method methods[METHODS_AMOUNT] = {{rectangle_, "rectangle"},
                     {trapezium_, "trapezium"},
                     {simpson_,   "simpson"}};

double run_program(program *prog)
{
    return prog->meth->pointer(prog->func->pointer, &prog->low_lim, &prog->high_lim, &prog->steps);
}

function *function_from_string(char s[MAX_BUFFER_LENGTH])
{
    for (int i = 0; i < FUNCTIONS_AMOUNT; ++i)
    {
        if (strcmp(functions[i].name, s) == 0){
            return &functions[i];
        }
    }

    FATAL("Can't find required function.");
    return NULL;
}

method *method_from_string(char s[MAX_BUFFER_LENGTH])
{
    for (int i = 0; i < METHODS_AMOUNT; ++i)
    {
        if (strcmp(methods[i].name, s) == 0){
            return &methods[i];
        }
    }

    FATAL("Can't find required method.");
    return NULL;
}
