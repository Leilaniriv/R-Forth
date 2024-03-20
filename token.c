#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "token.h"

#define MAX_TOKEN_LENGTH 100
#define MAX_LINE_LENGTH 1024

void free_token(token_t *token) {
    free(token->text);
    free(token);
}

token_t *get_next_token(FILE *input) {
    token_t *token = malloc(sizeof(token_t));
    if (token == NULL) {
        return NULL;
    }

    token->text = malloc(MAX_TOKEN_LENGTH);
    if (token->text == NULL) {
        free(token);
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, input) == NULL) {
        free(token->text);
        free(token);
        return NULL;
    }

    if (sscanf(line, "%s", token->text) != 1){
        free(token->text);
        free(token);
        return NULL;
    }

    // Determine token type
    if (isdigit(token->text[0])) {
        token->type = NUMBER;
        token->value = atoi(token->text);
    } else if (strcmp(token->text, "+") == 0 || strcmp(token->text, "-") == 0 ||
               strcmp(token->text, "*") == 0 || strcmp(token->text, "/") == 0) {
        token->type = OPERATOR;
    } else if (strcmp(token->text, ":") == 0 || strcmp(token->text, ";") == 0) {
        token->type = SYMBOL;
    }else if (isalpha(token->text[0])){
        if (issupper(token->text[0])){
            token->type = CONSTANT;
        } else{
            token->type = VARIABLE;
        }
    } else {
        token->type = WORD;

    return token;
}
