typedef struct deque *Deque;

/* Allocates and returns a deque */
Deque d_alloc();

/* Frees the deque */
void d_free(Deque d);

/* Pops and returns a value off of the head of the deque */
int d_pop_head(Deque *d);

/* Pops and returns a value off of the tail of the deque */
int d_pop_tail(Deque *d);

/* Pushes a value onto the head of the deque */
void d_push_head(Deque *d, int val);

/* Pushes a value onto the tail of the deque */
void d_push_tail(Deque *d, int val);

/* Returns true if the deque is empty */
int d_empty(const Deque *d);
