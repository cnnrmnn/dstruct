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
    LinkedList head, new_head;
    int ret;

    head = (*q)->head;
    new_head = ll_next(&head);
    ret = ll_val(&head);

    (*q)->head = new_head;
    ll_free(head);

    if (ll_empty(&new_head))
        (*q)->tail = new_head;

    return ret;
}

void q_enqueue(Queue *q, int val) {
    LinkedList tail, new_tail;
    
    tail = (*q)->tail;
    new_tail = ll_alloc();
    ll_set_val(&new_tail, val); 

    if (ll_empty(&tail)) {
        (*q)->head = new_tail;
    } else {
        ll_set_next(&tail, new_tail);
    }
 
    (*q)->tail = new_tail;
}

int q_empty(const Queue *q) {
    return ll_empty(&(*q)->head) && ll_empty(&(*q)->tail);
}
