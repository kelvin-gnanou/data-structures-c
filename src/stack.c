/**
*@file : stack.c
*@brief: stack implementation
*/

#include "../include/stack.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int value;
    struct StackNode *next;
} StackNode;

struct Stack {
    StackNode *top;
    size_t length;
};

Stack *stack_create(void) { 
    return calloc(1, sizeof(Stack)); 
}

bool stack_is_empty(const Stack *stack) { 
    return stack == NULL || stack->length == 0; 
}


size_t stack_length(const Stack *stack) { 
    return !stack ? 0 : stack->length; 
}


bool stack_push(Stack *stack, int value) {
    if (!stack) return false;

    StackNode *node = malloc(sizeof(*node));
    if (!node) 
        return false;

    node->value = value;
    node->next = stack->top;
    stack->top = node;
    stack->length++;

    return true;
}

bool stack_pop(Stack *stack, int *out_value) {
    if (stack_is_empty(stack))  
        return false;

    StackNode *node = stack->top;
    if (out_value) 
        *out_value = node->value;

    stack->top = node->next;
    stack->length--;

    free(node);
    return true;
}

void stack_clear(Stack *stack) {
    if (!stack) return;
    int ignored = 0;
    while (stack_pop(stack, &ignored)) {
    }
}

void stack_destroy(Stack **stack) {
    if (stack == NULL || *stack == NULL) return;

    stack_clear(*stack);

    free(*stack);
    *stack = NULL;
}

void stack_print(const Stack *stack) {
    putchar('[');
    if (stack != NULL) {
        for (
            const StackNode *node = stack->top; 
            node != NULL; 
            node = node->next
        ){
            printf("%d%s", node->value, node->next == NULL ? "" : ", ");
        }
    }
    puts("]");
}
