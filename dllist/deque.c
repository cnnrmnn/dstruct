#include <stdlib.h>
#include "dllist.h"
#include "deque.h"

struct deque {
    DoublyLinkedList dll;
};

Deque d_alloc() {
    Deque d;

    d = malloc(sizeof(struct deque));
    d->dll = dll_alloc();

    return d;
}

void d_free(Deque d) {
    free(d);
}

int d_pop_head(Deque *d) {
    return dll_remove_after(&(*d)->dll);
}

int d_pop_tail(Deque *d) {
    return dll_remove_before(&(*d)->dll);
}

void d_push_head(Deque *d, int val) {
    dll_insert_after(&(*d)->dll, val);
}

void d_push_tail(Deque *d, int val) {
    dll_insert_before(&(*d)->dll, val);
}

int d_empty(const Deque *d) {
    return dll_empty(&(*d)->dll);
}
