#ifndef MY_QUEUE_H
#define MY_QUEUE_H

typedef struct 
{
    int *innerQueue;
    int front, rear;
    int size;
    int capacity;
} MyQueue;

MyQueue *allocQ(int);
void freeQ(MyQueue*);
void printQ(MyQueue*);
int enqueueQ(MyQueue*, int);
int dequeueQ(MyQueue*);
int peekQ(MyQueue*);

#endif

