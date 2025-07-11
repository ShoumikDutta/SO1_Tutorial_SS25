/* Tutorial IE1-SO1 C-Programming
  Name: Shoumik Dutta  /
  Date: 11.07.2025

  Topic: Array, Pointer, Files, Memory Allocation, Structure
  Based on: Lecture Code 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============================================
   TASK 2: Array-based operations
   --------------------------------------------
   2.a) Implement a function to calculate average of grades in an array.
   2.b) Implement a function to find the maximum grade.
*/

// float calculate_average(float *grades, int count);
// float find_maximum(float *grades, int count);

/* ============================================
   TASK 3: Structures
   --------------------------------------------
   3.a) Define a struct 'student_t' with fields:
        - name (string), id (int), grades (float array),
          grade_count, average, max_grade

   3.b) Fill a student_t variable using fixed array data
   3.c) Implement a function to print the struct
*/

// typedef struct {
//     char name[100];
//     int id;
//     float *grades;
//     int grade_count;
//     float average;
//     float max_grade;
// } student_t;

// void print_student(const student_t *s);

/* ============================================
   TASK 4: File I/O and Dynamic Memory
   --------------------------------------------
   4.a) Implement function to read student data from CSV file.
        Format: name,id,grade1,grade2,...

   4.b) Allocate memory for grades array and store data in student_t

   4.c) Return a pointer to a fully initialized student_t structure
*/

// student_t *read_student_from_file(const char *filename);

/* ============================================
   TASK 5: Memory Usage Analysis
   --------------------------------------------
   5.a) Implement a function to print how much memory
        was dynamically allocated for a student.
*/

// void print_memory_usage(const student_t *s);

int main() {
    // TODO: Task 2 - Declare a fixed grade array and calculate average and max

    // TODO: Task 3 - Fill struct and print student info

    // TODO: Task 4 - Read student from CSV file and print data

    // TODO: Task 5 - Print memory usage info

    return 0;
}



