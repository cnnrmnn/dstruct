typedef struct ringBuffer *RingBuffer;

/* Allocates and returns a ring buffer of the given size */
RingBuffer rb_alloc(int size);

/* Frees the ring buffer */
void rb_free(RingBuffer rb);

/* Writes to the ring buffer */
void rb_write(RingBuffer *rb, int val);

/* Reads from the ring buffer */
int rb_read(RingBuffer *rb);
