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
    dll->prev = EMPTY_DLL;
    dll->next = EMPTY_DLL;

    return dll;
}

void dll_free(DoublyLinkedList dll) {
    free(dll);
}

int dll_empty(const DoublyLinkedList *dll) {
   return *dll == EMPTY_DLL; 
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

    if (!dll_empty(dll)) {
        if (!dll_empty(&(*dll)->prev))
            new_node->prev = (*dll)->prev;
        (*dll)->prev = new_node;
    }

    *dll = new_node;
}

void dll_insert_after(DoublyLinkedList *dll, int val) {
    DoublyLinkedList new_node;

    new_node = dll_alloc();
    new_node->val = val;
    new_node->prev = *dll;

    if (!dll_empty(dll)) {
        if (!dll_empty(&(*dll)->next))
            new_node->next = (*dll)->next;
        (*dll)->next = new_node;
    }

    *dll = new_node;
}

int dll_remove(DoublyLinkedList *dll) {
    DoublyLinkedList head;
    int ret;

    head = *dll;
    ret = head->val;

    if (!dll_empty(&head->next)) {
        head->next->prev = head->prev;
    }
    if (!dll_empty(&head->prev)) {
        head->prev->next = head->next;
    }

    if (dll_empty(&head->next) && !dll_empty(&head->prev)) {
        *dll = head->prev;
    } else {
        *dll = head->next;
    }

    dll_free(head);

    return ret;
}
