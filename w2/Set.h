#ifndef SET_H
#define SET_H

#include <stdbool.h>

/**
 * Abstract type for a set of integers.
 */
typedef struct set *Set;

/**
 * Creates a new empty set.
 */
Set SetNew(void);

/**
 * Frees memory allocated to the set.
 */
void SetFree(Set s);

/**
 * Inserts an element into the set.
 * If the element already exists, no change is made.
 */
void SetInsert(Set s, int elem);

/**
 * Deletes an element from the set if present.
 */
void SetDelete(Set s, int elem);

/**
 * Returns true if the given element is in the set, and false otherwise.
 */
bool SetContains(Set s, int elem);

/**
 * Returns the number of elements in the set.
 */
int SetSize(Set s);

#endif /* SET_H */