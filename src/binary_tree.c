/**
 * @file   : tree.c
 * @brief  : tree implemante
 * @author : Kelvin GNANOU

 * @date  : 2026/04/22 19:37
 * @note  :
 * @todo  :
 */

#include "../include/binary_tree.h"

#include <stdio.h>
#include <stdlib.h>

/* Internal struct */
struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* lifecycle */
static void destroy_nodes(BinaryTree node) {
    if (!node) return;

    destroy_nodes(node->left);
    destroy_nodes(node->right);

    free(node);
}


static size_t node_count(const BinaryTree node) {
    return (!node)
        ? 0 
        : 1 + node_count(node->left) + node_count(node->right);
}


static size_t node_height(const BinaryTree node) {
    if (!node) return 0;

    size_t left = node_height(node->left);
    size_t right = node_height(node->right);

    return 1 + (left > right ? left : right);
}

/* traversal */
static void inorder(const BinaryTree node) {
    if (!node) return;

    inorder(node->left);
    printf("%d ", node->value);
    inorder(node->right);
}

BinaryTree tree_create(void) { 
    return NULL; 
}

void tree_destroy(BinaryTree *root) {
    if (!root) return;

    destroy_nodes(*root);
    *root = NULL;
}


bool tree_insert(BinaryTree *root, int value) {
    if (!root) return false;

    while (*root != NULL) {
        if (value == (*root)->value) return true;
        root = (value < (*root)->value) 
            ? &(*root)->left 
            : &(*root)->right;
    }

    *root = malloc(sizeof(**root));

    if (!(*root)) return false;

    (*root)->value = value;
    (*root)->left = NULL;
    (*root)->right = NULL;

    return true;
}

bool tree_contains(const BinaryTree root, int value) {
    const struct TreeNode *node = root;
    while (node) {
        if (value == node->value) return true;
        node = value < node->value
            ? node->left
            : node->right;
    }
    return false;
}

/* utils */
size_t tree_size(const BinaryTree root) { 
    return node_count(root); 
}

size_t tree_height(const BinaryTree root) { 
    return node_height(root); 
}

void tree_print_inorder(const BinaryTree root) {
    inorder(root);
    putchar('\n');
}
