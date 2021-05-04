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
    LinkedList head, new_head;
    int ret;
    
    head = (*s)->head;
    new_head = ll_next(&head);
    ret = ll_val(&head);
    
    (*s)->head = new_head;
    ll_free(head);

    return ret;
}

void s_push(Stack *s, int val) {
    LinkedList head, new_head;

    head = (*s)->head;

    new_head = ll_alloc();
    ll_set_val(&new_head, val);
    ll_set_next(&new_head, head);

    (*s)->head = new_head;
}

int s_empty(const Stack *s) {
    return ll_empty(&(*s)->head);
}
