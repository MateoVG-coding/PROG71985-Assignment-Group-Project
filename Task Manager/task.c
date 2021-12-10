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


void printTask(PTASK task)
{
	printf("\n%d.\nTask: %s\nType: %s\nStatus: %s\n", getTaskNumber(task) ,getTitle(task), getType(task), getStatus(task));
}

	*numberOfTasks += 1;

void setTaskNumber(PTASK t, int taskNumber)
{
	t->taskNumber = taskNumber;
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

void printTask(PTASK task)
{
	printf("\n%d.\nTask: %s\nType: %s\nStatus: %s\n", getTaskNumber(task) ,getTitle(task), getType(task), getStatus(task));
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