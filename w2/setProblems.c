#include <stdio.h>
#include "Set.h"

int numOddOccurances(int arr[], int size);
int numSingleOccurrences(int arr[], int size);

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

static void test_numOddOccurances(void) {
    print_test_suite_header("numOddOccurances");

    // Test 1: No duplicates => each element appears once => all are odd occurrences
    {
        int arr[] = {1, 2, 3};
        int size = 3;
        // 1 appears once, 2 appears once, 3 appears once => 3 odd occurrences
        run_test(
            "No duplicates (1,2,3)",
            numOddOccurances(arr, size) == 3
        );
    }

    // Test 2: Some duplicates => (1,1,2,2,3)
    {
        int arr[] = {1, 1, 2, 2, 3};
        int size = 5;
        // 1 appears twice, 2 appears twice, 3 appears once
        // => only '3' has an odd occurrence => final size should be 1
        run_test(
            "Some duplicates (1,1,2,2,3)",
            numOddOccurances(arr, size) == 1
        );
    }

    // Test 3: All same element repeated even times => (1,1,1,1)
    {
        int arr[] = {1, 1, 1, 1};
        int size = 4;
        // 1 appears 4 times => that's even => so final set of odd-occurring elements is empty => 0
        run_test(
            "All same repeated even times (1,1,1,1)",
            numOddOccurances(arr, size) == 0
        );
    }

    // Test 4: All same element repeated odd times => (2,2,2)
    {
        int arr[] = {2, 2, 2};
        int size = 3;
        // 2 appears 3 times => that's odd => final set has '2' => size is 1
        run_test(
            "All same repeated odd times (2,2,2)",
            numOddOccurances(arr, size) == 1
        );
    }

    // Test 5: Empty array
    {
        int arr[1] = {0};
        int size = 0;
        run_test(
            "Empty array",
            numOddOccurances(arr, size) == 0
        );
    }

    // Test 6: Tutorial Example: [4, 3, 4, 8, 8, 4]
    {
        int arr[] = {4, 3, 4, 8, 8, 4};
        int size = 6;
        run_test(
            "Tutorial Example (4, 3, 4, 8, 8, 4)",
            numOddOccurances(arr, size) == 2
        );
    }
}

static void test_numSingleOccurrences(void) {
    print_test_suite_header("numSingleOccurrences");

    // Test 1: No duplicates => (1,2,3)
    {
        int arr[] = {1, 2, 3};
        int size = 3;
        // Because Set never gets updated, the result is size => 3
        run_test(
            "No duplicates (1,2,3)",
            numSingleOccurrences(arr, size) == 3
        );
    }

    // Test 2: Some duplicates => (1,1,2,2,3)
    {
        int arr[] = {1, 1, 2, 2, 3};
        int size = 5;
        run_test(
            "Some duplicates (1,1,2,2,3)",
            numSingleOccurrences(arr, size) == 1
        );
    }

    // Test 3: All same => (1,1,1,1)
    {
        int arr[] = {1, 1, 1, 1};
        int size = 4;
        run_test(
            "All same (1,1,1,1)",
            numSingleOccurrences(arr, size) == 0
        );
    }

    // Test 4: Empty array
    {
        int arr[1] = {0};
        int size = 0;
        run_test(
            "Empty array",
            numSingleOccurrences(arr, size) == 0
        );
    }

    // Test 5: Tutorial Example
    {
        int arr[] = {4, 3, 4, 8, 7, 4};
        int size = 6;
        run_test(
            "Tutorial Example (4, 3, 4, 8, 7, 4)",
            numSingleOccurrences(arr, size) == 3
        );
    }
}

// -----------------------------------------------------------------------------
// Orchestrate all tests
// -----------------------------------------------------------------------------
static void run_tests(void) {
    test_numOddOccurances();
    test_numSingleOccurrences();
}

int main(void) {
    run_tests();
    return 0;
}

int numOddOccurances(int arr[], int size) {
    Set s = SetNew();
    for (int i = 0; i < size; i++) {
        if (SetContains(s, arr[i])) {
            SetDelete(s, arr[i]);
        } else {
            SetInsert(s, arr[i]);
        }
    }
    return SetSize(s);
}

int numSingleOccurrences(int arr[], int size) {
    Set s1 = SetNew();
    Set s2 = SetNew();
    for (int i = 0; i < size; i++) {
        if (SetContains(s1, arr[i])) {
            SetInsert(s2, arr[i]);
        }
        SetInsert(s1, arr[i]);
    }
    return SetSize(s1) - SetSize(s2);
}