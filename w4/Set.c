#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Set.h"

#define MAX_CAPACITY 100

// Concrete representation of a Set using an array
struct set {
    int elems[MAX_CAPACITY];
    int size;  // current number of elements
};

Set SetNew(void) {
    Set newSet = malloc(sizeof(*newSet));
    if (newSet == NULL) {
        fprintf(stderr, "Unable to allocate memory for new set.\n");
        exit(EXIT_FAILURE);
    }
    newSet->size = 0;
    return newSet;
}

void SetFree(Set s) {
    if (s == NULL) return;
    free(s);
}

void SetInsert(Set s, int elem) {
    if (s == NULL) return;

    // Check if the element is already in the set
    for (int i = 0; i < s->size; i++) {
        if (s->elems[i] == elem) {
            // Element already exists, do nothing
            return;
        }
    }

    // If there's room, add the new element
    if (s->size < MAX_CAPACITY) {
        s->elems[s->size] = elem;
        s->size++;
    } else {
        fprintf(stderr, "Set is full. Cannot insert new element.\n");
    }
}

void SetDelete(Set s, int elem) {
    if (s == NULL) return;

    // Find the element
    int index = -1;
    for (int i = 0; i < s->size; i++) {
        if (s->elems[i] == elem) {
            index = i;
            break;
        }
    }

    // If found, remove it by shifting remaining elements
    if (index != -1) {
        for (int j = index; j < s->size - 1; j++) {
            s->elems[j] = s->elems[j + 1];
        }
        s->size--;
    }
}

bool SetContains(Set s, int elem) {
    if (s == NULL) return false;

    for (int i = 0; i < s->size; i++) {
        if (s->elems[i] == elem) {
            return true;
        }
    }
    return false;
}

int SetSize(Set s) {
    if (s == NULL) return 0;
    return s->size;
}