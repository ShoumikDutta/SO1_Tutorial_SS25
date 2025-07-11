
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

 // Task 2: Array-based operations
    float calculate_average(float* grades, int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }
    return (count > 0) ? (sum / count) : 0.0;
}

float find_maximum(float* grades, int count) {
    if (count == 0) return 0.0;
    float max = grades[0];
    for (int i = 1; i < count; i++) {
        if (grades[i] > max) {
            max = grades[i];
        }
    }
    return max;
}

// Task 3: Structure definition
typedef struct {
    char name[100];
    int id;
    float* grades;
    int grade_count;
    float average;
    float max_grade;
} student_t;

// Task 3.c: Print student data
void print_student(const student_t* s) {
    printf("Student name: %s\n", s->name);
    printf("ID: %d\n", s->id);
    printf("Grades: ");
    for (int i = 0; i < s->grade_count; i++) {
        printf("%.1f", s->grades[i]);
        if (i < s->grade_count - 1) printf(", ");
    }
    printf("\nAverage: %.2f\n", s->average);
    printf("Maximum: %.2f\n", s->max_grade);
}

// Task 4: Read student data from file
student_t* read_student_from_file(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Failed to open file.\n");
        return NULL;
    }

    char line[1024];
    if (!fgets(line, sizeof(line), fp)) {
        fclose(fp);
        return NULL;
    }
    fclose(fp);

    student_t* s = malloc(sizeof(student_t));
    if (!s) return NULL;

    char* token = strtok(line, ",");
    strcpy(s->name, token);

    token = strtok(NULL, ",");
    s->id = atoi(token);

    float* grades = malloc(100 * sizeof(float)); // support max 100 grades
    int count = 0;
    while ((token = strtok(NULL, ",")) != NULL) {
        grades[count++] = atof(token);
    }

    s->grades = grades;
    s->grade_count = count;
    s->average = calculate_average(grades, count);
    s->max_grade = find_maximum(grades, count);

    return s;
}

// Task 5: Show memory usage
void print_memory_usage(const student_t* s) {
    int grade_mem = s->grade_count * sizeof(float);
    int total = sizeof(student_t) + grade_mem;
    printf("Dynamic memory used: %d bytes\n", grade_mem);
    printf("Total memory (including structure): %d bytes\n", total);
}

int main() {
    // Test Task 2 + 3
    float grades1[] = { 89.5, 76.0, 92.0 };
    int count = sizeof(grades1) / sizeof(grades1[0]);

    student_t student1;
    strcpy(student1.name, "Alice");
    student1.id = 1001;
    student1.grades = grades1;
    student1.grade_count = count;
    student1.average = calculate_average(grades1, count);
    student1.max_grade = find_maximum(grades1, count);

    printf("=== Task 2 + 3 Output ===\n");
    print_student(&student1);

    // Test Task 4 + 5: read from CSV
    printf("\\n=== Task 4 + 5 Output ===\n");
    student_t* s2 = read_student_from_file("student_data.csv"); // this file needs to be in the same folder as main.c
    if (s2) {
        print_student(s2);
        print_memory_usage(s2);
        free(s2->grades);
        free(s2);
    }

    return 0;
}

