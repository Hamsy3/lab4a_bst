#include "input_func.h"
#include <stdlib.h>
int input_unsigned_int (unsigned int *num) {
        int a = 0;
    int tmp = 0;
    do {
        a = scanf ("%d", &tmp);
        if (a < 0) {
            return 0;
        }
        
        if (a == 0) {
            scanf("%*c");
        }
    } while (a == 0);
    *num = abs(tmp);
    return 1;
}
