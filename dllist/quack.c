#include <stdio.h>
#include <assert.h>
#include "deque.h"

int main(int argc, char **argv) {
    Deque s, q;
    s = d_alloc();
    assert(s);
    q = d_alloc();
    assert(q);

    for (int i = 0; i < 10; i++) {
        d_push_head(&s, i);
        d_push_tail(&q, i);
    }

    printf("Stack:\n");
    while (!d_empty(&s)) {
        printf("%d\n", d_pop_head(&s));
    }

    printf("\nQueue: \n");
    while (!d_empty(&q)) {
        printf("%d\n", d_pop_head(&q));
    }

    d_free(s);
    d_free(q);
}
