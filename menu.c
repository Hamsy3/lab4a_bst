#include "menu.h"
#include "input_func.h"
#include "tree.h"
int choice_action() {
    int choice_action = 0;
    printf("Please, choose action\n");
    printf ("0. Exit\n");
    printf ("1. Insert element\n");
    printf ("2. Delete element\n");
    printf ("3. Search element\n");
    printf ("4. Print tree\n");
    printf ("5. Search max element\n");
    printf ("6. Traversal\n");
    scanf ("%d", &choice_action);
    return choice_action;
}
int menu_action() {
    int choice = 0;
    choice = choice_action();
    if (choice<0 || choice>6) {
      do {
          choice = choice_action();
      } while (choice<0 || choice>6);
  }
  return choice;
}
int menu() {
    int choice = 0;
    unsigned int key = 0;
    unsigned int data = 0;
    node *root = NULL;
    do {
    choice = menu_action();
    switch (choice) {
        case 0:
            break;
        case 1: {
            printf("Please, write a key\n");
            input_unsigned_int(&key);
            printf("Please, write a data\n");
            input_unsigned_int(&data);
            if (root == NULL) {
                root = form_new_node(data, key);
            } else {
                insert(data, key, root);
            }
            
            break;
        }
        case 2:
            printf("Please, write a key\n");
            input_unsigned_int(&key);
            node *x = search_one(root, key);
            if (x == NULL) {
                printf("Element not found\n");
            } else {
                delete(x, &root);
            }
            break;
        case 3: {
            printf("Please, write a key\n");
            input_unsigned_int(&key);
            int size = 0;
            node **searched = NULL;
            searched = search(root, key, &size);
            if (searched == NULL) {
                printf("Element not found\n");
            } else {
                for (int i = 0; i <size; ++i) {
                    printf("%u(%u) ", searched[i]->key, searched[i]->data);
                }
            }
            free(searched);
            printf("\n");
            break;
        }
        case 4:
            if (root == NULL) {
                printf("Tree is empty");
            } else {
                start_print_tree(root);
            }
            printf("\n");
            break;
        case 5: {
            int size = 0;
            node **max = search_max_elem(root, &size);
            if (max == NULL) {
                printf("Tree is empty\n");
            } else {
                
                for (int i = 0; i < size; ++i) {
                    printf("%u(%u) ", max[i]->key, max[i]->data);
                }
                printf("\n");

            }
            free(max);
            break;
        }
        case 6:
            printf("Please write min element\n");
            unsigned int min, max;
            input_unsigned_int(&min);
            printf("Please write max element\n");
            input_unsigned_int(&max);
            print_tree_inorder(root, min, max);
            printf("\n");
        default:
            break;
    }
    } while (choice != 0);
    free_table(root);
    return 0;
}
