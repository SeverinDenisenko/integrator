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

double run_program(program prog)
{
    return prog.meth->pointer(prog.func->pointer, &prog.low_lim, &prog.high_lim, &prog.steps);
}

function *func_from_string(char s[MAX_BUFFER_LENGTH])
{
    //TODO error handling
    int i = 0;

    while (strcmp(functions[i].name, s) != 0){

        i++;
    }

    return &functions[i];
}

method *method_from_string(char s[MAX_BUFFER_LENGTH])
{
    //TODO error handling
    int i = 0;

    while (strcmp(methods[i].name, s) != 0){

        i++;
    }

    return &methods[i];
}

