/*
 * queue.h
 *
 *  Created on: 05.08.2018
 *      Author: fliess
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "stdlib.h"
#include "stdio.h"

typedef struct {
    float *items;
    int maxsize;
    int head;
    int tail;
    volatile int size;
    volatile int offset;
    volatile int remains;
} Queue;

Queue *newQueue(int size);

int size(Queue *pt);

int isEmpty(Queue *pt);

void enqueue(Queue *pt, float v);

float dequeue(Queue *pt);

float next(Queue *pt);

char hasNext(Queue *pt);

void resetOffset(Queue *pt);

#endif /* QUEUE_H_ */
