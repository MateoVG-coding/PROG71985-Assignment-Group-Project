//PROG71985- Group project (Task1)
//Mateo Vega & Jose Ibanez - December 2021

#include "task.h"

void createArrayTasks(PTASK tasks[])
{
	for (int i = 0; i < NUMBEROFTASKS; i++)               //Loop to initialize each position of the array.
	{
		tasks[i] = (PTASK)malloc(sizeof(TASK));
		setTaskNumber(tasks[i], i + 1);                   //Giving each task an specific task number.
	}
}

void addNewTask(PTASK task, int* numberOfTasks)
{
	char junkChars[JUNKCHARS] = { '\0' };
	char title[LENGTHTITLE] = { '\0' };
	int status = 0;
	int type = 0;

	printf("Please enter the task you want to add: ");

	if (scanf_s("%s", title, LENGTHTITLE) != 1)           //Input validation that checks if the input entered is valid or not and avoids errors in the funciton.
	{
		printf("You have entered an invalid value.\n");
		scanf_s("%s", junkChars, JUNKCHARS);
		return;
	}
	printf("\n");

	setTitle(task, title);                               //Setting the string entered as the title for the current task.


	printf("Please enter the type of the task\n");
	printf("1) Personal\t 2) School\t 3) Work\t 4) Home\n");
	printf("Enter here: ");
	if (scanf_s("%d", &type) != 1)
	{
		printf("You have entered an invalid value.\n");
		scanf_s("%s", junkChars, JUNKCHARS);
		return;
	}
	printf("\n");


	switch (type)        //Checking the number entered by the user to set the type of task according to the option chosen.
	{
		case 1:
		{
			setType(task, "Personal");
			break;
		}
		case 2:
		{
			setType(task, "School");
			break;
		}
		case 3:
		{
			setType(task, "Work");
			break;
		}
		case 4:
		{
			setType(task, "Home");
			break;
		}
		default:
		{
			printf("\nInvalid value entered.\n\n");
			return;
		}
	}

	printf("Please enter the status of the task:\n");
	printf("1) To Do\t 2) Doing\t 3) Done\n");

	printf("Enter here: ");
	if (scanf_s("%d", &status) != 1)
	{
		printf("You have entered an invalid value.\n");
		scanf_s("%s", junkChars, JUNKCHARS);
		return;
	}
	printf("\n");

	switch (status)
	{
		case 1:
		{
			setStatus(task, "To Do");
			break;
		}
		case 2:
		{
			setStatus(task, "Doing");
			break;
		}
		case 3:
		{
			setStatus(task, "Done");
			break;
		}
		default:
		{
			printf("\nInvalid value entered.\n\n");
			return;
		}
	}

	*numberOfTasks += 1;                               //Incrementing the number of tasks to let the program know that a new task has been created.

	printf("The task has been successfully created.\n\n");
}

void deleteTask(PTASK arrayTask[], int* numberOfTasks)
{
	if (*numberOfTasks == 0)											//Checking if there is any task to delete.
	{
		printf("There is no task to delete.\n");
		return;
	}

	char junkChars[JUNKCHARS] = { '\0' };

	int NtaskToDelete;

	printf("Please enter the number of the task you want to delete: ");

	if (scanf_s("%d", &NtaskToDelete) != 1)
	{
		printf("You have entered an invalid value.\n");
		scanf_s("%s", junkChars, JUNKCHARS);
		return;
	}
	printf("\n");

	if (taskExists(*numberOfTasks, NtaskToDelete) == false)             //Checking if the task that the user wants to delete exists.     
	{
		return;
	}

	for (int i = NtaskToDelete; i < *numberOfTasks; ++i)                //Loop used to move one position down every task that is after the task deleted.
	{
		//Changing the position of the tasks by moving their status, title and type one position down in the array.
		setStatus(arrayTask[i - 1], getStatus(arrayTask[i]));           
		setTitle(arrayTask[i - 1], getTitle(arrayTask[i]));             
		setType(arrayTask[i - 1], getType(arrayTask[i]));              

		//Cleaning the original position of the task since it has been moved one place down.
		setStatus(arrayTask[i], "");
		setTitle(arrayTask[i], "");
		setType(arrayTask[i], "");
	}

	*numberOfTasks -= 1;                                                //Subtracting one from the number of tasks to let the program know that a task has been deleted.

	printf("The task has been successfully deleted.\n");

	return;

}

void updateTask(PTASK arrayTask[], int numberOfTasks)
{
	if (numberOfTasks == 0)                                             //Checking if there is any task to update.
	{
		printf("There is no task to update.\n");
		return;
	}

	char junkChars[JUNKCHARS] = { '\0' };

	int taskToUpdate = 0;
	int input = 0;

	printf("Please enter the number of the task you want to update: ");

	if (scanf_s("%d", &taskToUpdate) != 1)
	{
		printf("You have entered an invalid value.\n");
		scanf_s("%s", junkChars, JUNKCHARS);
		return;
	}
	printf("\n");

	if (taskExists(numberOfTasks, taskToUpdate) == false)               //Checking if the task that the user wants to update exists.
	{
		return;
	}

	printf("What do you want to update from the task?\n");
	printf("1) Status.\n");
	printf("2) Type.\n\n");
	printf("Enter here: ");
	scanf_s("%d", &input);
	printf("\n");

	switch (input)                                                      //Checking which option the user chose to know which function should be executed.
	{
	case 1:
	{
		updateStatus(arrayTask, taskToUpdate);
		break;
	}
	case 2:
	{
		updateType(arrayTask, taskToUpdate);
		break;
	}
	default:
	{
		printf("You have entered an invalid value.\n\n");
		return;
	}
	}
}

void updateStatus(PTASK tasks[], int taskToUpdate)
{
	int status = 0;
	char junkChars[JUNKCHARS];
	printf("Please enter the new status for the task:\n");

	printf("1) To Do\n2) Doing\n3) Done\n");

	printf("Enter here: ");
	if (scanf_s("%d", &status) != 1)
	{
		printf("You have entered an invalid value.\n");
		scanf_s("%s", junkChars, JUNKCHARS);
		return;
	}
	printf("\n");

	switch (status)
	{
		case 1:
		{
			setStatus(tasks[taskToUpdate - 1], "To Do");
			break;
		}
		case 2:
		{
			setStatus(tasks[taskToUpdate - 1], "Doing");
			break;
		}
		case 3:
		{
			setStatus(tasks[taskToUpdate - 1], "Done");
			break;
		}
		default:
		{
			printf("\nYou have entered an invalid value.\n\n");
			return;
		}
	}

	printf("The task has been successfully updated.\n\n");
}

void updateType(PTASK tasks[], int taskToUpdate)
{
	int type = 0;
	char junkChars[JUNKCHARS];
	printf("Please enter the type of the task\n");
	printf("1) Personal\n2) School\n3) Work\n4) Home\n");

	printf("Enter here: ");
	if (scanf_s("%d", &type) != 1)
	{
		printf("You have entered an invalid value.\n");
		scanf_s("%s", junkChars, JUNKCHARS);
		return;
	}
	printf("\n");

	switch (type)                                                       //Checking the option that the user chose to change the type based on that.
	{
	case 1:
		{
			setType(tasks[taskToUpdate - 1], "Personal");
			break;
		}
	case 2: 
		{
			setType(tasks[taskToUpdate - 1], "School");
			break;
		}
	case 3:
		{
			setType(tasks[taskToUpdate - 1], "Work");
			break;
		}
	case 4:
		{
			setType(tasks[taskToUpdate - 1], "Home");
			break;
		}
	default:
	{
		printf("You have entered an invalid value.\n\n");
		return;
	}
	}
	printf("The task has been succesfully updated.\n\n");
}

void printTask(PTASK task)
{
	printf("\nTask #%d.\nTitle: %s\nType: %s\nStatus: %s\n", getTaskNumber(task) ,getTitle(task), getType(task), getStatus(task));
}

void printSingleTask(PTASK arrayTasks[], int numberOfTasks)
{
	if (numberOfTasks == 0)                                 //Checking if there is any task to print.
	{
		printf("There is no task to show.\n");
		return;
	}

	char junkChars[JUNKCHARS] = { '\0' };

	int task = 0;

	printf("Please enter the number of the task you want to see: ");

	if (scanf_s("%d", &task) != 1)
	{
		printf("You have entered an invalid value.\n");
		scanf_s("%s", junkChars, JUNKCHARS);
		return;
	}
	printf("\n");

	if (taskExists(numberOfTasks, task) == false)          //Checking if the task that the user wants to print exists or not.
	{
		return;
	}

	printf("\nTask #%d.\nTitle: %s\nType: %s\nStatus: %s\n", getTaskNumber(arrayTasks[task - 1]), getTitle(arrayTasks[task - 1]), getType(arrayTasks[task - 1]), getStatus(arrayTasks[task - 1]));
}

void printRangeTask(PTASK arrayTasks[], int numberOfTasks)
{
	if (numberOfTasks == 0)                                //Checking if there are any task to print.
	{
		printf("There is no task to show.\n");
		return;
	}

	char junkChars[JUNKCHARS] = { '\0' };

	int option = 0;

	printf("Please enter the range of the task you want to see:\n");
	printf("1) To Do\t 2) Doing\t 3) Done\t 4) Personal\t 5) School\t 6) Work\t 7) Home\n");
	printf("Enter here: ");
	if (scanf_s("%d", &option) != 1)
	{
		printf("You have entered an invalid value.\n");
		scanf_s("%s", junkChars, JUNKCHARS);
		return;
	}
	printf("\n");

	switch (option)         //Checking which option did the user choose to print a group of tasks based on that.
	{
		case 1:
		{
			printToDoTasks(arrayTasks, numberOfTasks);
			break;
		}
		case 2:
		{
			printDoingTasks(arrayTasks, numberOfTasks);
			break;
		}
		case 3:
		{
			printDoneTasks(arrayTasks, numberOfTasks);
			break;
		}
		case 4:
		{
			printPersonalTasks(arrayTasks, numberOfTasks);
			break;
		}
		case 5:
		{
			printSchoolTasks(arrayTasks, numberOfTasks);
			break;
		}
		case 6:
		{
			printWorkTasks(arrayTasks, numberOfTasks);
			break;
		}
		case 7:
		{
			printHomeTasks(arrayTasks, numberOfTasks);
			break;
		}
		default:
		{
			printf("You have entered an invalid value.\n\n");
			return;
		}
	}
}

void printToDoTasks(PTASK arrayTasks[], int numberOfTasks)
{
	int k = 0;
	for (int i = 0; i < numberOfTasks; i++)
	{
		if (strcmp(getStatus(arrayTasks[i]), "To Do") == 0)
		{
			printTask(arrayTasks[i]);
			k++;
		}
	}

	if (k == 0)
	{
		printf("There are no tasks of this status to print.\n\n");
	}
}

void printDoingTasks(PTASK arrayTasks[], int numberOfTasks)
{
	int k = 0;
	for (int i = 0; i < numberOfTasks; i++)
	{
		if (strcmp(getStatus(arrayTasks[i]), "Doing") == 0)
		{
			printTask(arrayTasks[i]);
			k++;
		}
	}

	if (k == 0)
	{
		printf("There are no tasks of this status to print.\n\n");
	}
}

void printDoneTasks(PTASK arrayTasks[], int numberOfTasks)
{
	int k = 0;
	for (int i = 0; i < numberOfTasks; i++)
	{
		if (strcmp(getStatus(arrayTasks[i]), "Done") == 0)
		{
			printTask(arrayTasks[i]);
			k++;
		}
	}

	if (k == 0)
	{
		printf("There are no tasks of this status to print.\n\n");
	}
}

void printPersonalTasks(PTASK arrayTasks[], int numberOfTasks)
{
	int k = 0;
	for (int i = 0; i < numberOfTasks; i++)
	{
		if (strcmp(getType(arrayTasks[i]), "Personal") == 0)
		{
			printTask(arrayTasks[i]);
			k++;
		}
	}

	if (k == 0)
	{
		printf("There are no tasks of this type to print.\n\n");
	}
}

void printSchoolTasks(PTASK arrayTasks[], int numberOfTasks)
{
	int k = 0;
	for (int i = 0; i < numberOfTasks; i++)
	{
		if (strcmp(getType(arrayTasks[i]), "School") == 0)
		{
			printTask(arrayTasks[i]);
			k++;
		}
	}

	if (k == 0)
	{
		printf("There are no tasks of this type to print.\n\n");
	}
}

void printWorkTasks(PTASK arrayTasks[], int numberOfTasks)
{
	int k = 0;
	for (int i = 0; i < numberOfTasks; i++)
	{
		if (strcmp(getType(arrayTasks[i]), "Work") == 0)
		{
			printTask(arrayTasks[i]);
			k++;
		}
	}

	if (k == 0)
	{
		printf("There are no tasks of this type to print.\n\n");
	}
}

void printHomeTasks(PTASK arrayTasks[], int numberOfTasks)
{
	int k = 0;
	for (int i = 0; i < numberOfTasks; i++)
	{
		if (strcmp(getType(arrayTasks[i]),"Home") == 0)
		{
			printTask(arrayTasks[i]);
			k++;
		}
	}

	if (k == 0)
	{
		printf("There are no tasks of this type to print.\n\n");
	}
}



void searchForTask(PTASK task[], int* numberTasks)
{
	int input = 0;
	int taskNumber = 0;
	char junkChars[JUNKCHARS];

	if (*numberTasks == 0)                                         //Checking if there is any task to search.
	{
		printf("There is no task to search.\n\n");
		return;
	}

	printf("Please enter the number of the task: ");
	if (scanf_s("%d", &taskNumber) != 1)
	{
		printf("You have entered an invalid value.\n");
		scanf_s("%s", junkChars, JUNKCHARS);
		return;
	}

	if (taskNumber > NUMBEROFTASKS || taskNumber <= 0)
	{
		printf("Invalid number entered.\n\n");
		return;
	}

	if (taskExists(*numberTasks, taskNumber) == false)			  //Checking if the task that the user wants to search exists or not.
	{
		return;
	}

	printTask(task[taskNumber - 1]);                              //Showing the task that the user searched.

	printf("\nWhat do you want to do with this task?\n");
	printf("1) Delete task.\n");
	printf("2) Update task.\n");
	printf("3) Exit.\n");
	printf("Enter which option you want: ");
	if (scanf_s("%d", &input) != 1)
	{
		printf("You have entered an invalid value.\n");
		scanf_s("%s", junkChars, JUNKCHARS);
		return;
	}
	printf("\n");

	switch (input)
	{
	case 1:
		//For the delete option the same code as the function "deleteTask" was used,
		//The reason why we don't just call the function is because "deleteTask" ask for input and in this function input was already asked, so it would ask for input twice.
		for (int i = taskNumber; i < *numberTasks; ++i)
		{
			setStatus(task[i - 1], getStatus(task[i]));
			setTitle(task[i - 1], getTitle(task[i]));
			setType(task[i - 1], getType(task[i]));

			setStatus(task[i], "");
			setTitle(task[i], "");
			setType(task[i], "");
		}

		*numberTasks -= 1;

		printf("The task has been successfully deleted.\n");
		break;
	case 2:
	{
		//As well as the delete option, the update option basically uses the same code as the "updateTask" function.
		//Also the reason why is the same.
		printf("What do you want to update from the task?\n");
		printf("1) Status.\n");
		printf("2) Type.\n");
		printf("Enter here the number of the option that you want to choose: ");
		scanf_s("%d", &input);
		printf("\n");

		switch (input)
		{
		case 1:
		{
			updateStatus(task, taskNumber);
			break;
		}
		case 2:
		{
			updateType(task, taskNumber);
			break;
		}
		default:
		{
			printf("Invalid value entered.\n\n");
			break;
		}
		}

		break;
	}
	case 3:
	{
		break;
	}
	default:
	{
		printf("Invalid number.\n\n");
		break;
	}
	}
}

void printAllTasks(PTASK tasks[], int numberTasks)
{
	int i = 0;
	if (numberTasks == 0)                                      //Checking if there are any tasks to print.
	{
		printf("There no tasks to print.\n\n");
	}
	else
	{
		while (i < numberTasks)                                //Using a loop to print every task created one by one.
		{
			printTask(tasks[i]);
			i++;
		}
		printf("\n");
	}
}

bool saveTasks(PTASK tasks[], int numberTasks)
{
	FILE* fp;
	int i = 0;

	if ((fp = fopen("Tasks.txt", "w+")) == NULL)                  //Opening the file and using "w+" in order to avoid deleting what was previously saved in the file.
		return false;

	fprintf(fp, "%d\n", numberTasks);                             //Saving the number of tasks in the file.
	for (i = 0; i < numberTasks; i++)
	{
		fprintf(fp, "%d\n%s\n%s\n%s\n", getTaskNumber(tasks[i]), getTitle(tasks[i]), getType(tasks[i]), getStatus(tasks[i]));        //Printing every specification of each task created in the file.
	}
	fclose(fp);                                                   //Closing the file after it was all saved.

	return true;
}

bool loadTasks(PTASK tasks[], int* numberTasks)
{
	FILE* fp;
	int i = 0;

	if ((fp = fopen("Tasks.txt", "r")) == NULL)                 //Opening the file to read what was saved in it.
		return false;

	int numberTasks_L = 0;
	fscanf(fp, "%d\n", &numberTasks_L);                        //Scanning first the number of tasks.
	*numberTasks = numberTasks_L;                              //Loading the number of tasks.
	for (i = 0; i < numberTasks_L; i++)                        //Loop used to load every task that was previously saved.
	{
		char titleBuffer[MAX_BUFFER];
		char typeBuffer[MAX_BUFFER];
		char statusBuffer[MAX_BUFFER];
		int taskNumber;

		fscanf(fp, "%d\n", &taskNumber);                      //Scanning the number of task.
		//Getting every specifiation of the task from the file.
		fgets(titleBuffer, MAX_BUFFER, fp);                   
		fgets(typeBuffer, MAX_BUFFER, fp);
		fgets(statusBuffer, MAX_BUFFER, fp);

		//Changing every '\n' to a '\0' in the strings.
		RemoveBadChars(titleBuffer);
		RemoveBadChars(typeBuffer);
		RemoveBadChars(statusBuffer);

		//Setting every specification to the respective task.
		setTaskNumber(tasks[i], taskNumber);
		setTitle(tasks[i], titleBuffer);
		setType(tasks[i], typeBuffer);
		setStatus(tasks[i], statusBuffer);
	}
}

bool RemoveBadChars(char* input)
{
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == '\n')
			input[i] = '\0';
	}

	return true;
}

bool taskExists(int numberOfTasks, int taskNumber)
{
	if (taskNumber > numberOfTasks)
	{
		printf("This task does not exist.\n\n");
		return false;
	}

	return true;
}


void setTaskNumber(PTASK t, int taskNumber)
{
	t->taskNumber = taskNumber;
}

void setStatus(PTASK t, char status[])
{
	strncpy_s(t->status, LENGTHSTATUS, status, LENGTHSTATUS);
}

void setTitle(PTASK t, char title[])
{
	strncpy_s(t->title, LENGTHTITLE, title, LENGTHTITLE);
}

void setType(PTASK t, char type[])
{
	strncpy_s(t->type, LENGTHTYPE, type, LENGTHTYPE);
}

int getTaskNumber(PTASK t)
{
	return t->taskNumber;
}

char* getStatus(PTASK t)
{
	return t->status;
}

char* getTitle(PTASK t)
{
	return t->title;
}

char* getType(PTASK t)
{
	return t->type;
}