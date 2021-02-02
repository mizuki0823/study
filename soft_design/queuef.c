#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "queue.h"

MyQueue *allocQ(int capacity){
    MyQueue *q = malloc(sizeof(MyQueue));
    q->size=0;
    q->front=0;
    q->rear=0;
    q->capacity = capacity;
    q->innerQueue = malloc(sizeof(int)*q->capacity);
    return q;
}

void freeQ(MyQueue *q){
    free(q->innerQueue);
    free(q);
}

void printQ(MyQueue *q){
    int i;

    for(i=0; i<=q->size; i++){
        printf("%d ", q->innerQueue[(q->front + i ) % q->capacity]);
    }
    printf("\n");

}

int enqueueQ(MyQueue *q, int value){

    if(q->size == q->capacity){
        printf("満杯です\n");
        return -1;
    }

    q->innerQueue[q->rear] = value;
    q->size++;
    q->rear++;
    if(q->rear >= q->capacity){
        q->rear=0;
    }
}

int dequeueQ(MyQueue *q){

    if(q->size <= 0){
        printf("空です\n");
        return -1;
    }

    q->size--;
    q->front--;
    if(q->front >= q->capacity){
        q->front=0;
    }
    return q->innerQueue[q->front+1];
}

int peekQ(MyQueue *q){
    if(q->size <= 0){
        return -1;
    }
    return q->innerQueue[q->front];

}