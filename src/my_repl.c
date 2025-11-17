#include "./my_repl.h"
#include <stdio.h>

MyString read_line(void)
{
    MyString user_input = my_new_string("");
    char *buffer = NULL;
    size_t buffer_size = 1;
    getline(&buffer, &buffer_size, stdin);
    my_append_literal(&user_input, buffer);
    user_input.string_proper[user_input.size - 1] = '\0';
    user_input.size--;
    return user_input;
}
