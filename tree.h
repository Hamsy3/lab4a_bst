#ifndef tree_h
#define tree_h
#include "input_func.h"
#include <stdlib.h>
typedef struct node {
    struct node *left;
    struct node *right;
    struct node *parent;
    unsigned int key;
    unsigned int data;
}node;
node **search (node *ptr, unsigned int key, int *size);
node **search_max_elem (node *ptr, int *size);
node *form_new_node (unsigned int data, unsigned int key);
node * find_min (node *root);
node *find_next (node *x);
node *search_one (node *ptr, unsigned int key);
void print_tree (node *root, int space);
void start_print_tree (node *root);
void insert(unsigned int data, unsigned key, node *root);
void print_tree_inorder(node* root, unsigned int min, unsigned int max);
void free_table (node *root);
void delete (node *x, node **root);
#endif
