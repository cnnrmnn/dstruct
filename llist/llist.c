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

void ll_insert_before(LinkedList *ll, int val) {
    LinkedList new_node;

    new_node = ll_alloc();
    new_node->val = val;
    new_node->next = *ll;

    *ll = new_node;
}

void ll_insert_after(LinkedList *ll, int val) {
    LinkedList new_node;

    new_node = ll_alloc();
    new_node->val = val;
    if (!ll_empty(ll)) {
        new_node->next = (*ll)->next;
        (*ll)->next = new_node;
    }

    *ll = new_node;
}

int ll_remove(LinkedList *ll) {
    LinkedList head;
    int ret;

    head = *ll;
    ret = head->val;

    *ll = head->next;
    ll_free(head);

    return ret;
}
