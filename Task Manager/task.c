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

void addNewTask(PTASK task, int numberOfTask)
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

	setTitle(task, title);
	setType(task, type);
	setStatus(task, status);
}

void printTask(PTASK task)
{
	printf("\nTask #%d.\nTask: %s\nType: %s\nStatus: %s\n\n", getTaskNumber(task) ,getTitle(task), getType(task), getStatus(task));
}

void searchForTask(PTASK task[], int numberTasks)
{
	int input = 0;
	int taskNumber = 0;
	char junkChars[JUNKCHARS];
	printf("Please enter the number of the task: ");
	if (scanf_s("%d", &taskNumber) != 1)
	{
		printf("You have entered an invalid value.\n");
		scanf_s("%s", junkChars, JUNKCHARS);
		return 1;
	}

	if (taskNumber > NUMBEROFTASKS || taskNumber <= 0)
	{
		printf("Invalid number entered.\n\n");
		return 1;
	}

	if (taskNumber > numberTasks)
	{
		printf("This task doesn't exist.\n\n");
		return 1;
	}

	printTask(task[taskNumber - 1]);

	printf("What do you want to do with this task?\n");
	printf("1) Delete task.\n");
	printf("2) Update task.\n");
	printf("Enter which option you want: ");
	if (scanf_s("%d", &input) != 1)
	{
		printf("You have entered an invalid value.\n");
		scanf_s("%s", junkChars, JUNKCHARS);
		return 1;
	}

	switch (input)
	{
		case 1:
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



void setTaskNumber(PTASK t, int taskNumber)
{
	t->taskNumber = taskNumber;
}

void setStatus(PTASK t, int status)
{
	if (status == 1)
	{
		strncpy_s(t->status, LENGTHSTATUS, "To Do", LENGTHSTATUS);
	}
	else if (status == 2)
	{
		strncpy_s(t->status, LENGTHSTATUS, "Doing", LENGTHSTATUS);
	}
	else
	{
		strncpy_s(t->status, LENGTHSTATUS, "Done", LENGTHSTATUS);
	}
}

void setTitle(PTASK t, char title[])
{
	strncpy_s(t->title, LENGTHTITLE, title, LENGTHTITLE);
}

void setType(PTASK t, int type)
{
	if (type == 1)
	{
		strncpy_s(t->type, LENGTHTYPE, "Personal" , LENGTHTYPE);
	}
	else if (type == 2)
	{
		strncpy_s(t->type, LENGTHTYPE, "School", LENGTHTYPE);
	}
	else if (type == 3)
	{
		strncpy_s(t->type, LENGTHTYPE, "Work", LENGTHTYPE);
	}
	else
	{
		strncpy_s(t->type, LENGTHTYPE, "Home", LENGTHTYPE);
	}
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