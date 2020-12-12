#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
    int value;
    struct node *next;
} node;

node* create_node(int value);
int push(node* head, node* n);
int pop(node* n);
node* pop_front(node* n);
int insert(node* n, int index, int value);
int contains(node* n, int value);
void display_list(node* n);

#endif