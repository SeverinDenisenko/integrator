//
// Created by Severin on 23.09.2022.
//

#include "string_utils.h"

// Notice: remove_comments and remove_spaces may be better merge to one function
void remove_spaces(char *s)
{
    char c = ' ';
    int writer = 0, reader = 0;

    while (s[reader])
    {
        if (s[reader] != c)
        {
            s[writer++] = s[reader];
        }

        reader++;
    }

    s[writer] = 0;
}

// Effectively hides comments, not removes them
void remove_comments(char *s)
{
    char c = '#';
    int reader = 0;

    while (s[reader])
    {
        if (s[reader] == c)
        {
            s[reader] = '\0';
            return;
        }

        reader++;
    }
}

void split_parameters(const char *s, char *p, char *v)
{
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

int is_in_parameters(char (*arr)[256], char *s)
{
    //TODO
    return 0;
}

int index_in_parameters(char (*arr)[256], char *s)
{
    //TODO
    return 0;
}

