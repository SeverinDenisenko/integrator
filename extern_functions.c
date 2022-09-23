//
// Created by Severin on 23.09.2022.
//

#include "extern_functions.h"

const function functions[3] = {{sin_f_, "sin"},
                               {cos_f_, "cos"},
                               {log_f_, "log", (char **) "base", 1}};

const function integrators[3] = {{rectangle_, "rectangle"},
                                 {trapezium_, "trapezium"},
                                 {simpson_,   "simpson"}};

double run_program(program prog)
{
    //TODO
    return 0;
}

function *func_from_string(char *s)
{
    //TODO
    function *result;
    return result;
}
