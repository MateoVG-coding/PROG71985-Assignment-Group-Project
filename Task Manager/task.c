//PROG71985- Group project (Task1)
//Mateo Vega & Jose Ibanez - December 2021

#include "task.h"

void createArrayTasks(PTASK tasks[])
{
	for (int i = 0; i < NUMBEROFTASKS; i++)
	{
		tasks[i] = (PTASK)malloc(sizeof(TASK));
		setTaskNumber(tasks[i], i + 1);
	}
}

void addNewTask(PTASK task, int* numberOfTasks)
{
	char junkChars[JUNKCHARS] = { '\0' };
	char title[LENGTHTITLE] = { '\0' };
	int status = 0;
	int type = 0;

	printf("Please enter the task you want to add:\n");

	if (scanf_s("%s", title, LENGTHTITLE) != 1)
	{
		printf("You have entered an invalid value.\n");
		scanf_s("%s", junkChars, JUNKCHARS);
		return;
	}

	setTitle(task, title);


	printf("Please enter the type of the task\n");
	printf("1) Personal\t 2) School\t 3) Work\t 4) Home\n");

	if (scanf_s("%d", &type) != 1)
	{
		printf("You have entered an invalid value.\n");
		scanf_s("%s", junkChars, JUNKCHARS);
		return;

	}
	else if (type > 4 || type < 0)
	{
		printf("You have entered an invalid value.\n");
		return;
	}


	if (type == 1)
	{
		setType(task, "Personal");
	}
	else if (type == 2)
	{
		setType(task, "School");
	}
	else if (type == 3)
	{
		setType(task, "Work");
	}
	else if (type == 4)
	{
		setType(task, "Home");
	}


	printf("Please enter the status of the task:\n");
	printf("1) To Do\t 2) Doing\t 3) Done\n");

	if (scanf_s("%d", &status) != 1)
	{
		printf("You have entered an invalid value.\n");
		scanf_s("%s", junkChars, JUNKCHARS);
		return;

	}
	else if (status > 3 || status < 0)
	{
		printf("You have entered an invalid value.\n");
		return;
	}


	if (status == 1)
	{
		setStatus(task, "To Do");
	}
	else if (status == 2)
	{
		setStatus(task, "Doing");
	}
	else if (status == 3)
	{
		setStatus(task, "Done");
	}

	*numberOfTasks += 1;

	printf("The task has been successfully created.\n");
}

void deleteTask(PTASK arrayTask[], int* numberOfTasks)
{
	if (*numberOfTasks == 0)
	{
		printf("There is no task to delete.\n");
		return;
	}

	int NtaskToDelete;

	printf("Please enter the number of the task you want to delete:\n");
	scanf_s("%d", &NtaskToDelete);

	if (NtaskToDelete > *numberOfTasks)
	{
		printf("The task does not exist.\n");
		return;
	}

	for (int i = NtaskToDelete; i < *numberOfTasks; ++i)
	{
		setStatus(arrayTask[i - 1], getStatus(arrayTask[i]));
		setTitle(arrayTask[i - 1], getTitle(arrayTask[i]));
		setType(arrayTask[i - 1], getType(arrayTask[i]));

		setStatus(arrayTask[i], "");
		setTitle(arrayTask[i], "");
		setType(arrayTask[i], "");
	}

	*numberOfTasks -= 1;

	printf("The task has been successfully deleted.\n");

	return;

}

void updateTask(PTASK arrayTask[], int numberOfTasks)
{
	if (numberOfTasks == 0)
	{
		printf("There is no task to delete.\n");
		return;
	}

	int taskToUpdate = 0;

	printf("Please enter the number of the task you want to update:\n");

	if (scanf_s("%d", &taskToUpdate) != 1)
	{
		printf("You have entered an invalid value.\n");
		return;
	}

	if (taskToUpdate > numberOfTasks)
	{
		printf("The task does not exist.\n");
		return;
	}


	int status = 0;

	printf("Please enter the new status for the task:\n");

	printf("1) To Do\t 2) Doing\t 3) Done\n");

	if (scanf_s("%d", &status) != 1)
	{
		printf("You have entered an invalid value.\n");
		return;

	}
	else if (status > 3 || status < 0)
	{
		printf("You have entered an invalid value.\n");
		return;
	}

	if (status == 1)
	{
		setStatus(arrayTask[taskToUpdate - 1], "To Do");
	}
	else if (status == 2)
	{
		setStatus(arrayTask[taskToUpdate - 1], "Doing");
	}
	else if (status == 3)
	{
		setStatus(arrayTask[taskToUpdate - 1], "Done");
	}

	printf("The task has been successfully updated.\n");

}

void printTask(PTASK task)
{
	printf("\n%d.\nTask: %s\nType: %s\nStatus: %s\n", getTaskNumber(task) ,getTitle(task), getType(task), getStatus(task));
}


void searchForTask(PTASK task[], int* numberTasks)
{
	int input = 0;
	int taskNumber = 0;
	char junkChars[JUNKCHARS];
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

	if (taskNumber > *numberTasks)
	{
		printf("This task doesn't exist.\n\n");
		return;
	}

	printTask(task[taskNumber - 1]);

	printf("\nWhat do you want to do with this task?\n");
	printf("1) Delete task.\n");
	printf("2) Update task.\n");
	printf("Enter which option you want: ");
	if (scanf_s("%d", &input) != 1)
	{
		printf("You have entered an invalid value.\n");
		scanf_s("%s", junkChars, JUNKCHARS);
		return;
	}

	switch (input)
	{
	case 1:
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
		break;
	default:
	{
		printf("Invalid number.\n\n");
		break;
	}
	}
}

bool saveTasks(PTASK tasks[], int numberTasks)
{
	FILE* fp;
	int i = 0;

	if ((fp = fopen("Tasks.txt", "w+")) == NULL)
		return false;

	fprintf(fp, "%d\n", numberTasks);
	while (i < numberTasks)
	{
		fprintf(fp, "%d\n%s\n%s\n%s\n", getTaskNumber(tasks[i]), getTitle(tasks[i]), getType(tasks[i]), getStatus(tasks[i]));
		i++;
	}
	fclose(fp);

	return true;
}

bool loadTasks(PTASK tasks[], int* numberTasks)
{
	FILE* fp;
	int i = 0;

	if ((fp = fopen("Tasks.txt", "r")) == NULL)
		return false;

	int numberTasks_L = 0;
	fscanf(fp, "%d\n", &numberTasks_L);
	*numberTasks = numberTasks_L;
	for (i = 0; i < numberTasks_L; i++)
	{
		char titleBuffer[MAX_BUFFER];
		char typeBuffer[MAX_BUFFER];
		char statusBuffer[MAX_BUFFER];
		int taskNumber;

		fscanf(fp, "%d\n", &taskNumber);
		fgets(titleBuffer, MAX_BUFFER, fp);
		fgets(typeBuffer, MAX_BUFFER, fp);
		fgets(statusBuffer, MAX_BUFFER, fp);

		RemoveBadChars(titleBuffer);
		RemoveBadChars(typeBuffer);
		RemoveBadChars(statusBuffer);

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