#ifndef MY_STACK_H
#define MY_STACK_H

typedef struct 
{
    int *innerStack;
    int size;
    int capacity;
} MyStack;

MyStack *allocS(int);
void freeS(MyStack);
void printS(MyStack);
int pushS(MyStack, int);
int popS(MyStack);
int peekA(MyStack);


#endif