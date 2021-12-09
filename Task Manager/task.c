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
	char junkChars[JUNKCHARS];
	char title[LENGTHTITLE];
	int status;
	int type;

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
	printf("1) To Dol\t 2) Doing\t 3) Done\n");

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

void printTask(TASK task)
{
	printf("%d.\nTask: %s\nType: %s\nStatus: %s\n", getTaskNumber(task) ,getTitle(task), getType(task), getStatus(task));
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

int getTaskNumber(TASK t)
{
	return t.taskNumber;
}

char* getStatus(TASK t)
{
	return t.status;
}

char* getTitle(TASK t)
{
	return t.title;
}

char* getType(TASK t)
{
	return t.type;
}