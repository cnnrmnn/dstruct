typedef struct node *DoublyLinkedList;

/* Allocates and returns a doubly-linked list */
DoublyLinkedList dll_alloc();

/* Frees the doubly-linked list */
void dll_free(DoublyLinkedList dll);

/* Returns true if the doubly-linked list is empty */
int dll_empty(const DoublyLinkedList *dll);

/* Returns the previous node */
DoublyLinkedList dll_prev(const DoublyLinkedList *dll);

/* Returns the next node */
DoublyLinkedList dll_next(const DoublyLinkedList *dll);

/* Returns the value of the head node */
int dll_val(const DoublyLinkedList *dll);

/* Inserts a new node before the head node */
void dll_insert_before(DoublyLinkedList *dll, int val);

/* Inserts a new node after the head node */
void dll_insert_after(DoublyLinkedList *dll, int val);

/* Removes the tail node and returns its value */
int dll_remove_before(DoublyLinkedList *dll);

/* Removes the head node and returns its value */
int dll_remove_after(DoublyLinkedList *dll);
