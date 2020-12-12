#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void dis_int_arr(int *arr, int length) {
    int i;
    for(i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}