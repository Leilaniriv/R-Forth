#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "int_stack.h"

int main() {
    int_stack_t myStack;
    const int capacity = 5;

    // Initialize the stack with a capacity of 5.
    int_stack_init(&myStack, capacity);

    // Push values onto the stack.
    for (int i = 0; i < capacity; i++) {
        int success = int_stack_push(&myStack, i);
        if (!success) {
            fprintf(stderr, "Stack overflow: %d\n", i);
        }
    }

    // Print the stack (top to bottom)
    int_stack_print(&myStack, stdout);

    // Pop values from the stack and print them.
    for (int i = 0; i < capacity; i++) {
        int top_value;
        int success = int_stack_pop(&myStack, &top_value);
        if (!success) {
            fprintf(stderr, "Stack empty\n");
        }
    }

    // Print the stack (top to bottom)
    int_stack_print(&myStack, stdout);

    // Quick tests for swap, dup, and add.

    int_stack_push(&myStack, 7);
    int_stack_push(&myStack, 8);
    int_stack_print(&myStack, stdout);
    int_stack_swap(&myStack);
    int_stack_print(&myStack, stdout);
    int_stack_add(&myStack);
    int_stack_print(&myStack, stdout); 
    int_stack_dup(&myStack);
    int_stack_print(&myStack, stdout); 
    int_stack_add(&myStack);
    int_stack_print(&myStack, stdout); 


    token_t *token;

    printf("Enter R-FORTH program:\n");

    while (1) {
        // Create a buffer to hold user input
        char input_buffer[100];

        // Read user input
        if (scanf("%s", input_buffer) == EOF || strcmp(input_buffer, "exit") == 0) {
            break; //Exit loop if EOF or 'exit' command
        }

        // Open a stream on the input buffer
        FILE *input_stream = fmemopen(input_buffer, strlen(input_buffer), "r");
        if (input_stream == NULL) {
            fprintf(stderr, "Error\n");
            return 1;
        }

        // Get next token
        token = get_next_token(input_stream);
        if (token == NULL) {
            fprintf(stderr, "Error\n");
            fclose(input_stream);
            return 1;
        }

        // Close the stream
        fclose(input_stream);

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

    return 0;
}
