#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

node* create_node(int value) {
    node* n = (node*) malloc(sizeof(node));
    n->next = NULL;
    n->value = value;
}

int push(node* head, node* n) {
    if(!head) {
        return -1;
    }

    while(head->next) {
        head = head->next;
    }

    head->next = n;
    return 1;
}

int pop(node* n) {
    if(!n || !n->next) {
        return -1;
    }

    while(n->next->next) {
        n = n->next;
    }

    free(n->next);
    n->next = NULL;
    return 1;
}

node* pop_front(node* n) {
    node * new_head = n->next;
    free(n);
    return new_head;
}

int insert(node* n, int index, int value) {
    while(--index && n) {
        n = n-> next;
    }

    if(index) {
        return -1;
    }

    node* next = n->next;
    n->next = create_node(value);
    n->next->next = next;
    return 1;
}

int contains(node* n, int value) {
    while(n) {
        if(n->value == value) {
            return 1;
        }
        n = n-> next;
    }
    return 0;
}

void display_list(node* n) {
    while(n) {
        printf("%d%s", n->value, n->next ? "->" : " ");
        n = n->next;
    }

    printf("\n");
}

int main() {
    node* first = create_node(1);
    node* second = create_node(2);
    node* third = create_node(3);
    node* fourth = create_node(4);

    push(first, second);
    push(first, third);

    printf("Initial state of the linked list:\n");
    display_list(first);
    printf("Push 4:\n");
    push(first, fourth);
    display_list(first);
    printf("Expected: \n1->2->3->4\n");
    printf("Pop: \n");
    pop(first);
    display_list(first);
    printf("Expected: \n1->2->3\n");
    printf("Insert 6 at index 2:\n");
    insert(first, 2, 6);
    display_list(first);
    printf("Expected:\n1->2->6->3\n");
    printf("The list contains 1:\n");
    printf("%d\n", contains(first, 1));
    printf("Expected:\n1\n");
    printf("The list contains 9:\n");
    printf("%d\n", contains(first, 9));
    printf("Expected:\n0\n");
}