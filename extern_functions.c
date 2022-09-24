//
// Created by Severin on 23.09.2022.
//

#include "extern_functions.h"

function functions[3] = {{sin_f_, "sin"},
                         {cos_f_, "cos"},
                         {log_f_, "log"}};

method methods[3] = {{rectangle_, "rectangle"},
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
