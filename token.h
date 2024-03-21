#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    NUMBER,
    OPERATOR,
    SYMBOL,
    WORD,
    VARIABLE,
    CONSTANT,
    BOOLEAN_EX
} token_type_t;

// Define structure for a token
typedef struct {
    token_type_t type;
    char *text;
    int value;
} token_t;

// Function prototypes
token_t *get_next_token(FILE *input);
void free_token(token_t *token);

#endif // TOKEN_H
