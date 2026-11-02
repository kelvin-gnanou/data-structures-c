/**
 * @file: test_stack.c
 * @brief: test stack implementation
 * @author: GNANOU Kelvin
 * @date: 02-11-2026
 * @note:
 * @TODO:
 */

#include <assert.h>   // assert
#include <stddef.h>   // NULL
#include <stdio.h>    // fputs, stdout

#include "../include/stack.h"

#define ASSERT_TRUE(x) assert(x)

void test_stack(void){
    Stack *stack = stack_create();
    ASSERT_TRUE(stack != NULL && "ERROR: stack creation failed !");
    ASSERT_TRUE(stack_is_empty(stack) && "ERROR: new stack is not empty !");

    ASSERT_TRUE(stack_push(stack, 3) && "ERROR: fail to push 3 !");
    ASSERT_TRUE(stack_push(stack, 8) && "ERROR: fail to push 8 !");
    ASSERT_TRUE(stack_length(stack) == 2 && "ERROR: stack size is not 2 !");

    int value = 0;
    ASSERT_TRUE(stack_pop(stack, &value) && value == 8 && "ERROR: stack order is incorrect !");
    ASSERT_TRUE(stack_pop(stack, &value) && value == 3 && "ERROR: stack order is incorrect !");
    ASSERT_TRUE(!stack_pop(stack, NULL) && "ERROR: pop from empty stack succeeded !");

    stack_destroy(&stack);
    ASSERT_TRUE(stack == NULL && "ERROR: stack was not destroyed !");

    fputs("func: void test_stack(void) end succefully ...\n", stdout);
}
