//PROG71985- Group project (Task1)
//Mateo Vega & Jose Ibanez - December 2021


#include "task.h"

void createArrayTasks(PTASK tasks[])
{
	for (int i = 0; i < NUMBEROFTASKS; i++)
	{
		tasks[i] = (PTASK)malloc(sizeof(TASK));
	}
}

void addNewTask(PTASK task)
{
	char title[LENGTHTITLE];
	int status = 0;
	int type = 0;

	printf("Please enter the task you want to add:\n");
	scanf_s("%s", title, LENGTHTITLE);

	printf("Please enter the type of the task\n");
	printf("1) Personal\t2) School\t3) Work\t4) Home\n");
	scanf_s("%d", &type);

	printf("Please enter the status of the task:\n");
	printf("1) To Do\t2) Doing\t3) Done\n");
	scanf_s("%d", &status);

	setTitle(task, title);
	setType(task, type);
	setStatus(task, status);

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

void printTask(TASK task)
{
	printf("\nTitle: %s - Type: %s - Status: %s", getTitle(task), getType(task), getStatus(task));
}
