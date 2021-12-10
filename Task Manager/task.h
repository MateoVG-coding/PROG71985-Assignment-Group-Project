//PROG71985- Group project (Task1)
//Mateo Vega & Jose Ibanez - December 2021

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LENGTHSTATUS 20
#define LENGTHTITLE 50
#define LENGTHTYPE 20
#define NUMBEROFTASKS 100
#define JUNKCHARS 256
#define MAX_BUFFER 80

typedef struct task
{
	int taskNumber;
	char status[LENGTHSTATUS];
	char title[LENGTHTITLE];
	char type[LENGTHTYPE];

}TASK, * PTASK;

void createArrayTasks(PTASK[]);

void addNewTask(PTASK, int*);
void deleteTask(PTASK[], int*);
void updateTask(PTASK[], int);
void printTask(PTASK);
void printSingleTask(PTASK[], int);
void printRangeTask(PTASK[], int);
void printToDoTasks(PTASK[], int);
void printDoingTasks(PTASK[], int);
void printDoneTasks(PTASK[], int);
void printPersonalTasks(PTASK[], int);
void printSchoolTasks(PTASK[], int);
void printWorkTasks(PTASK[], int);
void printHomeTasks(PTASK[], int);
void printAllTasks(PTASK[], int);
void searchForTask(PTASK[], int*);
bool saveTasks(PTASK[], int);
bool loadTasks(PTASK[], int*);
bool RemoveBadChars(char*);
bool taskExists(int, int);
void updateStatus(PTASK[], int);
void updateType(PTASK[], int);


void setTaskNumber(PTASK, int);
void setStatus(PTASK, char[]);
void setType(PTASK, char[]);
void setTitle(PTASK, char[]);
int getTaskNumber(PTASK);
char* getStatus(PTASK);
char* getTitle(PTASK);
char* getType(PTASK);