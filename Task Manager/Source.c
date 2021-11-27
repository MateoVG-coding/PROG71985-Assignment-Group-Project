#include <stdio.h>


int main(void)
{
	int number = 0;
	printf("  **********************\n");
	printf("***     Welcome to     ***\n");
	printf("***  your task manager ***\n");
	printf("  **********************\n\n");

	printf("1) Add new task.\n");
	printf("2) Delete a task.\n");
	printf("3) Update a task.\n");
	printf("4) Display a task.\n");
	printf("5) Display a group of tasks.\n");
	printf("6) Display all tasks.\n");
	printf("7) Search a task.\n");
	printf("0) Exit.\n\n");

	printf("Please enter the number of the option that you want to choose: ");
	if (scanf_s("%d", &number) != 1)
		return printf("\nInvalid value entered.\n");
	else if (number > 7 || number < 0)
		return printf("\nThe number that you entered does not belong to any of the options.\n");


	return 0;
}