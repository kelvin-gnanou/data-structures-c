#ifndef _DATA_STRUCTURES_BINARY_TREE_H_
    #define _DATA_STRUCTURES_BINARY_TREE_H_

    #include <stdbool.h>
    #include <stddef.h>

    /* Internal struct */
    typedef struct TreeNode *BinaryTree;

    /* Lyfe cycle */
    BinaryTree tree_create(void);
    void tree_destroy(BinaryTree *root);

    /* Traversal */
    bool tree_insert(BinaryTree *root, int value);
    bool tree_contains(const BinaryTree root, int value);
    size_t tree_size(const BinaryTree root);
    size_t tree_height(const BinaryTree root);
    void tree_print_inorder(const BinaryTree root);

#endif /* _DATA_STRUCTURES_BINARY_TREE_H_ */
