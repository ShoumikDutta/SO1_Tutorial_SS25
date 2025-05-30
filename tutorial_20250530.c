/* Tutorial IE1-SO1 C-Programming
  Name: Shoumik Dutta
  Date: 30.05.2025
  Topics: 2D Arrays, Strings, Functions
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define WEEKS 4
#define DAYS_PER_WEEK 7
#define MAX_STR_LEN 100
#define MIN_TEMP -50.0
#define MAX_TEMP 50.0

// ===== Task 1: 4×7 Array Operations ===== //

void calculate_weekly_averages(double temps[WEEKS][DAYS_PER_WEEK], double weekly_avg[WEEKS]) {
    for (int week = 0; week < WEEKS; week++) {
        double sum = 0.0;
        for (int day = 0; day < DAYS_PER_WEEK; day++) {
            sum += temps[week][day];
        }
        weekly_avg[week] = sum / DAYS_PER_WEEK;
    }
}

void scale_weekly_temperatures(double temps[WEEKS][DAYS_PER_WEEK], double factor) {
    for (int week = 0; week < WEEKS; week++) {
        for (int day = 0; day < DAYS_PER_WEEK; day++) {
            temps[week][day] *= factor;
        }
    }
}

// ===== Task 2: String Processing ===== //

int count_vowels(const char str[][MAX_STR_LEN]) {
    int count = 0;
    for (int i = 0; str[0][i] != '\0'; i++) {
        char c = tolower(str[0][i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

void reverse_string(char str[][MAX_STR_LEN]) {
    int len = strlen(str[0]);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[0][i];
        str[0][i] = str[0][j];
        str[0][j] = temp;
    }
}

// ===== Task 3: Input Validation ===== //

double get_valid_temperature() {
    double temp;
    while (1) {
        printf("Enter temperature (-50.0 to 50.0): ");
        if (scanf("%lf", &temp) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }
        if (temp >= MIN_TEMP && temp <= MAX_TEMP) {
            return temp;
        }
        printf("Temperature must be between -50.0 and 50.0\n");
    }
}

void read_four_weeks_temperatures(double temps[WEEKS][DAYS_PER_WEEK]) {
    for (int week = 0; week < WEEKS; week++) {
        printf("\nWeek %d:\n", week + 1);
        for (int day = 0; day < DAYS_PER_WEEK; day++) {
            printf("Day %d: ", day + 1);
            temps[week][day] = get_valid_temperature();
        }
    }
}

// ===== Main Function ===== //
int main() {
    double temps[WEEKS][DAYS_PER_WEEK] = {
        {20.1, 21.3, 19.8, 22.4, 23.0, 18.7, 19.9}, // Week 1
        {17.5, 16.8, 18.2, 20.5, 21.1, 22.3, 19.4}, // Week 2
        {23.6, 24.2, 25.0, 22.7, 21.9, 20.5, 19.8}, // Week 3
        {18.9, 17.6, 16.5, 15.8, 14.9, 16.2, 17.1}  // Week 4
    };

    // Task 1: Weekly Averages
    double weekly_avg[WEEKS];
    calculate_weekly_averages(temps, weekly_avg);
    printf("Weekly Averages:\n");
    for (int week = 0; week < WEEKS; week++) {
        printf("Week %d: %.1f\n", week + 1, weekly_avg[week]);
    }

    // Task 1: Scaling
    scale_weekly_temperatures(temps, 1.1);
    printf("\nScaled Temperatures (+10%%):\n");
    for (int week = 0; week < WEEKS; week++) {
        printf("Week %d: ", week + 1);
        for (int day = 0; day < DAYS_PER_WEEK; day++) {
            printf("%.1f ", temps[week][day]);
        }
        printf("\n");
    }

    // Task 2: String Operations
    char str[1][MAX_STR_LEN] = { "ProgrammingIsFun" };
    printf("\nVowels in \"%s\": %d\n", str[0], count_vowels(str));
    reverse_string(str);
    printf("Reversed: %s\n", str[0]);

    // Task 3: User Input (Uncomment to test)
     double user_temps[WEEKS][DAYS_PER_WEEK];
     read_four_weeks_temperatures(user_temps);

    return 0;
}
