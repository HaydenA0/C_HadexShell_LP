#include "./my_list_string.h"
#include "lib/my_string.h"
#include <stdlib.h>

// DEEP COPYING IN APPENDING

MyStringList *my_strlist_new(void)
{
    MyStringList *list = malloc(sizeof(MyStringList));
    list->size = 0;
    list->capacity = 0;
    list->body = NULL;
    return list;
}

MyStrListResult my_strlist_append(MyStringList *list, const MyString *string)
{
    if (list == NULL || string == NULL)
        return MY_STRLIST_INVALID_ARG;

    if (list->size >= list->capacity)
    {
        u64 new_capacity = (list->capacity == 0 ? 1 : list->capacity * 2);

        MyString *new_body = realloc(list->body, new_capacity * sizeof(MyString));
        if (!new_body)
            return MY_STRLIST_ALLOC_FAIL;

        list->body = new_body;
        list->capacity = new_capacity;
    }

    list->body[list->size] = my_copy_string(string);
    list->size++;

    return MY_STRLIST_OK;
}

i8 my_strlist_append_literal(MyStringList *list, const char *literal)
{
    if (literal == NULL)
    {
        return MY_STRLIST_INVALID_ARG;
    }

    MyString string = my_new_string(literal);
    my_strlist_append(list, &string);
    my_destroy_string(&string);

    return MY_STRLIST_OK;
}

u8 my_strlist_is_in(const MyStringList *list, const MyString *string)
{
    if (list == NULL || string == NULL)
        return 0;

    for (u64 i = 0; i < list->size; i++)
    {
        if (my_compare_strings(&list->body[i], string))
        {
            return 1;
        }
    }

    return 0;
}
