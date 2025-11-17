#include "./lib/my_string.h"
#include "abreviations.h"
#include "my_list_string.h"
#include <stdio.h>
#include <stdlib.h>

MyStringList *my_split(const char *literal, const char delim) // assumes perfect literal
{
    if (literal == NULL)
    {
        return NULL;
    }
    int literal_length = my_calculate_string_length(literal);
    MyString string = my_new_string("");
    MyStringList *output_list = my_strlist_new();
    char element;
    for (u8 i = 0; i < literal_length; i++)
    {
        element = literal[i];
        if (element != delim)
        {
            my_append_character(&string, element);
        }
        else
        {
            if (i == literal_length - 1)
            {
                break;
            }
            my_strlist_append(output_list, &string);
            my_destroy_string(&string);
            string = my_new_string("");
        }
    }
    my_strlist_append(output_list, &string);
    my_destroy_string(&string);

    return output_list;
}

int main(void)
{
    char literal[] = "_Hello_world_without_my_baby__something_weirdlol";
    MyStringList *splited = my_split(literal, '_');
    for (u8 i = 0; i < splited->size; i++)
    {
        printf("Liste[%d] = %s\n", i, splited->body[i].string_proper);
    }
    free(splited);
    return EXIT_SUCCESS;
}
