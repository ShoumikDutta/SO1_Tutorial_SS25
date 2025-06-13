#include <stdio.h>
#include <assert.h>
#include <limits.h>

/* ====================== Task 1: Array Operations  ====================== */

/**
 * Finds the minimum value in an array (Pass by Value)
 * @param arr Integer array
 * @param size Size of the array
 * @return Minimum value, or INT_MIN if empty
 */
int find_min(int arr[], int size); // Implement this

/**
 * Doubles each value in the array (Pass by Reference)
 * @param arr Integer array (modified in-place)
 * @param size Size of the array
 */
void double_values(int *arr, int size); // Implement this

/* ====================== Task 2: Pointer Challenges  ====================== */

/**
 * Swaps two integers using pointers (Call by Reference)
 * @param a Pointer to first integer
 * @param b Pointer to second integer
 */
void swap(int *a, int *b); // Implement this

/**
 * Counts zeros in an array using pointer arithmetic
 * @param arr Integer array
 * @param size Size of the array
 * @return Number of zeros
 */
int count_zeros(int *arr, int size); // Implement this

/* ====================== Task 3: Unit Testing  ====================== */

/**
 * Write test cases for find_min() using assert()
 * 1. Test with mixed values
 * 2. Test edge case (empty array)
 */
void test_find_min(); // Implement this

/* ====================== Task 4: Recursion  ====================== */

/**
 * Recursively calculates the sum of an array
 * @param arr Integer array
 * @param size Size of the array
 * @return Sum of elements
 */
int recursive_sum(int arr[], int size); // Implement this

/**
 * Recursive binary search on a sorted array
 * @param arr Sorted integer array
 * @param left Left index
 * @param right Right index
 * @param target Value to find
 * @return Index of target, or -1 if not found
 */
int binary_search(int *arr, int left, int right, int target); // Implement this

/* ====================== Main Function ====================== */

int main() {
    /* Task 1 Demo (Do NOT modify) */
    int arr[] = {3, 1, 4, 1, 5};
    printf("[Task 1] Original array: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    
    // Your implementations should make these work:
    // printf("\nMinimum: %d", find_min(arr, 5));
    // double_values(arr, 5);
    // printf("\nDoubled: ");
    // for (int i = 0; i < 5; i++) printf("%d ", arr[i]);

    /* Task 2 Demo (Do NOT modify) */
    int a = 5, b = 7;
    // swap(&a, &b);
    // printf("\n[Task 2] Swapped: a=%d, b=%d", a, b);

    /* Task 3 (Call your test function here) */
    // test_find_min();

    /* Task 4 Demo (Do NOT modify) */
    int nums[] = {1, 2, 3, 4, 5};
    // printf("\n[Task 4] Recursive sum: %d", recursive_sum(nums, 5));
    // printf("\nBinary search (4): %d", binary_search(nums, 0, 4, 4));

    return 0;
}
