#include <stdlib.h>
#include <stddef.h>
#include "stack.h"
#include "llist.h"

struct stack {
    LinkedList head;
};

Stack s_alloc() {
    Stack s;

    s = malloc(sizeof(struct stack));
    s->head = EMPTY_LL; 

    return s;
}

void s_free(Stack s) {
    free(s);
}

int s_pop(Stack *s) {
    return ll_remove(&(*s)->head);
}

void s_push(Stack *s, int val) {
    ll_insert_before(&(*s)->head, val);
}

int s_empty(const Stack *s) {
    return ll_empty(&(*s)->head);
}
