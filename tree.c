#include "tree.h"
node **search (node *ptr, unsigned int key, int *size) {
    node **search = calloc(1, sizeof(node*));
    *size = 0;
    int flag = 0;
    while (ptr != NULL) {
        if (key == ptr->key) {
            flag = 1;
            *size = *size +1;
            search =(node**)realloc(search, (*size) * sizeof(node*));
            search[(*size)-1] = ptr;
        }
        if (key >= ptr->key) {
            ptr=ptr->right;
        } else {
            ptr=ptr->left;
        }
    }
    
    if (flag == 0) {
        return NULL;
    }
    return search;
}

node **search_max_elem (node *ptr, int *size) {
    node **max = calloc(1, sizeof(node*));
    if (ptr == NULL) {
        return 0;
    }
    while (ptr->right != NULL) {
        ptr = ptr->right;
    }
    unsigned int tmp = ptr->key;
    max[0] = ptr;
    ptr = ptr -> parent;
    *size = 1;
    for (int i = 1; (ptr != NULL)&&(ptr->key == tmp); ++i) {
        max = (node**) realloc(max, (i+1) * sizeof(node*));
        max[i] = ptr;
        ptr = ptr->parent;
        *size = i+1;
    }
    return max;
}
node *form_new_node (unsigned int data, unsigned int key) {
    node *node = (struct node*) calloc(1, sizeof(struct node));
    node->key = key;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}
void print_tree (node *root, int space) {
    if (root == NULL) {
        return;
    }
    space = space + 10;
    print_tree(root->right, space);
    printf("\n\n");
    for (int i = 10; i < space; ++i) {
        printf(" ");
    }
    printf("|%u(%u)|", root->key, root->data);
    print_tree(root->left, space);
}
void start_print_tree (node *root) {
    print_tree(root, 0);
}

void print_tree_inorder(node* root, unsigned int min, unsigned int max){
    if(root != NULL){
        print_tree_inorder(root->left, min, max);
        if ((root->key < min) || (root->key > max)) {
            printf("%d ", root->key);
        }
        print_tree_inorder(root->right, min, max);
    }
}
void insert(unsigned int data, unsigned key, node *root)
{
    if (key < root->key)
    {
        if (root->left != NULL)
        {
            insert(data, key, root->left);
        }
        else
        {
            root->left = form_new_node(data, key);
            root->left->parent = root;
        }
    }
    else if (key >= root->key)
    {
        if (root->right != NULL)
        {
            insert(data, key, root->right);
        }
        else
        {
            root->right = form_new_node(data, key);
            root->right->parent = root;
        }
    }
}
void free_table (node *root) {
    if (root != NULL) {
        free_table(root->left);
        free_table(root->right);
        free(root);
    }
}
node * find_min (node *root) {
    node *ptr = root;
    while (ptr->left != NULL) {
        ptr = ptr->left;
    }
    return ptr;
}
node *find_next (node *x) {
    node *ptr;
    if (x->right != NULL) {
        ptr = find_min(x->right);
        return ptr;
    }
    ptr = x->parent;
    while ((ptr != NULL) && (x == ptr->right)) {
        x = ptr;
        ptr = x->parent;
    }
    return ptr;
}
void delete (node *x, node **root) {
    node *real_deleted = NULL;
    node *tmp = NULL;
    if ((x->left == NULL) || (x->right == NULL)) {
        real_deleted = x;
    } else {
        real_deleted = find_next(x);
    }
    if (real_deleted->left != NULL) {
        tmp = real_deleted->left;
    } else {
        tmp = real_deleted->right;
    }
    if (tmp !=NULL) {
        tmp->parent = real_deleted->parent;
    }
    if (real_deleted->parent == NULL) {
        *root = tmp;
    } else {
        if (real_deleted->parent->left == real_deleted) {
            real_deleted->parent->left = tmp;
        } else{
            real_deleted->parent->right = tmp;
        }
    }
    if (real_deleted != x) {
        x->key = real_deleted->key;
        x->data = real_deleted->data;
    }
    free(real_deleted);
}
node *search_one (node *ptr, unsigned int key) {
    while (ptr != NULL) {
        if (key == ptr->key) {
            return ptr;
        }
        if (key >= ptr->key) {
            ptr=ptr->right;
        } else {
            ptr=ptr->left;
        }
    }
    return NULL;
}
