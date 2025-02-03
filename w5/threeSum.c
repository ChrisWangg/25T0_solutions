#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "HashTable.h"

// ANSI colour codes
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

// Declaration of threeSum function.
bool threeSum(int arr[], int size, int sum);

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
// Test 1: Empty Array
// -----------------------------------------------------------------------------
static void test_emptyArray(void) {
    print_test_suite_header("test_emptyArray");

    int arr[] = {};
    int size = 0;
    int target = 0;
    // With no elements, no triplet exists.
    bool result = threeSum(arr, size, target);
    run_test("Empty array should return false", result == false);
}

// -----------------------------------------------------------------------------
// Test 2: No Valid Triplet
// -----------------------------------------------------------------------------
static void test_noTriplet(void) {
    print_test_suite_header("test_noTriplet");

    int arr[] = {1, 2, 3};
    int size = 3;
    int target = 10; // Only triplet: 1+2+3 = 6
    bool result = threeSum(arr, size, target);
    run_test("Array {1,2,3} with target 10 returns false", result == false);
}

// -----------------------------------------------------------------------------
// Test 3: Valid Triplet in an Array of Positives
// -----------------------------------------------------------------------------
static void test_validTriplet(void) {
    print_test_suite_header("test_validTriplet");

    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    int target = 9; // Example: 2+3+4 = 9, or 1+3+5 = 9.
    bool result = threeSum(arr, size, target);
    run_test("Array {1,2,3,4,5} with target 9 returns true", result == true);
}

// -----------------------------------------------------------------------------
// Test 4: Valid Triplet with Negative Numbers (Unsorted)
// -----------------------------------------------------------------------------
static void test_negativeNumbers(void) {
    print_test_suite_header("test_negativeNumbers");

    // Unsorted array with negative numbers.
    int arr[] = { -1, 2, -4, 1, 0, -1 };
    int size = 6;
    int target = 0; // For example: -1 + 1 + 0 = 0.
    bool result = threeSum(arr, size, target);
    run_test("Array {-1,2,-4,1,0,-1} with target 0 returns true", result == true);
}

// -----------------------------------------------------------------------------
// Test 5: Valid Triplet with Duplicates
// -----------------------------------------------------------------------------
static void test_duplicates(void) {
    print_test_suite_header("test_duplicates");

    int arr[] = {1, 1, 1, 1};
    int size = 4;
    int target = 3; // 1+1+1 = 3
    bool result = threeSum(arr, size, target);
    run_test("Array {1,1,1,1} with target 3 returns true", result == true);
}

// -----------------------------------------------------------------------------
// Test 6: Unsorted Array Without Valid Triplet
// -----------------------------------------------------------------------------
static void test_unsortedNoTriplet(void) {
    print_test_suite_header("test_unsortedNoTriplet");

    int arr[] = { 7, 2, 5, 1, 9, 3 };
    int size = 6;
    int target = 20; // No three numbers in the array add up to 20.
    bool result = threeSum(arr, size, target);
    run_test("Unsorted array {7,2,5,1,9,3} with target 20 returns false", result == false);
}

// -----------------------------------------------------------------------------
// Run all tests
// -----------------------------------------------------------------------------
static void run_tests(void) {
    test_emptyArray();
    test_noTriplet();
    test_validTriplet();
    test_negativeNumbers();
    test_duplicates();
    test_unsortedNoTriplet();
}

int main(void) {
    run_tests();
    return 0;
}

bool threeSum(int arr[], int size, int sum) {
    HashTable container = HashTableNew();
    for (int i = 0; i < size; i++) {
        if (HashTableContains(container, sum - arr[i])) {
            HashTableFree(container);
            return true;
        }
        for (int j = 0; j < i; j++) {
            HashTableInsert(container, arr[j] + arr[i], 0);
        }
    }
    HashTableFree(container);
    return false;
}