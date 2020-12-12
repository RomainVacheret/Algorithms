#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

typedef struct heap {
    int *arr;
    int size;
    int capacity;
} heap;


heap* create_heap(int size);
int parent(int i);
int left_child(int i);
int right_child(int i);
int is_leaf(int i, int size);
int has_right_child(int i, int size);
int is_full(heap* h);
int is_empty(heap* h);
int insert(heap *h, int key);
int delete_max(heap* h);

#endif