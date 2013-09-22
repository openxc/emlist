#ifndef _EMLIST_H_
#define _EMLIST_H_

#ifdef __cplusplus
extern "C" {
#endif

struct LinkedListElement {
   void* value;
   LinkedListElement* next;
};

/* Public: A singly linked list of void pointers.
 */
struct LinkedList {
   LinkedListElement* head;
};

/* Public: Allocate and initialize a new, empty LinkedList.
 *
 * This allocates memory for the list, so make sure to call
 * emlist_destroy(LinkedList*) when you're done.
 *
 * Returns a pointer to a new LinkedList.
 */
LinkedList* emlist_create();

/* Public: Free all memory associated with the list and its elements.
 */
void emlist_destroy(LinkedList* list);

/* Public: Initialize a LinkedList that has already been allocated, either
 * in static or dynamic memory.
 *
 * If the list has already been initialized and has elements, this will leak
 * memory.
 *
 * list - the list the initialize.
 */
void emlist_initialize(LinkedList* list);

/* Public: Check if the list contains a value.
 *
 * This function is O(n).
 *
 * Returns true if the value is in the list.
 */
bool emlist_contains(LinkedList* list, void* value);

/* Public: Insert a value into the list.
 *
 * This function is O(n).
 *
 * Returns true if the value was inserted successfully. Returns false if memory
 * could not be allocated for the new element.
 */
bool emlist_insert(LinkedList* list, void* value);

/* Public: Remove a value from the list, if it is in the list.
 *
 * This function is O(n).
 *
 * Returns true if the value was found in the list and succesfully removed.
 * Returns false if the value was not in the list.
 */
bool emlist_remove(LinkedList* list, void* value);

/* Public: Remove all elements from the list.
 *
 * This function is O(n).
 */
void emlist_clear(LinkedList* list);

/* Public: Determine the total size of the list.
 *
 * This function is O(n).
 *
 * Returns the number of elements in the list.
 */
int emlist_size(LinkedList* list);

/* Public: Check if the list is empty.
 *
 * This function is O(1).
 *
 * Returns true if the list is empty.
 */
bool emlist_is_empty(LinkedList* list);

#ifdef __cplusplus
}
#endif

#endif // _EMLIST_H_
