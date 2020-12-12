#include <stdio.h>
#include <stdlib.h>
#include "../../utils.h"
#include "binary_heap.h"

heap* create_heap(int size) {
    heap* h = (heap*) malloc(sizeof(heap));
    h->capacity = 0;
    h->size = size;
    h->arr = (int*) malloc(sizeof(int) * size);
    return h;
}

int parent(int i) { return i ? (i - 1) / 2 : 0; }
int left_child(int i) { return 2 * i + 1; }
int right_child(int i) { return 2 * i + 2; }
int is_leaf(int i, int size) { return i < size && left_child(i) > size; }
int has_right_child(int i, int size) {right_child(i) < size; }
int is_full(heap* h) { return h->size == h->capacity; }
int is_empty(heap* h) { h->capacity == 0; }

int insert(heap *h, int key) {
    if(is_full(h)) {
        return -1;
    }

    int i = h->capacity++, p = parent(i);
    h->arr[i] = key;

    while(h->arr[p] < h->arr[i]) {
        swap(&h->arr[p], &h->arr[i]);
        i = p;
        p = parent(i);
    }
    
    return i;
}

int delete_max(heap* h) {
    int i = 0;
    h->arr[i] = h->arr[--h->capacity];

    while(!is_leaf(i, h->capacity)) {
        int l = left_child(i);
        int r = right_child(i);
        int *m = h->arr[l] > h->arr[r] || !has_right_child(i, h->capacity) ? &l : &r;

        if(*m < h->capacity && h->arr[i] < h->arr[*m]) {
            swap(&h->arr[i], &h->arr[*m]);
            i = *m;
        } else {
            break;
        }
    }

    return i;
}

heap* heap_from_array(int *arr, int length, int heap_size) {
    if(heap_size < length) {
        return NULL;
    }

    int i;
    heap* h = create_heap(heap_size);
    for(i = 0; i < length; i++) {
        insert(h, arr[i]);
    }

    return h;
}

void sort_with_heap(int* arr, int* arr2, int length) {
    int i;
    heap* h = heap_from_array(arr, length, length);

    for(i = 0; i < length; i++) {
        arr2[i] = h->arr[0];
        delete_max(h);
    }
}

int main() {
    int arr[] = { 53, 41, 30, 36, 28, 21, 6, 31, 16, 20 };
    heap* h = heap_from_array(arr, 10, 11);
    printf("-- Insertion --\n");
    printf("Inital state of the heap:\n");
    dis_int_arr(h->arr, h->capacity);
    insert(h, 50);
    printf("State after inserting 50:\n");
    dis_int_arr(h->arr, h->capacity);
    printf("Expected state:\n");
    printf("53 50 30 36 41 21 6 31 16 20 28\n");

    h = heap_from_array(arr, 10, 10);
    printf("\n\n-- Maximum deletion --\n");
    printf("Inital state of the heap:\n");
    dis_int_arr(h->arr, h->capacity);
    delete_max(h);
    printf("State after deleting the maximum (53):\n");
    dis_int_arr(h->arr, h->capacity);
    printf("Expected state:\n");
    printf("41 36 30 31 28 21 6 20 16\n");

    int arr2[10];
    printf("\n\n-- Heap sort --\n");
    printf("Inital state of the array:\n");
    dis_int_arr(arr, 10);
    sort_with_heap(arr, arr2, 10);
    printf("State after sort:\n");
    dis_int_arr(arr2, 10);
    printf("Expected state:\n");
    printf("53 41 36 31 30 28 21 20 16 6\n");
    
    return EXIT_SUCCESS;
}