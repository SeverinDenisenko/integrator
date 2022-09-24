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

    int parameters_count = 0;
    while (fgets(config_line, MAX_BUFFER_LENGTH, config_file))
    {
        remove_spaces(config_line);
        remove_comments(config_line);
        split_parameters(config_line, parameters_str[parameters_count], parameters_values_str[parameters_count]);

        parameters_count++;
    }

    fclose(config_file);

    for (int i = 0; i < parameters_count; ++i)
    {
        if (strcmp(parameters_str[i], "") == 0){
            ERROR("Some of parameters name is empty.");
        }
        if (strcmp(parameters_values_str[i], "") == 0){
            ERROR("Some of parameters values is empty.");
        }
    }

    INFO("Parsed config file.");

    // Find required arguments in configs //

    char *method_s = "method";
    if (!is_in_parameters(parameters_str, method_s))
    {
        FATAL("Can't find integration method in config file.");
    }
    int method_s_index = index_in_parameters(parameters_str, method_s);
    method *meth = method_from_string(parameters_values_str[method_s_index]);

    INFO("Get integration method.");

    char *function_s = "function";
    if (!is_in_parameters(parameters_str, function_s))
    {
        FATAL("Can't find function name to integrate in config file.");
    }
    int function_s_index = index_in_parameters(parameters_str, function_s);
    function *func = function_from_string(parameters_values_str[function_s_index]);

    INFO("Get function.");

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

    INFO("Get limits.");

    char *steps_s = "steps";
    if (!is_in_parameters(parameters_str, steps_s))
    {
        FATAL("Can't find number of steps in config file.");
    }
    int steps_s_index = index_in_parameters(parameters_str, steps_s);
    int steps = strtol(parameters_values_str[steps_s_index], NULL, 10);

    INFO("Get all needed arguments.");

    // Asemble program and run //

    program prog;
    prog.func = func;
    prog.low_lim = low_lim;
    prog.high_lim = high_lim;
    prog.steps = steps;
    prog.meth = meth;

    double res = run_program(&prog);

    INFO("Program ended without an error.");

    // Output //

    printf("%f\n", res);

    return EXIT_SUCCESS;
}
