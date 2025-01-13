#include <stdio.h>
#include <stdbool.h>

bool hasTwoSum(int *arr, int size, int target);

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

static void test_emptyArray(void) {
    print_test_suite_header("test_emptyArray");

    int arr[] = {};
    int size = 0;
    bool result = hasTwoSum(arr, size, 10);
    run_test("Empty array => false", result == false);
}

static void test_singleElement(void) {
    print_test_suite_header("test_singleElement");

    int arr1[] = {5};
    bool result1 = hasTwoSum(arr1, 1, 5);
    run_test("Single element [5], target=5 => false", result1 == false);

    bool result2 = hasTwoSum(arr1, 1, 10);
    run_test("Single element [5], target=10 => false", result2 == false);
}

static void test_twoElements(void) {
    print_test_suite_header("test_twoElements");

    // Should be true: 3+7=10
    int arr1[] = {3, 7};
    bool result1 = hasTwoSum(arr1, 2, 10);
    run_test("[3,7], target=10 => true", result1 == true);

    // Should be false
    int arr2[] = {2, 2};
    bool result2 = hasTwoSum(arr2, 2, 5);
    run_test("[2,2], target=5 => false", result2 == false);
}

static void test_smallArrays(void) {
    print_test_suite_header("test_smallArrays");

    // Simple array, has a pair
    int arr1[] = {1, 2, 3};
    bool result1 = hasTwoSum(arr1, 3, 5); // 2+3=5
    run_test("[1,2,3], target=5 => true", result1 == true);

    // Simple array, no pair
    int arr2[] = {1, 2, 3};
    bool result2 = hasTwoSum(arr2, 3, 6); // No pair sums to 6
    run_test("[1,2,3], target=6 => false", result2 == false);
}

static void test_negativeNumbers(void) {
    print_test_suite_header("test_negativeNumbers");

    int arr[] = {-1, -2, -3, 4, 6};
    // -3 + 6 = 3
    bool result1 = hasTwoSum(arr, 5, 3);
    run_test("[-1,-2,-3,4,6], target=3 => true (-3+6=3)", result1 == true);

    // Check a target that doesn't exist
    bool result2 = hasTwoSum(arr, 5, 11);
    run_test("[-1,-2,-3,4,6], target=11 => false", result2 == false);
}

static void test_duplicateValues(void) {
    print_test_suite_header("test_duplicateValues");

    int arr[] = {2, 2, 4, 4};
    // 2+2=4 => if searching for 4 => true
    bool result1 = hasTwoSum(arr, 4, 4);
    run_test("[2,2,4,4], target=4 => true (2+2=4)", result1 == true);

    // 4+4=8 => if searching for 8 => true
    bool result2 = hasTwoSum(arr, 4, 8);
    run_test("[2,2,4,4], target=8 => true (4+4=8)", result2 == true);

    // If searching for 3 => none => false
    bool result3 = hasTwoSum(arr, 4, 3);
    run_test("[2,2,4,4], target=3 => false", result3 == false);
}

static void test_largeArray(void) {
    print_test_suite_header("test_largeArray");

    // Example array with 10 elements, includes large positive and negative
    int arr[] = {10, 15, -5, 20, 0, 100, 99, 1, 2, -100};
    int size = 10;

    // There's a pair: 1 + 99 = 100
    bool result1 = hasTwoSum(arr, size, 100);
    run_test("large array, target=100 => true (1+99=100)", result1 == true);

    // There's no pair that sums to 999
    bool result2 = hasTwoSum(arr, size, 999);
    run_test("large array, target=999 => false", result2 == false);

    // There's a pair: 15 + -5 = 10
    bool result3 = hasTwoSum(arr, size, 10);
    run_test("large array, target=10 => true (15 + -5=10)", result3 == true);
}

static void test_notUsingSameValueTwice(void) {
    print_test_suite_header("test_notUsingSameValueTwice");

    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    bool result = hasTwoSum(arr, size, 2);
    run_test("Not using the same value twice", result == false);
}

// -----------------------------------------------------------------------------
// Orchestrate all tests
// -----------------------------------------------------------------------------
static void run_tests(void) {
    test_emptyArray();
    test_singleElement();
    test_twoElements();
    test_smallArrays();
    test_negativeNumbers();
    test_duplicateValues();
    test_largeArray();
    test_notUsingSameValueTwice();
}

// -----------------------------------------------------------------------------
// Main
// -----------------------------------------------------------------------------
int main(void) {
    run_tests();
    return 0;
}


// -----------------------------------------------------------------------------
// hasTwoSum function
// -----------------------------------------------------------------------------
bool hasTwoSum(int *arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                return true;
            }
        }
    }
    return false;
}