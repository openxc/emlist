#ifndef _EMLIST_H_
#define _EMLIST_H_

#ifdef __cplusplus
extern "C" {
#endif

struct LinkedListElement {
   void* value;
   LinkedListElement* next;
};

struct LinkedList {
   LinkedListElement* head;
};

void emlist_initialize(LinkedList* list);

bool emlist_contains(LinkedList* list, void* value);

void emlist_insert(LinkedList* list, void* value);

bool emlist_remove(LinkedList* list, void* value);

void emlist_clear(LinkedList* list);

int emlist_size(LinkedList* list);

bool emlist_is_empty(LinkedList* list);

#ifdef __cplusplus
}
#endif

#endif // _EMLIST_H_
