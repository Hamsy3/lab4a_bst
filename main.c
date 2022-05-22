#include <stdio.h>
#include "menu.h"
#include "tree.h"
int main() {
    if (menu() == 1) {
        printf("EOF\n");
        return 1;
    }
    return 0;
}
