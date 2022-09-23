//
// Created by Severin on 23.09.2022.
//

#include "string_utils.h"

// Notice: remove_comments and remove_spaces may be better merge to one function
void remove_spaces(char *s)
{
    //TODO error handling

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
    //TODO error handling

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

int is_in_parameters(char arr[MAX_PARAMETERS][MAX_BUFFER_LENGTH], char *s)
{
    //TODO error handling

    for (int i = 0; i < MAX_BUFFER_LENGTH; ++i)
    {
        if(strcmp(arr[i], s) == 0){
            return 1;
        }
    }

    return 0;
}

int index_in_parameters(char arr[MAX_PARAMETERS][MAX_BUFFER_LENGTH], char *s)
{
    //TODO error handling

    int i = 0;

    while (strcmp(s, arr[i]) != 0){

        i++;
    }

    return i;
}

