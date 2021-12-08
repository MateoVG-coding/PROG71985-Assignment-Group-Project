//PROG71985- Group project (Task1)
//Mateo Vega & Jose Ibanez - December 2021

#pragma once

#include <stdio.h>
#include <stdbool.h>

#define LENGTHSIZE 10
#define LENGTHDESCRIPTION 40

typedef struct task
{
	int taskNumber;
	char status[LENGTHSIZE];
	char description[LENGTHDESCRIPTION];

}TASK, * PTASK;
