#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"

stack_arr* create_stack_arr(int size) {
    stack_arr* s = (stack_arr*) malloc(sizeof(stack_arr));
    s->size = size;
    s->capacity = 0;
    s->top = -1;
    s->arr = (int*) malloc(sizeof(int) * size);
    return s;
}

int is_full(stack_arr* s) { return s->size == s->capacity; }
int is_empty(stack_arr* s) { return s->capacity == 0; }

int push(stack_arr* s, int value) {
    if(is_full(s)) {
        return -1;
    }

    s->top = (s->top + 1) % s->size;
    s->arr[s->top] = value;
    s->capacity++;
    return 1;
}

int pop(stack_arr* s) {
    if(is_empty(s)) {
        return -1;
    }

    s->top = (s->top + s->size - 1) % s->size;
    s->capacity--;
    return s->arr[s->top];
}

void display_stack(stack_arr* s) {
    if(is_empty(s)) {
        printf("The stack is empty.\n");
        return;
    }

    int i;
    for(i = 0; i < s->capacity; i++) {
        int idx = (s->top - i + s->size) % s->size;
        printf("%d%s", s->arr[idx], i + 1 != s->capacity ? "-" : " ");
    }

    printf("\n");
}

int main() {
    stack_arr* s = create_stack_arr(3);
    // push(s, 1);
    // push(s, 1);
    // printf("%d", s->capacity);


    printf("Initial state of the stack:\n");
    display_stack(s);
    printf("Push 1\n");
    push(s, 1);
    display_stack(s);
    printf("Expected state:\n1\n");
    printf("Push 2\n");
    push(s, 2);
    display_stack(s);
    printf("Expected state:\n2-1\n");
    printf("Push 3\n");
    push(s, 3);
    display_stack(s);
    printf("Expected state:\n3-2-1\n");
    printf("Pop\n");
    pop(s);
    display_stack(s);
    printf("Expected state:\n2-1\n");

}