#include <string.h>
#include <stdlib.h>
#include "logger.h"
#include "string_utils.h"
#include "extern_functions.h"

int main(int argc, char *argv[])
{

    // Parsing command line input //

    if (argc != 2)
    {
        FATAL("Wrong amount of arguments.");
    }
    char *config_file_name = argv[1];

    // Parsing config file //

    FILE *config_file = fopen(config_file_name, "r");

    if (config_file == NULL)
    {
        FATAL("Can't open for read file.");
    }

    char config_line[MAX_BUFFER_LENGTH];

    // 64 kb for each
    char parameters_str[MAX_PARAMETERS][MAX_BUFFER_LENGTH];
    char parameters_values_str[MAX_PARAMETERS][MAX_BUFFER_LENGTH];

    int parameter_index = 0;
    while (fgets(config_line, MAX_BUFFER_LENGTH, config_file))
    {
        remove_spaces(config_line);
        remove_comments(config_line);
        split_parameters(config_line, parameters_str[parameter_index], parameters_values_str[parameter_index]);

        parameter_index++;
    }

    fclose(config_file);

    INFO("Parsed config file.");

    // Find required arguments in configs //

    char *method_s = "method";
    if (!is_in_parameters(parameters_str, method_s))
    {
        FATAL("Can't find integration method in config file.");
    }
    int method_s_index = index_in_parameters(parameters_str, method_s);
    function *method = func_from_string(parameters_values_str[method_s_index]);

    char *function_s = "function";
    if (!is_in_parameters(parameters_str, function_s))
    {
        FATAL("Can't find function name to integrate in config file.");
    }
    int function_s_index = index_in_parameters(parameters_str, function_s);
    function *func = func_from_string(parameters_values_str[function_s_index]);

    char *low_lim_s = "low_lim";
    if (!is_in_parameters(parameters_str, low_lim_s))
    {
        FATAL("Can't find lower integration limit in config file.");
    }
    int low_lim_s_index = index_in_parameters(parameters_str, low_lim_s);
    double low_lim = strtod(parameters_values_str[low_lim_s_index], NULL);

    char *high_lim_s = "high_lim";
    if (!is_in_parameters(parameters_str, high_lim_s))
    {
        FATAL("Can't find high integration limit in config file.");
    }
    int high_lim_s_index = index_in_parameters(parameters_str, high_lim_s);
    double high_lim = strtod(parameters_values_str[high_lim_s_index], NULL);

    char *steps_s = "steps";
    if (!is_in_parameters(parameters_str, steps_s))
    {
        FATAL("Can't find number of steps in config file.");
    }
    int steps_s_index = index_in_parameters(parameters_str, steps_s);
    int steps = strtol(parameters_values_str[steps_s_index], NULL, 10);

    double custom_args[MAX_PARAMETERS];
    if (func->args_amount != 0)
    {
        for (int i = 0; i < func->args_amount; ++i)
        {
            if (!is_in_parameters(parameters_str, func->args[i])){
                FATAL("Can't find all the function arguments.");
            }
            int arg_index = index_in_parameters(parameters_str, func->args[i]);
            custom_args[i] = strtod(parameters_values_str[arg_index], NULL);
        }
    }

    INFO("Get all needed arguments.");

    // Asemble program and run //

    program prog;
    prog.func = func;
    prog.low_lim = low_lim;
    prog.high_lim = high_lim;
    for (int i = 0; i < func->args_amount; ++i)
    {
        prog.args[i] = custom_args[i];
    }
    prog.steps = steps;

    double res = run_program(prog);

    // Output //

    printf("%f\n", res);

    return EXIT_SUCCESS;
}
