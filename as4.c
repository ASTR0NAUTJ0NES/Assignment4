/*
Purpose: To print out number of passengers and when they arrived and at what time

Assumption: What domain of data you are restricting

Input: files passed in

Output: formatted strings which contains calculations

Algorithm: using a queue structure

Programmer: Andrew Peyton Albanese
*/

#include <stdio.h>
#include "queue.h"

typedef struct arrival_struct {
    int time;       // time of arrival
    int count;      // number of passengers/seats arriving
} itemtype;

// function prototypes
void passenger(node **headptr, node **tailptr, itemtype *arrival);
double bus(node **headptr, node **tailptr, itemtype *arrival);

int main(void) {
	node *head = NULL, *tail = NULL;
	itemtype item;
	int totalPassengers = 0;
	double returnTime = 0.0;
	int code;

	while (scanf("%d", &code) != EOF) {
		if (code == 0) {
			scanf("%d", &item.time);
			scanf("%d", &item.count);
			totalPassengers += item.count;
			passenger(&head, &tail, &item);
		}else {
			scanf("%d", &item.time);
			scanf("%d", &item.count);
			returnTime += bus(&head,&tail,&item);
			returnTime -= item.time;
		} // if else
	} // while
	printf("\nTotal %i persons waited for %.0lf minutes, the average time %.2lf\n", totalPassengers, returnTime, returnTime/(double)totalPassengers );
	return 0;
} // main

void passenger(node **headptr, node **tailptr, itemtype *arrival) {
	int x = 0;
	printf("%d persons arrived at time %d\n", arrival->count, arrival->time);
	for (x = 0; x < arrival->count; x++) {
		enqueue(headptr, tailptr, arrival->time);
	} // for
} // passenger

double bus(node **headptr, node **tailptr, itemtype *arrival) {
	int x = 0;
	double totTime = 0.0;
	printf("bus arrived at time %d with %d seats available\n", arrival->time, arrival->count);
	for (x = 0; x < arrival->count; x++) {
		totTime += dequeue(headptr, tailptr); 
	} // for
	return totTime;
} // bus