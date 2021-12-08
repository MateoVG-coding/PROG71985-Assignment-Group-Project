//PROG71985- Group project (Task1)
//Mateo Vega & Jose Ibanez - December 2021

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LENGTHSIZE 10
#define LENGTHDESCRIPTION 40
#define NUMBEROFTASKS 30

typedef struct task
{
	int taskNumber;
	char status[LENGTHSIZE];
	char description[LENGTHDESCRIPTION];

}TASK, * PTASK;

void createArrayTasks(PTASK[]);

void setTaskNumber(PTASK, int);

void setStatus(PTASK, char[]);

void setDescription(PTASK, char[]);