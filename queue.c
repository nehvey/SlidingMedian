/*
 * queue.c
 *
 *  Created on: 05.08.2018
 *      Author: fliess
 */

#include "queue.h"
#include <float.h>

Queue *newQueue(int size) {
    Queue *q = NULL;
    q = (Queue *) malloc(sizeof(Queue));
    q->items = (float *) malloc(size * sizeof(float));
    q->maxsize = size;
    q->head = -1;
    q->tail = -1;
    q->size = 0;
    q->offset = -1;
    q->remains = 0;
    return q;
}

int size(Queue *pt) {
    return pt->size;
}

int isEmpty(Queue *pt) {
    return !size(pt);
}

void enqueue(Queue *pt, float v) {
    if (pt->size == pt->maxsize) {
        dequeue(pt);
    }

    pt->tail = (pt->tail + 1) % pt->maxsize;
    pt->items[pt->tail] = v;
    pt->size++;
}

float dequeue(Queue *pt) {
    pt->head = (pt->head + 1) % pt->maxsize;
    pt->size--;
    return pt->items[pt->head];
}

float next(Queue *pt) {
    pt->remains--;
    pt->offset = (pt->offset + 1) % pt->maxsize;
    return pt->items[pt->offset];
}

char hasNext(Queue *pt) {
    return pt->remains > 0;
}

void resetOffset(Queue *pt) {
    pt->remains = pt->size;
    pt->offset = pt->head;
}
