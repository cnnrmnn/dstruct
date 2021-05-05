#include <stdlib.h>
#include "queue.h"
#include "llist.h"

struct queue {
    LinkedList head;
    LinkedList tail;
};

Queue q_alloc() {
    Queue q;

    q = malloc(sizeof(struct queue));
    q->head = EMPTY_LL;
    q->tail = EMPTY_LL;

    return q;
}

void q_free(Queue q) {
    free(q);
}

int q_dequeue(Queue *q) {
    int ret;

    ret = ll_remove(&(*q)->head);
    if (ll_empty(&(*q)->head))
        (*q)->tail = (*q)->head;

    return ret;
}

void q_enqueue(Queue *q, int val) {
    ll_insert_after(&(*q)->tail, val);

    if (ll_empty(&(*q)->head))
        (*q)->head =  (*q)->tail;
}

int q_empty(const Queue *q) {
    return ll_empty(&(*q)->head) && ll_empty(&(*q)->tail);
}
