typedef struct stack *Stack;

// Allocates and returns an empty stack
Stack s_alloc();

// Frees the stack (should be empty)
void s_free(Stack s);

// Pops and returns a value off of the stack
int s_pop(Stack *s);

// Pushes the given value onto the stack
void s_push(Stack *s, int val);

// Returns true if the given stack is empty
int s_empty(const Stack *s);
