

#ifndef MY_LIST_STRING_H
#define MY_LIST_STRING_H
#include "abreviations.h"
#include "lib/my_string.h"
typedef struct MyStringList
{
    MyString *body;
    u64 size;
    u64 capacity;

} MyStringList;

typedef enum
{
    MY_STRLIST_OK = 0,
    MY_STRLIST_INVALID_ARG = 1,
    MY_STRLIST_ALLOC_FAIL = 2
} MyStrListResult;

MyStringList *my_strlist_new(void);
MyStrListResult my_strlist_append(MyStringList *list, const MyString *string);
i8 my_strlist_append_literal(MyStringList *list, const char *literal);
u8 my_strlist_is_in(const MyStringList *list, const MyString *string);
#endif
