/**
 * @file: test_main.c
 * @brief: main function of tests
 * @author: GNANOU Kelvin
 * @date: 02-11-2026
 * @note:
 * @TODO:
 */

#include <stdio.h>  // puts

/* prototypes of test functions */
void test_binary_tree(void);
void test_graph(void);
void test_list(void);
void test_queue(void);
void test_stack(void);

int main(void){
    puts("\nBEGINNING OF TESTS ...\n");

    test_binary_tree();
    test_graph();
    test_list();
    test_queue();
    test_stack();

    puts("\nALL TEST IS OK ...\n");
    return 0;
}
