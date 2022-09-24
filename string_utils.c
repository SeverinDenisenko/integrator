//
// Created by Severin on 23.09.2022.
//

#include "string_utils.h"

// Notice: remove_comments and remove_spaces may be better merge to one function
void remove_spaces(char s[MAX_BUFFER_LENGTH])
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
void remove_comments(char s[MAX_BUFFER_LENGTH])
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

void split_parameters(const char s[MAX_BUFFER_LENGTH], char p[MAX_BUFFER_LENGTH], char v[MAX_BUFFER_LENGTH])
{
    char c = '=';
    int reader = 0;

    while (s[reader] != c)
    {
        p[reader] = s[reader];

        reader++;
    }

    reader++;

    int writer = 0;
    while (s[reader])
    {
        v[writer] = s[reader];

        writer++;
        reader++;
    }
}

int is_in_parameters(char arr[MAX_PARAMETERS][MAX_BUFFER_LENGTH], char *s)
{
    for (int i = 0; i < MAX_BUFFER_LENGTH; ++i)
    {
        if(strcmp(s, arr[i]) == 0){
            return 1;
        }
    }

    return 0;
}

int index_in_parameters(char arr[MAX_PARAMETERS][MAX_BUFFER_LENGTH], char *s)
{
    int i = 0;

    while (strcmp(s, arr[i]) != 0){

        i++;
    }

    return i;
}

