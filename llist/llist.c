#include <stdlib.h>
#include <stddef.h>
#include "llist.h"

struct node {
    struct node *next;
    int val;
};

const LinkedList EMPTY_LL = NULL;

LinkedList ll_alloc() {
    LinkedList ll;

    ll = malloc(sizeof(struct node));
    ll->next = EMPTY_LL;

    return ll;
}

void ll_free(LinkedList ll) {
    free(ll);
}

int ll_empty(const LinkedList *ll) {
    return *ll == EMPTY_LL;
}

LinkedList ll_next(const LinkedList *ll) {
    return (*ll)->next;
}

int ll_val(const LinkedList *ll) {
    return (*ll)->val;
}

void ll_set_next(LinkedList *ll, LinkedList next) {
    (*ll)->next = next;
}

void ll_set_val(LinkedList *ll, int val) {
    (*ll)->val = val;
}
