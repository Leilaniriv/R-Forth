#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "token.h"

token_t *get_next_token(FILE *input) {
    token_t *token = malloc(sizeof(token_t));
    if (token == NULL) {
        return NULL;
    }

    if (fscanf(input, "%s", token->text) == EOF) {
        free(token);
        return NULL;
    }

    // Determine token type
    if (isdigit(token->text[0])) {
        token->type = NUMBER;
    } else if (strcmp(token->text, "+") == 0 || strcmp(token->text, "-") == 0 ||
               strcmp(token->text, "*") == 0 || strcmp(token->text, "/") == 0) {
        token->type = OPERATOR;
    } else if (strcmp(token->text, ":") == 0 || strcmp(token->text, ";") == 0) {
        token->type = SYMBOL;
    } else {
        token->type = WORD;
    }

    return token;
}

void free_token(token_t *token) {
    free(token);
}
