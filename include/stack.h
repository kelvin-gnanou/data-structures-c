#ifndef _DATA_STRUCTURES_STACK_H_
    #define _DATA_STRUCTURES_STACK_H_

    /**
    * @file  : stack.h
    * @brief : prototype of function
    * @author: Kelvin A.GNANOU
    * @date  : 2025-11-18 17:40
    */

    #include <stdbool.h>
    #include <stddef.h>

    typedef struct Stack Stack;

    /** *@TODO: Commenter les APIs */
    Stack *stack_create(void);
    void stack_destroy(Stack **stack);
    bool stack_is_empty(const Stack *stack);
    size_t stack_length(const Stack *stack);
    bool stack_push(Stack *stack, int value);
    bool stack_pop(Stack *stack, int *out_value);
    void stack_clear(Stack *stack);
    void stack_print(const Stack *stack);

#endif /* _DATA_STRUCTURES_STACK_H_ */
