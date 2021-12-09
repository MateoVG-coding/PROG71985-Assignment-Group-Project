//PROG71985- Group project (Task1)
//Mateo Vega & Jose Ibanez - December 2021

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LENGTHSTATUS 10
#define LENGTHTITLE 40
#define LENGTHTYPE 10
#define NUMBEROFTASKS 100
#define JUNKCHARS 256

typedef struct task
{
	int taskNumber;
	char status[LENGTHSTATUS];
	char title[LENGTHTITLE];
	char type[LENGTHTYPE];

}TASK, * PTASK;

void createArrayTasks(PTASK[]);

void addNewTask(PTASK, int);
void printTask(PTASK);

void setTaskNumber(PTASK, int);
void setStatus(PTASK, int);
void setType(PTASK, int);
void setTitle(PTASK, char[]);
int getTaskNumber(TASK);
char* getStatus(TASK);
char* getTitle(TASK);
char* getType(TASK);