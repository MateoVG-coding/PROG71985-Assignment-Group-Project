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
#define NUMBEROFTASKS 200

typedef struct task
{
	char status[LENGTHSTATUS];
	char title[LENGTHTITLE];
	char type[LENGTHTYPE];

}TASK, * PTASK;

void createArrayTasks(PTASK[]);

void addNewTask(PTASK);

void setStatus(PTASK, int);
void setType(PTASK, int);
void setTitle(PTASK, char[]);
char* getStatus(TASK);
char* getTitle(TASK);
char* getType(TASK);
