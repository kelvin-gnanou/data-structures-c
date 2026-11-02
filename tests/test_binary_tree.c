/**
 * @file: test_binary_tree.c
 * @brief: test binary tree implementation
 * @author: GNANOU Kelvin
 * @date: 02-11-2026
 * @note:
 * @TODO:
 */

#include <assert.h>   // assert
#include <stddef.h>   // NULL
#include <stdio.h>    // fputs, stdout

#include "../include/binary_tree.h"

#define ASSERT_TRUE(x) assert(x)

void test_binary_tree(void){
    BinaryTree tree = tree_create();

    ASSERT_TRUE(tree_size(tree) == 0 && "ERROR: new tree is not empty !");
    ASSERT_TRUE(tree_height(tree) == 0 && "ERROR: new tree height is not 0 !");
    ASSERT_TRUE(tree_insert(&tree, 5) && "ERROR: fail to insert 5 !");
    ASSERT_TRUE(tree_insert(&tree, 2) && "ERROR: fail to insert 2 !");
    ASSERT_TRUE(tree_insert(&tree, 8) && "ERROR: fail to insert 8 !");
    ASSERT_TRUE(tree_insert(&tree, 2) && "ERROR: duplicate insert failed !");
    ASSERT_TRUE(tree_size(tree) == 3 && "ERROR: tree size is not 3 !");
    ASSERT_TRUE(tree_height(tree) == 2 && "ERROR: tree height is not 2 !");
    ASSERT_TRUE(tree_contains(tree, 8) && "ERROR: value 8 is missing !");
    ASSERT_TRUE(!tree_contains(tree, 7) && "ERROR: value 7 should be missing !");

    tree_destroy(&tree);
    ASSERT_TRUE(tree == NULL && "ERROR: tree was not destroyed !");

    fputs("func: void test_binary_tree(void) end succefully ...\n", stdout);
}
