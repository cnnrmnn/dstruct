#include <stdlib.h>
#include <stddef.h>
#include "dllist.h" 

#define DIR_PREV (0)
#define DIR_NEXT (1)

struct node {
    struct node *next[2];
    int val;
};

DoublyLinkedList dll_alloc() {
    DoublyLinkedList dll;

    dll = malloc(sizeof(struct node));
    dll->next[DIR_PREV] = dll->next[DIR_NEXT] = dll;

    return dll;
}

void dll_free(DoublyLinkedList dll) {
    free(dll);
}

int dll_empty(const DoublyLinkedList *dll) {
    return (*dll)->next[DIR_PREV] == *dll;
}

DoublyLinkedList dll_prev(const DoublyLinkedList *dll) {
    return (*dll)->next[DIR_PREV];
}

DoublyLinkedList dll_next(const DoublyLinkedList *dll) {
    return (*dll)->next[DIR_NEXT];
}

int dll_val(const DoublyLinkedList *dll) {
    return (*dll)->val;
}

static void dll_insert(DoublyLinkedList *dll, int val, int dir) {
    DoublyLinkedList new_node;

    new_node = dll_alloc();
    new_node->val = val;
    new_node->next[!dir] = *dll;
    new_node->next[dir]= (*dll)->next[dir];
    new_node->next[dir]->next[!dir] = new_node;

    (*dll)->next[dir] = new_node;
}

void dll_insert_before(DoublyLinkedList *dll, int val) {
    dll_insert(dll, val, DIR_PREV);
}

void dll_insert_after(DoublyLinkedList *dll, int val) {
    dll_insert(dll, val, DIR_NEXT);
}

static int dll_remove(DoublyLinkedList *dll, int dir) {
    DoublyLinkedList rem;
    int ret;

    rem = (*dll)->next[dir];

    ret = rem->val;
    rem->next[!dir]->next[dir] = rem->next[dir];
    rem->next[dir]->next[!dir] = rem->next[!dir];

    dll_free(rem);

    return ret;
}

int dll_remove_before(DoublyLinkedList *dll) {
    return dll_remove(dll, DIR_PREV);
}

int dll_remove_after(DoublyLinkedList *dll) {
    return dll_remove(dll, DIR_NEXT);
}
