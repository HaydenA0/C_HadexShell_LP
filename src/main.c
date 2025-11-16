
#include "./lib/my_string.h"
#include <stdio.h>

int main(void)
{
    MyString *string = my_new_string_reff("Something I guess");
    my_append_literal(string, "\nThis should be in the lower bottom\n");
    printf("%s", string->string_proper);
    return 0;
}
