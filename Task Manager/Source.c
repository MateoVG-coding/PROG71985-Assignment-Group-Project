#include <stdio.h>
#include <stdbool.h>


int main(void)
{
	bool continueProgram = true;
	while (continueProgram) 
	{
	
		int menuInput;
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
		scanf_s("%d", &menuInput);

		switch (menuInput)
		{
			case 1:
			{
				break;
			}
			case 2:
			{
				break;
			}
			case 3:
			{
				break;
			}
			case 4:
			{
				break;
			}
			case 5:
			{
				break;
			}
			case 6:
			{
				break;
			}
			case 7:
			{
				break;
			}
			case 0:
			{
				continueProgram = false;
				break;
			}
			default:
			{
				printf("\nInvalid value entered.\n\n");
				break;
			}
		}
	}

	return 0;
}