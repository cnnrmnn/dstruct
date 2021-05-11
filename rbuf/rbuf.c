#include <stdlib.h>
#include "rbuf.h"

struct ringBuffer {
    int *contents; 
    int index;
    int length;
    int size;
};

RingBuffer rb_alloc(int size) {
    RingBuffer rb;

    rb = malloc(sizeof(struct ringBuffer));
    rb->contents = malloc(sizeof(int) * size);
    rb->index = 0;
    rb->length = 0;
    rb->size = size;

    return rb;
}

void rb_free(RingBuffer rb) {
    free(rb->contents);
    free(rb);
}

void rb_write(RingBuffer *rb, int val) {
    (*rb)->contents[((*rb)->index + (*rb)->length++) % (*rb)->size] = val;
}

int rb_read(RingBuffer *rb) {
    int ret;

    ret = (*rb)->contents[(*rb)->index];
    (*rb)->index = ((*rb)->index + 1) % (*rb)->size;
    (*rb)->length--;

    return ret;
}
