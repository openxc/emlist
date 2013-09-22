#include "emlist.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

// TODO would a static array backed implementation be useful, too?

void emlist_initialize(LinkedList* list) {
    list->head = NULL;
}

bool emlist_contains(LinkedList* list, void* value) {
    LinkedListElement* candidate = list->head;
    while(candidate != NULL) {
        if(candidate->value == value) {
            return true;
        }
        candidate = candidate->next;
    }
    return false;
}

void emlist_insert(LinkedList* list, void* value) {
    LinkedListElement* element = (LinkedListElement*) malloc(
            sizeof(LinkedListElement));
    if(element != NULL) {
        element->value = value;
        element->next = NULL;
        if(emlist_is_empty(list)) {
            list->head = element;
        } else {
            LinkedListElement* current = list->head;
            while(current->next != NULL) {
                current = current->next;
            }
            current->next = element;
        }
    }
}

bool emlist_remove(LinkedList* list, void* value) {
    LinkedListElement* prev = NULL;
    LinkedListElement* next = list->head;
    while(next != NULL) {
        if(next->value == value) {
            if(prev == NULL) {
                list->head = next->next;
            } else {
                prev->next = next->next;
            }
            free(next);
            return true;
        }
        prev = next;
        next = next->next;
    }
    return false;
}

void emlist_clear(LinkedList* list) {
}

void emlist_size(LinkedList* list) {
}

bool emlist_is_empty(LinkedList* list) {
    return list->head == NULL;
}
