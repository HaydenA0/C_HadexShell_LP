#include "./lib/my_string.h"
#include "abreviations.h"
#include "my_list_string.h"
#include "my_tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    MyStringList *commands = my_strlist_new();
    char literal[] = "echo hello_for_me Iloveyou Forever";
    MyStringList *splited = my_splitter(literal, ' ');
    MyTokenList *tokens = my_tokenize_this(splited, commands);

    for (u16 i = 0; i < tokens->size; i++)
    {
        printf("Token[%d]   : \n", i);
        printf("String      : %s\n", tokens->data[i].string.string_proper);
        printf("type        : %u\n", tokens->data[i].token_type);
        printf("-------------------\n");
    }

    free(splited);
    return EXIT_SUCCESS;
}
