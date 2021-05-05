typedef struct node *LinkedList;

/* The empty linked list */
extern const LinkedList EMPTY_LL;

/* Allocates and returns a linked list */
LinkedList ll_alloc();

/* Frees the linked list */
void ll_free(LinkedList ll);

/* Returns true if the linked list is empty */
int ll_empty(const LinkedList *ll);

/* Returns the next node */
LinkedList ll_next(const LinkedList *ll);

/* Returns the value of the head node */
int ll_val(const LinkedList *ll);

/* Inserts a new node before the head node */
void ll_insert_before(LinkedList *ll, int val);

/* Inserts a new node after the head node */
void ll_insert_after(LinkedList *ll, int val);

/* Removes the head node and returns its value */
int ll_remove(LinkedList *ll);
