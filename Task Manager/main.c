//PROG71985- Group project (Task1)
//Mateo Vega & Jose Ibanez - December 2021

#include "main.h"

int main(void)
{
	char junkChars[JUNKCHARS];

	int numberTasks = 0;


	PTASK arrayTasks[NUMBEROFTASKS];

	createArrayTasks(arrayTasks);                        //Initializing the array.

	loadTasks(arrayTasks, &numberTasks);                 //Loading data from the file if any.

	bool continueProgram = true;
	while (continueProgram)
	{
		int menuInput;

		printWelcome();

		printMenu();

		printf("Please enter the number of the option that you want to choose: ");

		if (scanf_s("%d", &menuInput) != 1)             //Input Vaidation that avoids the entering of invalid values as well as errors in the loop.
		{
			printf("You have entered an invalid value.\n");
			scanf_s("%s", junkChars, JUNKCHARS);
			exit(1);
		}
		printf("\n");

		switch (menuInput)
		{
			case 1:
			{
				addNewTask(arrayTasks[numberTasks], &numberTasks);
			
				break;
			}
			case 2:
			{
				deleteTask(arrayTasks, &numberTasks);

				break;
			}
			case 3:
			{
				updateTask(arrayTasks, numberTasks);
				break;
			}
			case 4:
			{
				printSingleTask(arrayTasks, numberTasks);
				break;
			}
			case 5:
			{
				printRangeTask(arrayTasks, numberTasks);
				break;
			}
			case 6:
			{
				printAllTasks(arrayTasks, numberTasks);
				break;
			}
			case 7:
			{
				searchForTask(arrayTasks, &numberTasks);
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
		saveTasks(arrayTasks, numberTasks);             //Saving changes made in the current run if any.                       
	}

	return 0;
}

void printWelcome()
{
	printf("\n **********************\n");
	printf("***     Welcome to     ***\n");
	printf("***  your task manager ***\n");
	printf("  **********************\n\n");
}

void printMenu()
{
	printf("1) Add new task.\n");
	printf("2) Delete a task.\n");
	printf("3) Update a task.\n");
	printf("4) Display a task.\n");
	printf("5) Display a group of tasks.\n");
	printf("6) Display all tasks.\n");
	printf("7) Search a task.\n");
	printf("0) Exit.\n\n");
}