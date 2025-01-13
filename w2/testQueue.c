#include <stdio.h>
#include <stdbool.h>
#include "Queue.h"

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

static void test_basicEnqueueDequeue(void) {
    print_test_suite_header("test_basicEnqueueDequeue");

    Queue q = QueueNew();

    // Enqueue 3 items: 10, 20, 30
    QueueEnqueue(q, 10);
    QueueEnqueue(q, 20);
    QueueEnqueue(q, 30);

    // Dequeue them and check the order
    bool test1 = (QueueDequeue(q) == 10);
    run_test("Dequeue first => 10", test1);

    bool test2 = (QueueDequeue(q) == 20);
    run_test("Dequeue second => 20", test2);

    bool test3 = (QueueDequeue(q) == 30);
    run_test("Dequeue third => 30", test3);
}

static void test_interleavedOperations(void) {
    print_test_suite_header("test_interleavedOperations");

    Queue q = QueueNew();

    // Enqueue 3 items: 1, 2, 3
    QueueEnqueue(q, 1);
    QueueEnqueue(q, 2);
    QueueEnqueue(q, 3);

    // Dequeue 2 items => expect 1, then 2
    bool test1 = (QueueDequeue(q) == 1);
    run_test("Dequeue => 1", test1);

    bool test2 = (QueueDequeue(q) == 2);
    run_test("Dequeue => 2", test2);

    // Enqueue 2 more items: 4, 5
    QueueEnqueue(q, 4);
    QueueEnqueue(q, 5);

    // Remaining items in queue: 3, 4, 5
    bool test3 = (QueueDequeue(q) == 3);
    run_test("Dequeue => 3", test3);

    bool test4 = (QueueDequeue(q) == 4);
    run_test("Dequeue => 4", test4);

    bool test5 = (QueueDequeue(q) == 5);
    run_test("Dequeue => 5", test5);
}

static void test_dequeueFromEmpty(void) {
    print_test_suite_header("test_dequeueFromEmpty");

    // This test will depend on how your code handles dequeue from empty.
    // If your `StackPop` or `QueueDequeue` does not handle empty gracefully,
    // it might crash or return garbage. 
    // We'll demonstrate a possible approach, but you may need to adjust
    // depending on your implementation requirements.
    
    Queue q = QueueNew();
    
    // Attempt to dequeue from an empty queue.
    // If your code doesn't define behavior for this, 
    // you may skip or handle it differently.
    // We'll assume a return of 0 or some sentinel for an empty queue.
    int val = QueueDequeue(q);
    bool test1 = (val == 0); // or whichever behavior you define
    run_test("Dequeue from empty => 0 (or sentinel)", test1);
}

// -----------------------------------------------------------------------------
// Orchestrate all tests
// -----------------------------------------------------------------------------
static void run_tests(void) {
    test_basicEnqueueDequeue();
    test_interleavedOperations();
    test_dequeueFromEmpty();
}

int main(void) {
    run_tests();
    return 0;
}