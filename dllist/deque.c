#include <stdlib.h>
#include "dllist.h"
#include "deque.h"

struct deque {
    DoublyLinkedList head;
    DoublyLinkedList tail;
};

Deque d_alloc() {
    Deque d;

    d = malloc(sizeof(struct deque));
    d->head = EMPTY_DLL;
    d->tail = EMPTY_DLL;

    return d;
}

void d_free(Deque d) {
    free(d);
}

int d_pop_head(Deque *d) {
    int ret;

    ret = dll_remove(&(*d)->head);
    if (dll_empty(&(*d)->head))
        (*d)->tail = (*d)->head;

    return ret;
}

int d_pop_tail(Deque *d) {
    int ret;

    ret = dll_remove(&(*d)->tail);
    if (dll_empty(&(*d)->tail))
        (*d)->head = (*d)->tail;

    return ret;
}

void d_push_head(Deque *d, int val) {
    dll_insert_before(&(*d)->head, val);

    if (dll_empty(&(*d)->tail))
        (*d)->tail = (*d)->head;
}

void d_push_tail(Deque *d, int val) {
    dll_insert_after(&(*d)->tail, val);

    if (dll_empty(&(*d)->head))
        (*d)->head= (*d)->tail;
}

int d_empty(const Deque *d) {
    return dll_empty(&(*d)->head) && dll_empty(&(*d)->tail);
}
