#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ANSI colour codes
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

// Function Declarations
int listLength(struct node *l);
int listCountOdds(struct node *l);
bool listIsSorted(struct node *l);
struct node *listDelete(struct node *l, int value);
struct node *listDeleteAll(struct node *l, int value);
int listLengthWrapper(struct list *list);

// Function to create a node in memory
struct node *createNode(int value) {
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->value = value;
    new->next = NULL;
    return new;
}

// Function to add node to the head of the list
struct node *prependNode(int value, struct node *list) {
    struct node *new = createNode(value);
    new->next = list;
    return new;
}

// Function to free a linked list
void freeList(struct node *list) {
    while (list != NULL) {
        struct node *del = list; 
        list = list->next;
        free(del);
    }
}

// Helper function to report test results with colour
void run_test(const char *test_name, bool condition) {
    if (condition) {
        printf("%sTest %s: PASSED%s\n", GREEN, test_name, RESET);
    } else {
        printf("%sTest %s: FAILED%s\n", RED, test_name, RESET);
    }
}

// Test listLength
void test_listLength() {
    // Test with empty list
    struct node *list = NULL;
    run_test("listLength (empty list)", listLength(list) == 0);

    // Test with single element
    list = prependNode(1, list);
    run_test("listLength (single element)", listLength(list) == 1);

    // Test with multiple elements
    list = prependNode(2, list);
    list = prependNode(3, list);
    run_test("listLength (multiple elements)", listLength(list) == 3);
    freeList(list);
}

// Test listLengthWrapper
void test_listLengthWrapper() {
    // Test with empty list
    struct list *emptyList = malloc(sizeof(struct list));
    emptyList->head = NULL;
    run_test("listLengthWrapper (empty list)", listLengthWrapper(emptyList) == 0);
    free(emptyList);

    // Test with single element
    struct list *singleElementList = malloc(sizeof(struct list));
    singleElementList->head = prependNode(42, NULL);
    run_test("listLengthWrapper (single element)", listLengthWrapper(singleElementList) == 1);
    freeList(singleElementList->head);
    free(singleElementList);

    // Test with multiple elements
    struct list *multipleElementsList = malloc(sizeof(struct list));
    multipleElementsList->head = NULL;
    multipleElementsList->head = prependNode(3, multipleElementsList->head);
    multipleElementsList->head = prependNode(2, multipleElementsList->head);
    multipleElementsList->head = prependNode(1, multipleElementsList->head);
    run_test("listLengthWrapper (multiple elements)", listLengthWrapper(multipleElementsList) == 3);
    freeList(multipleElementsList->head);
    free(multipleElementsList);
}

// Test listIsSorted
void test_listIsSorted() {
    // Test with sorted list
    struct node *reversedList = NULL;
    reversedList = prependNode(1, reversedList);
    reversedList = prependNode(2, reversedList);
    reversedList = prependNode(3, reversedList);
    run_test("listIsSorted (sorted)", listIsSorted(reversedList) == false);
    freeList(reversedList);

    // Test with unsorted list
    struct node *sortedList = NULL;
    sortedList = prependNode(3, sortedList);
    sortedList = prependNode(2, sortedList);
    sortedList = prependNode(1, sortedList);
    run_test("listIsSorted (unsorted)", listIsSorted(sortedList) == true);
    freeList(sortedList);

    // Test with empty list
    struct node *emptyList = NULL;
    run_test("listIsSorted (empty list)", listIsSorted(emptyList) == true);
    freeList(emptyList);

    // Test with single-element list
    struct node *singleList = prependNode(42, NULL);
    run_test("listIsSorted (single element)", listIsSorted(singleList) == true);
    freeList(singleList);
}

// Test listDelete
void test_listDelete() {
    // Test deleting first occurrence
    struct node *list = NULL;
    list = prependNode(1, list);
    list = prependNode(2, list);
    list = prependNode(3, list);
    list = prependNode(3, list);
    list = listDelete(list, 3);
    run_test("listDelete (first occurrence)", list != NULL && list->value == 3 &&
             list->next != NULL && list->next->value == 2 && list->next->next->value == 1);
    freeList(list);

    // Test deleting from empty list
    struct node *emptyList = NULL;
    emptyList = listDelete(emptyList, 1);
    run_test("listDelete (empty list)", emptyList == NULL);
    freeList(emptyList);

    // Test deleting a value not in the list
    struct node *singleElementList = prependNode(1, NULL);
    singleElementList = listDelete(singleElementList, 2);
    run_test("listDelete (value not found)", singleElementList != NULL && singleElementList->value == 1);
    freeList(singleElementList);
}

// Test listDeleteAll
void test_listDeleteAll() {
    // Test deleting all occurrences
    struct node *list = NULL;
    list = prependNode(1, list);
    list = prependNode(2, list);
    list = prependNode(3, list);
    list = prependNode(3, list);
    list = listDeleteAll(list, 3);
    run_test("listDeleteAll (all occurrences)", list != NULL && list->value == 2 
             && list->next != NULL && list->next->value == 1);
    freeList(list);

    // Test deleting from empty list
    struct node *emptyList = NULL;
    emptyList = listDeleteAll(emptyList, 1);
    run_test("listDeleteAll (empty list)", emptyList == NULL);
    freeList(emptyList);

    // Test deleting a value not in the list
    struct node *singleElementList = prependNode(1, NULL);
    singleElementList = listDeleteAll(singleElementList, 2);
    run_test("listDeleteAll (value not found)", singleElementList != NULL && singleElementList->value == 1);
    freeList(singleElementList);
}

void print_test_suite_header(const char *suite_name) {
    printf("\nTest Suite: %s\n", suite_name);
    printf("-----------------------\n");
}

void run_tests() {
    // Test Suite: listLength
    print_test_suite_header("listLength");
    test_listLength();

    // Test Suite: listIsSorted
    print_test_suite_header("listIsSorted");
    test_listIsSorted();

    // Test Suite: listDelete
    print_test_suite_header("listDelete");
    test_listDelete();

    // Test Suite: listDeleteAll
    print_test_suite_header("listDeleteAll");
    test_listDeleteAll();

    // Test Suite: listLengthWrapper
    print_test_suite_header("listLengthWrapper");
    test_listLengthWrapper();
}

int main(void) {
    run_tests();
    return 0;
}

// 1. Write a recursive function to compute the length of a linked list
int listLength(struct node *l) {
    if (l == NULL) return 0;
    return 1 + listLength(l->next);
}

// 2. Write a recursive function to count the number of odd numbers in a linked list
int listCountOdds(struct node *l) {
    if (l == NULL) return 0;
    else if (l->value % 2 == 1) {
        return 1 + listCountOdds(l->next);
    }
    return listCountOdds(l->next);
}

// 3. Write a recursive function to check if a list is sorted in ascending order
bool listIsSorted(struct node *l) {
    if (l == NULL || l->next == NULL) return true;
    else if (l->value > l->next->value) return false;
    return listIsSorted(l->next);
}

// 4. Write a recursive function to delete the first instance of a value from a linked list
struct node *listDelete(struct node *l, int value) {
    if (l == NULL) return NULL;
    else if (l->value == value) {
        struct node *del = l;
        l = l->next;
        free(del);
        return l;
    } else {
        l->next = listDelete(l->next, value);
    }
    return l;
}

// 5. Write a recursive function to delete all instances of a value from a linked list
struct node *listDeleteAll(struct node *l, int value) {
    if (l == NULL) return NULL;
    else if (l->value == value) {
        struct node *newHead = l->next;
        free(l);
        return listDeleteAll(newHead, value);
    } else {
        l->next = listDeleteAll(l->next, value);
    }
    return l;
}

// 6. Wrapper version - List Length find the length of a list, given a wrapper to a linked list
int listLengthWrapper(struct list *list) {
    return listLength(list->head);
}