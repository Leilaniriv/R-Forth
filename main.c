//#include <stdio.h>
#include "token.h"

int main() {
    token_t *token;

    printf("Enter R-FORTH program:\n");

    while (1) {
        // Create a buffer to hold user input
        char input_buffer[100];

        // Read user input
        if (scanf("%s", input_buffer) == EOF || strcmp(input_buffer, "exit") == 0) {
            break; // Exit loop if EOF or 'exit' command
        }

        // Open a stream on the input buffer
        FILE *input_stream = fmemopen(input_buffer, strlen(input_buffer), "r");

        // Get next token
        token = get_next_token(input_stream);

        // Close the stream
        fclose(input_stream);

        if (token != NULL) {
            switch (token->type) {
                case NUMBER:
                    printf("Number: %s\n", token->text);
                    break;
                case OPERATOR:
                    printf("Operator: %s\n", token->text);
                    break;
                case SYMBOL:
                    printf("Symbol: %s\n", token->text);
                    break;
                case WORD:
                    printf("Word: %s\n", token->text);
                    break;
                default:
                    printf("Unknown token type\n");
                    break;
            }
            free_token(token);
        }
    }

    return 0;
}
