/**
 * @file: test_list.c
 * @brief: test linked list implementation
 * @author: GNANOU Kelvin
 * @date: 02-11-2026
 * @note:
 * @TODO:
 */

#include <assert.h>   // assert
#include <stddef.h>   // NULL
#include <stdio.h>    // fputs, stdout

#include "../include/list.h"

#define ASSERT_TRUE(x) assert(x)

void test_list(void){
    List *list = list_create();
    ASSERT_TRUE(list != NULL && "ERROR: list creation failed !");
    ASSERT_TRUE(list_is_empty(list) && "ERROR: new list is not empty !");

    ASSERT_TRUE(list_push_back(list, 1) && "ERROR: fail to append 1 !");
    ASSERT_TRUE(list_push_back(list, 2) && "ERROR: fail to append 2 !");
    ASSERT_TRUE(list_length(list) == 2 && "ERROR: list size is not 2 !");
    ASSERT_TRUE(list_remove_first(list, 1) && "ERROR: fail to remove first 1 !");
    ASSERT_TRUE(list_length(list) == 1 && "ERROR: list size is not 1 !");
    ASSERT_TRUE(list_push_front(list, 2) && "ERROR: fail to prepend 2 !");
    ASSERT_TRUE(list_remove_last(list, 2) && "ERROR: fail to remove last 2 !");

    int value = 0;
    ASSERT_TRUE(
        list_pop_back(list, &value) && value == 2
        && "ERROR: pop back returned a wrong value !"
    );
    ASSERT_TRUE(list_is_empty(list) && "ERROR: list should be empty !");
    ASSERT_TRUE(!list_pop_front(list, NULL) && "ERROR: pop from empty list succeeded !");

    list_destroy(&list);
    ASSERT_TRUE(list == NULL && "ERROR: list was not destroyed !");

    fputs("func: void test_list(void) end succefully ...\n", stdout);
}
