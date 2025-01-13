#include <stdio.h>
#include <stdbool.h>
#include "bst.h"

// ANSI colour codes
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

// -----------------------------------------------------------------------------
// Helper function to print test results in colour
// -----------------------------------------------------------------------------
static void run_test(const char *test_name, bool condition) {
    if (condition) {
        printf("%sTest %s: PASSED%s\n", GREEN, test_name, RESET);
    } else {
        printf("%sTest %s: FAILED%s\n", RED, test_name, RESET);
    }
}

// -----------------------------------------------------------------------------
// Helper function to print test suite headers
// -----------------------------------------------------------------------------
static void print_test_suite_header(const char *suite_name) {
    printf("\nTest Suite: %s\n", suite_name);
    printf("-----------------------\n");
}

// -----------------------------------------------------------------------------
// Test Functions
// -----------------------------------------------------------------------------

// Test BST insertion with a simple sequence
static void test_bstInsert(void) {
    print_test_suite_header("test_bstInsert");

    struct node *root = NULL;
    int values[] = {4, 6, 5, 2, 1, 3, 7};
    int n = sizeof(values) / sizeof(values[0]);

    // Insert values
    for (int i = 0; i < n; i++) {
        root = bstInsert(root, values[i]);
    }

    // For now, we only check if the root is not NULL after insertion.
    // (You could add a function to traverse the tree and verify structure if needed.)
    bool test1 = (root != NULL);
    run_test("Root not NULL after inserts", test1);

    bstFree(root);
}

// Test Q3: bstCountOdds
static void test_bstCountOdds(void) {
    print_test_suite_header("test_bstCountOdds");

    struct node *root = NULL;
    int values[] = {4, 6, 5, 2, 1, 3, 7}; // 5,1,3,7 are odd => 4 odd numbers
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = bstInsert(root, values[i]);
    }

    // CURRENTLY DUMMY, returns -1 by default
    int result = bstCountOdds(root);

    // We expect 4, but the function is not yet implemented
    // We'll check if 'result == 4' once you implement it
    run_test("Count of odd values => 4 (currently dummy = -1)", result == 4);

    bstFree(root);
}

// Test Q4: bstCountInternal
static void test_bstCountInternal(void) {
    print_test_suite_header("test_bstCountInternal");

    struct node *root = NULL;
    int values[] = {4, 6, 5, 2, 1, 3, 7};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = bstInsert(root, values[i]);
    }

    // CURRENTLY DUMMY, returns -1 by default
    int result = bstCountInternal(root);

    // Let's guess what the internal count should be:
    //   Insert order: 4,6,5,2,1,3,7
    //   Structure (roughly):
    //           4
    //         /   \
    //        2     6
    //       / \   / \
    //      1   3 5   7
    //            
    //   Internal nodes are: 4,2,6 => 3 total
    run_test("Count of internal nodes => 3 (currently dummy = -1)", result == 3);

    bstFree(root);
}

// Test Q5: bstNodeLevel
static void test_bstNodeLevel(void) {
    print_test_suite_header("test_bstNodeLevel");

    struct node *root = NULL;
    int values[] = {4, 6, 5, 2, 1, 3, 7};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = bstInsert(root, values[i]);
    }

    // CURRENTLY DUMMY, returns -1 by default
    // Once implemented, 
    //   key=4 => level 0
    //   key=2 => level 1
    //   key=3 => level 2
    //   key=10 => not in tree => -1

    bool test1 = (bstNodeLevel(root, 4) == 0);
    run_test("Level of root (4) => 0 (currently dummy = -1)", test1);

    bool test2 = (bstNodeLevel(root, 3) == 2);
    run_test("Level of 3 => 2 (currently dummy = -1)", test2);

    bool test3 = (bstNodeLevel(root, 10) == -1);
    run_test("Level of non-existent key => -1 (currently dummy = -1)", test3);

    bstFree(root);
}

// Test Q6: bstCountGreater
static void test_bstCountGreater(void) {
    print_test_suite_header("test_bstCountGreater");

    struct node *root = NULL;
    int values[] = {4, 6, 5, 2, 1, 3, 7};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = bstInsert(root, values[i]);
    }

    // CURRENTLY DUMMY, returns -1 by default
    // For val=3 => greater numbers are {4,5,6,7} => total = 4
    int result = bstCountGreater(root, 3);
    run_test("Count of values > 3 => 4 (currently dummy = -1)", result == 4);

    bstFree(root);
}

// -----------------------------------------------------------------------------
// Orchestrate all tests
// -----------------------------------------------------------------------------
static void run_tests(void) {
    test_bstInsert();
    test_bstCountOdds();
    test_bstCountInternal();
    test_bstNodeLevel();
    test_bstCountGreater();
}

int main(void) {
    run_tests();
    return 0;
}