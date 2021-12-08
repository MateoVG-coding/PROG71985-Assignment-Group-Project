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

void setTaskNumber(PTASK t, int taskNumber)
{
	t->taskNumber = taskNumber;
}

void setStatus(PTASK t, char status[])
{
	strncpy_s(t->status, LENGTHSIZE, status, LENGTHSIZE);
}

void setDescription(PTASK t, char description[])
{
	strncpy_s(t->description, LENGTHDESCRIPTION, description, LENGTHDESCRIPTION);
}

int getTaskNumber(TASK t)
{
	return (t.taskNumber);
}

char* getStatus(TASK t)
{
	return (t.status);
}

char* getDescription(TASK t)
{
	return (t.description);
}