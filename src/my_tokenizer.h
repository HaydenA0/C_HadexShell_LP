#ifndef MY_TOKENIZER_H
#define MY_TOKENIZER_H

#include "abreviations.h"
#include "my_list_string.h"

// DEEP COPYING IN APPENDING

typedef enum
{
    BUILTIN_COMMAND = 0,
    UNIX_COMMAND = 1,
    USER_ARGS = 2,
} TOKEN_TYPE;
typedef struct MyToken
{
    MyString string;
    TOKEN_TYPE token_type;

} MyToken;

typedef struct MyTokenList
{
    MyToken *data;
    u16 size;
    u16 capacity;

} MyTokenList;

MyToken *my_tok_new(const MyString *string, const TOKEN_TYPE token_type);
MyStringList *my_splitter(const char *literal, const char delim);
MyTokenList *my_toklist_new(void);
u8 my_toklist_append(MyTokenList *list, const MyToken *token);
MyTokenList *my_tokenize_this(const MyStringList *string_list, const MyStringList *commands);

#endif
