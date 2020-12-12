#ifndef STACK_H
#define STACK_H

typedef struct stack_arr {
    int* arr;
    int size;
    int capacity;
    int top;
} stack_arr;

stack_arr* create_stack_arr(int size);
int is_full(stack_arr* s);
int is_empty(stack_arr* s);
int push(stack_arr* s, int value);
int pop(stack_arr* s);

#endif