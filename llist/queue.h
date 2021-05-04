typedef struct queue *Queue;

// Allocates and returns an empty queue
Queue q_alloc();

// Frees the queue (should be empty)
void q_free(Queue q);

// Dequeues and returns a value off of the queue
int q_dequeue(Queue *q);

// Enqueues the given value
void q_enqueue(Queue *q, int val);

// Returns true if the queue is empty
int q_empty(const Queue *q);
