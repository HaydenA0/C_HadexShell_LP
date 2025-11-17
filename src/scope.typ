
=== The Goal
Create a shell for learning purposes, Especially parsing and tokenizing.\
=== The scope of this projet
This project leverages my library with the following api :
```c
int my_calculate_string_length(const char *string);

MyString my_new_string(const char *string);
MyString *my_new_string_reff(const char *literal);

void my_destroy_string(MyString *string);

MyString my_copy_string(MyString *string_to_copy);
int my_append_literal(MyString *string, char *string_to_append);
int my_append_custom_literal(MyString *string, char *string_to_append, const size_t bytes_to_append);
int my_append_character(MyString *string, char character_to_append);
int my_compare_strings(MyString *string1, MyString *string2);
int my_compare_literals(const char *literal1, const char *literal2);
int my_append_string(MyString *string, MyString *string_to_append);
int my_insert_char(MyString *string, char character, int index);
int my_replace_char(MyString *string, char old_character, char new_character);
int my_reverse_string(MyString *string);
MyString my_int_to_string(int integer);
char my_int_to_digit_char(int single_number);
int my_find_first_occ_character(MyString *string, char character);
int my_find_first_occ_literal(MyString *string, char *character);
MyString my_slicing(MyString *string, int first_index, int last_index);

int my_is_digit(char character);
int my_is_alphabet(char character);
int my_is_upper_case(char character);
int my_is_lower_case(char character);
char my_to_upper(char c);
char my_to_lower(char c);

int my_make_lowercase(MyString *string);
int my_make_uppercase(MyString *string);
int my_count_character(MyString *string, char character);
MyString my_allocate_custom_size(const size_t size, const size_t capacity);

```

It should be noted that I will definitely make it bigger throught this project for obvious reasons.
I dont want to use the stdlib with anything that deals with the string with themselves. This set of conditions
- All functions from the standard library that dont act on a char \* are allowed
For example `printf` will be allowed because it deals with the char \* AND the io\
strcmp will not since it just work on the char \* itself.


=== How to learn 
I want to learn a concept, apply it in a small self contained problem.
Then after learning all concepts I would go back to the main problem.
For example in shell making I we should manage child processus and all
that so I will then work on small processus managment problems then go back. 
#pagebreak()
* Concepts * :
+ Reading man pages
+ Rewrite strtok
+ What a lexer/tokenizer is
+ Grammar & Parsing (Token sequences, Operator precedence, ...)
+ System Calls & Processes ( forking , execute, wait,...)
+ PATH lookup


