#include <string.h>
#include "logger.h"
#include "extern_functions.h"

void print_manual();
void remove_spaces(char *s);
void remove_comments(char *s);
void split_parameters(const char *s, char *p, char *v);

int main(int argc, char *argv[]) {

    // Parsing command line input //

    if (argc != 2){
        ERROR("Wrong amount of arguments.");
        print_manual();
        return EXIT_FAILURE;
    }
    char *config_file_name = argv[1];

    // Parsing config file //

    FILE *config_file = fopen(config_file_name, "r");

    if (config_file == NULL){
        ERROR("Can't open for read file.");
        print_manual();
        return EXIT_FAILURE;
    }

    const int MAX_BUFFER_LENGTH = 256;
    const int MAX_PARAMETERS = 256;
    char config_line[MAX_BUFFER_LENGTH];

    // 64 kb for each
    char parameters_str[MAX_PARAMETERS][MAX_BUFFER_LENGTH];
    char parameters_values_str[MAX_PARAMETERS][MAX_BUFFER_LENGTH];

    int parameter_index = 0;
    while (fgets(config_line, MAX_BUFFER_LENGTH, config_file)){
        remove_spaces(config_line);
        remove_comments(config_line);
        split_parameters(config_line, parameters_str[parameter_index],parameters_values_str[parameter_index]);

        parameter_index++;
    }

    //double parameters_values[parameter_index];
    //for (int i = 0; i < parameter_index; ++i) {
    //    parameters_values[i] = strtod(parameters_values_str[i], NULL);
    //}

    fclose(config_file);

    INFO("Parsed config file.");
    // Call integrating procedure //

    // Output //

    return EXIT_SUCCESS;
}

void print_manual() {
    ERROR("Not implemented");
}

// Notice: remove_comments and remove_spaces may be better merge to one function
void remove_spaces(char *s) {
    char c = ' ';
    int writer = 0, reader = 0;

    while (s[reader])
    {
        if (s[reader]!=c)
        {
            s[writer++] = s[reader];
        }

        reader++;
    }

    s[writer]=0;
}

// Effectively hides comments, not removes them
void remove_comments(char *s) {
    char c = '#';
    int reader = 0;

    while (s[reader])
    {
        if (s[reader]==c)
        {
            s[reader] = '\0';
            return;
        }

        reader++;
    }
}

void split_parameters(const char *s, char *p, char *v) {
    char c = '=';
    int reader = 0;

    while (s[reader] != c)
    {
        p[reader] = s[reader];

        reader++;
    }

    while (s[reader])
    {
        v[reader] = s[reader];

        reader++;
    }
}
