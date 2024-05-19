#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

Node* create_node(int val, int hash) {
    Node* node;

    if ((node = malloc(sizeof(Node))) == NULL) {
        printf("Failed to allocate memory for node\n");
        exit(1);
    }

    node->val = val;
    node->hash = hash;
    node->right = node->left = NULL;
    return node;
}

void free_node(Node* node) {
    if (node == NULL) return;

    free_node(node->left);
    free_node(node->right);
    free(node);
}

void init_tree(Tree* tree) {
    tree->counter = 0;
    tree->root = NULL;
}

int find(Tree* tree, int val) {
    Node* current = tree->root;

    while (current != NULL) {
        if (current->val == val) {
            return current->hash;
        } else if (current->val > val) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return -1;
}

int insert(Tree* tree, int val) {
    Node* current = tree->root;

    if (current == NULL) {
        tree->root = create_node(val, tree->counter++);
        return tree->root->hash;
    }

    while (1) {
        if (current->val > val) {
            if (current->left == NULL) {
                current->left = create_node(val, tree->counter++);
                return current->left->hash;
            } else {
                current = current->left;
            }
        } else {
            if (current->right == NULL) {
                current->right = create_node(val, tree->counter++);
                return current->right->hash;
            } else {
                current = current->right;
            }
        }
    }
}

int get_hash(Tree* tree, int val) {
    int hash;
    if ((hash = find(tree, val)) == -1) hash = insert(tree, val);
    return hash;
}
