/* Tutorial IE1-SO1 C-Programming
  Name: Shoumik Dutta  /
  Date: 02.05.2025

  Topic: Data type, Flow controll, Understanding Error(s), Functions
  Based on: Lecture Code
  Dependencies: N/A
*/
#define _CRT_SECURE_NO_WARNINGS /* to allow scanf() */
#include <stdio.h>



int main() {

	// Problem 1: implementing Ohm´s law U=I*R
	float u, i, r; //declaration
	//printf("Enter the value of I: \n");
	//scanf("%f", &i);
	//printf("Enter the value of R: \n");
	//scanf("%f",&r);

	//u = i * r;

	//printf("U=%.2fV",u);
	// now what if the user can decide what they wants to calculate?
	char val;
	int flag = 0;

	do {
		printf("Which value you want to calculate? \n");
		scanf("%c", &val);
		getchar();
		if (val == 'u' || val == 'U') {
			printf("Enter the value of I: \n");
			scanf("%f", &i);
			printf("Enter the value of R: \n");
			scanf("%f", &r);

			u = i * r;

			printf("U=%.2fV", u);
			flag = 1;
		}

		else if (val == 'r' || val == 'R') {
			printf("Enter the value of U: \n");
			scanf("%f", &u);
			printf("Enter the value of i: \n");
			scanf("%f", &i);

			r = u / i;

			printf("R=%.2fV", r);
			flag = 1;
		}
		else if (val == 'i' || val == 'I') {
			printf("Enter the value of U: \n");
			scanf("%f", &u);
			printf("Enter the value of i: \n");
			scanf("%f", &r);

			i = u / r;

			printf("I=%.2fV", i);
			flag = 1;
		}
		else {
			printf("Invalid Input. Please enter U, R, or I.\n");

		}


	} while (flag == 0);


	// Slope Formula m= (y2-y1)/(x2-x1), One condition, coordinates are int values

	/*int x1, x2, y1, y2;
	float m;

	printf("Enter the value of x1: \n");
	scanf("%d", &x1);

	printf("Enter the value of y1: \n");
	scanf("%d", &y1);

	printf("Enter the value of x2: \n");
	scanf("%d", &x2);

	printf("Enter the value of y2: \n");
	scanf("%d", &y2);

	if (x2 == x1) {
		printf("Slope is undefined (vertical line).");
	} else {
		m = (float)(y2 - y1) / (x2 - x1);
		printf("Slope, m= %.3f", m);
	}*/

	getchar();
	return 0;

}

