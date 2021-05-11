#include <stdlib.h>
#include <stddef.h>
#include "dllist.h" 

struct node {
    struct node *prev;
    struct node *next;
    int val;
};

const DoublyLinkedList EMPTY_DLL = NULL;

DoublyLinkedList dll_alloc() {
    DoublyLinkedList dll;

    dll = malloc(sizeof(struct node));
    dll->prev = dll->next = dll;

    return dll;
}

void dll_free(DoublyLinkedList dll) {
    free(dll);
}

int dll_empty(const DoublyLinkedList *dll) {
    return (*dll)->next == *dll;
}

DoublyLinkedList dll_prev(const DoublyLinkedList *dll) {
    return (*dll)->prev;
}

DoublyLinkedList dll_next(const DoublyLinkedList *dll) {
    return (*dll)->next;
}

int dll_val(const DoublyLinkedList *dll) {
    return (*dll)->val;
}

void dll_insert_before(DoublyLinkedList *dll, int val) {
    DoublyLinkedList new_node;

    new_node = dll_alloc();
    new_node->val = val;
    new_node->next = *dll;
    new_node->prev = (*dll)->prev;
    new_node->prev->next = new_node;

    (*dll)->prev = new_node;
}

void dll_insert_after(DoublyLinkedList *dll, int val) {
    DoublyLinkedList new_node;

    new_node = dll_alloc();
    new_node->val = val;
    new_node->prev = *dll;
    new_node->next = (*dll)->next;
    new_node->next->prev = new_node;

    (*dll)->next = new_node;
}


int dll_remove_before(DoublyLinkedList *dll) {
    DoublyLinkedList prev;
    int ret;

    prev = (*dll)->prev;

    ret = prev->val;
    prev->next->prev = prev->prev;
    prev->prev->next = prev->next;

    dll_free(prev);

    return ret;
}

int dll_remove_after(DoublyLinkedList *dll) {
    DoublyLinkedList next;
    int ret;

    next = (*dll)->next;

    ret = next->val;
    next->next->prev = next->prev;
    next->prev->next = next->next;

    dll_free(next);

    return ret;
}
