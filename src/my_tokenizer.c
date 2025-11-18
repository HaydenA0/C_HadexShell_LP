#include "./my_tokenizer.h"
#include "lib/my_string.h"
#include "my_list_string.h"

MyStringList *my_splitter(const char *literal, const char delim)
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

MyTokenList *my_toklist_new(void)
{
    MyTokenList *list = malloc(sizeof(MyTokenList));
    if (!list)
        return NULL;

    list->size = 0;
    list->capacity = 0;
    list->data = NULL;

    return list;
}

u8 my_toklist_append(MyTokenList *tokens_list, const MyToken *token)
{
    if (tokens_list == NULL || token == NULL)
        return 0;

    if (tokens_list->size >= tokens_list->capacity)
    {
        u16 new_capacity = (tokens_list->capacity == 0 ? 1 : tokens_list->capacity * 2);
        MyToken *new_data = realloc(tokens_list->data, new_capacity * sizeof(MyToken));
        if (!new_data)
            return 0;

        tokens_list->data = new_data;
        tokens_list->capacity = new_capacity;
    }

    tokens_list->data[tokens_list->size].string = my_copy_string(&token->string);
    tokens_list->data[tokens_list->size].token_type = token->token_type;

    tokens_list->size++;
    return 1;
}

MyToken *my_tok_new(const MyString *string, const TOKEN_TYPE token_type)
{
    if (string == NULL)
    {
        return NULL;
    }
    MyToken *token = malloc(sizeof(MyToken));
    token->string = *string; // I have no idea what i am doing lol
    token->token_type = token_type;
    return token;
}
MyTokenList *my_tokenize(const MyStringList *string_list, const MyStringList *commands)
{
    if (string_list == NULL || string_list->size == 0)
    {
        return NULL;
    }
    MyTokenList *tokenized_output = my_toklist_new();
    if (my_strlist_is_in(commands, &string_list->body[0]))
    {
        MyToken *token = my_tok_new(&string_list->body[0], BUILTIN_COMMAND);
        my_toklist_append(tokenized_output, token);
        free(token);
    }
    else
    {
        MyToken *token = my_tok_new(&string_list->body[0], UNIX_COMMAND);
        my_toklist_append(tokenized_output, token);
        free(token);
    }
    for (u16 i = 1; i < string_list->size; i++)
    // everything is a user command for now because the shell is simple as of now
    {
        MyToken *token = my_tok_new(&string_list->body[i], USER_ARGS);
        my_toklist_append(tokenized_output, token);
        free(token);
    }

    return tokenized_output;
}
