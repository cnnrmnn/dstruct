#include <stdio.h>
#include <assert.h>
#include "stack.h"
#include "queue.h"

int main(int argc, char **argv) {
    Stack s = s_alloc();
    assert(s);
    Queue q = q_alloc();
    assert(q);

    for (int i = 0; i < 10; i++) {
        s_push(&s, i);
        q_enqueue(&q, i);
    }

    printf("Stack:\n");
    while (!s_empty(&s)) {
        printf("%d\n", s_pop(&s));
    }

    printf("\nQueue: \n");
    while (!q_empty(&q)) {
        printf("%d\n", q_dequeue(&q));
    }

    s_free(s);
    q_free(q);
}
