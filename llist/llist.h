typedef struct node *LinkedList;

//The empty linked list
extern const LinkedList EMPTY_LL;

// Allocates and returns a linked list
LinkedList ll_alloc();

// Frees the given linked list
void ll_free(LinkedList ll);

// Returns true if the given linked list is empty
int ll_empty(const LinkedList *ll);

// Returns the next node in the linked list
LinkedList ll_next(const LinkedList *ll);

// Returns the value of the head node of the linked list
int ll_val(const LinkedList *ll);

// Sets the next node of the linked list to the given linked list
void ll_set_next(LinkedList *ll, LinkedList next);

// Sets the value of the head node of the linked list to the given value
void ll_set_val(LinkedList *ll, int val);
