/**
 * @file: test_queue.c
 * @brief: test queue implementation
 * @author: GNANOU Kelvin
 * @date: 02-11-2026
 * @note:
 * @TODO:
 */

#include <assert.h>   // assert
#include <stddef.h>   // NULL
#include <stdio.h>    // fputs, stdout

#include "../include/queue.h"

#define ASSERT_TRUE(x) assert(x)

void test_queue(void){
    Queue *queue = queue_create();
    Queue *second = queue_create();
    ASSERT_TRUE(queue != NULL && second != NULL && "ERROR: queue creation failed !");

    ASSERT_TRUE(queue_enqueue(queue, 10) && "ERROR: fail to enqueue 10 !");
    ASSERT_TRUE(queue_enqueue(queue, 20) && "ERROR: fail to enqueue 20 !");
    ASSERT_TRUE(queue_enqueue(second, 7) && "ERROR: fail to enqueue 7 in second queue !");
    ASSERT_TRUE(queue_length(queue) == 2 && "ERROR: queue size is not 2 !");
    ASSERT_TRUE(queue_length(second) == 1 && "ERROR: second queue size is not 1 !");

    int value = 0;
    ASSERT_TRUE(queue_dequeue(queue, &value) && value == 10 && "ERROR: queue order is incorrect !");
    ASSERT_TRUE(queue_dequeue(queue, &value) && value == 20 && "ERROR: queue order is incorrect !");
    ASSERT_TRUE(!queue_dequeue(queue, NULL) && "ERROR: dequeue from empty queue succeeded !");

    queue_destroy(&queue);
    queue_destroy(&second);
    ASSERT_TRUE(queue == NULL && second == NULL && "ERROR: queue was not destroyed !");

    fputs("func: void test_queue(void) end succefully ...\n", stdout);
}
