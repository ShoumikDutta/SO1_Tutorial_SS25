/* Tutorial IE1-SO1 C-Programming
  Name: Shoumik Dutta  /
  Date: 13.06.2025

  Topic: Array, Pointer(call by value & call by reference), Unit test,Recursion
  Based on: Lecture Code
  Dependencies: assert.h , limits.h
*/

#include <stdio.h>
#include <assert.h>
#include <limits.h>

/* ====================== Task 1: Array Operations ====================== */

/**
 * Finds the minimum value in an array (Pass by Value)
 * @param arr Integer array
 * @param size Size of the array
 * @return Minimum value, or INT_MIN if empty
 */
int find_min(int arr[], int size) {
    if (size == 0) {
        return INT_MIN;
    }
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

/**
 * Doubles each value in the array (Pass by Reference)
 * @param arr Integer array (modified in-place)
 * @param size Size of the array
 */
void double_values(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
        // arr[i]= arr[i]*2; 
        //arr[i] = 3*2;
    }
}

/* ====================== Task 2: Pointer Challenges ====================== */

/**
 * Swaps two integers using pointers (Call by Reference)
 * @param a Pointer to first integer
 * @param b Pointer to second integer
 */

// & = address of X( get to memory address of variable X)
//* = Dereference (Accesses value at a ponter) 
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}// Implement this

/**
 * Counts zeros in an array using pointer arithmetic
 * @param arr Integer array
 * @param size Size of the array
 * @return Number of zeros
 */
int count_zeros(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == 0) {
            count++;
        }
    }
    return count;
} // Implement this

/* ====================== Task 3: Unit Testing ====================== */

/**
 * Write test cases for find_min() using assert()
 * 1. Test with mixed values
 * 2. Test edge case (empty array)
 */
void test_find_min() {
    int arr1[] = { 5,-2,10,0 };
    assert(find_min(arr1, 4) == -2);
    assert(find_min(NULL, 0) == INT_MIN);
    printf("\nTask 1.a tested.\n");
    int arr2[] = { 5,2,3 };
    double_values(arr2, 3);
    assert(arr2[0] == 10 && arr2[1] == 4 && arr2[2] == 6);
    printf("\nTask 1.b tested.\n");

    int arr3[] = { 0,-2,10,0 };
    assert(count_zeros(arr3, 4) == 2);
    printf("\nTask 2 tested.\n");


}// Implement this

/* ====================== Task 4: Recursion ====================== */

/**
 * Recursively calculates the sum of an array
 * @param arr Integer array
 * @param size Size of the array
 * @return Sum of elements
 */
// arr= 1, 2,3;
int recursive_sum(int arr[], int size) {
    if (size == 0) {
        return 0; // base case
    }
    return arr[0] + recursive_sum(arr + 1, size - 1); // recursive step
} // Implement this

/**
 * Recursive binary search on a sorted array
 * @param arr Sorted integer array
 * @param left Left index
 * @param right Right index
 * @param target Value to find
 * @return Index of target, or -1 if not found
 */
int binary_search(int* arr, int left, int right, int target) {
    if (left > right) return -1; //base case : target not found

    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        return mid;
    }

    if (arr[mid] < target) {
        return binary_search(arr, mid + 1, right, target);
    }
    else {
        return binary_search(arr, left, mid - 1, target);
    }
    
}// Implement this

/* ====================== Main Function ====================== */

int main() {
    /* Task 1 Demo (Do NOT modify) */
    int arr[] = { 3, 1, 4, 1, 5 };
    printf("[Task 1] Original array: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);

    // Your implementations should make these work:
     printf("\nMinimum: %d", find_min(arr, 5));
     double_values(arr, 5);
     printf("\nDoubled: ");
     for (int i = 0; i < 5; i++) printf("%d ", arr[i]);

    /* Task 2 Demo (Do NOT modify) */
    int a = 5, b = 7;
    printf("\n[Task 2] Before Swapped: a=%d, b=%d", a, b);
    swap(&a, &b);
    printf("\n[Task 2] Swapped: a=%d, b=%d", a, b);

    /* Task 3 (Call your test function here) */
     test_find_min();

    /* Task 4 Demo (Do NOT modify) */
    int nums[] = { 1, 2, 3, 4, 5 };
     printf("\n[Task 4] Recursive sum: %d", recursive_sum(nums, 5));
     printf("\nBinary search (4): %d", binary_search(nums, 0, 4, 4));

    return 0;
}

/* OUTPUT
* Original array: 3 1 4 1 5
Minimum: 1
Doubled: 6 2 8 2 10
Swapped: a=7, b=5
All unit tests passed!
Recursive sum: 15
Binary search (4): 3
*/
