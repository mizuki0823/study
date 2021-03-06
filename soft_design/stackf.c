#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "stack.h"

MyStack* allocS(int capacity){

    MyStack *s = malloc(sizeof(MyStack));
    s->size=0;
    s->capacity = capacity;
    s->innerStack = malloc(sizeof(int)*s->capacity);
    return s;
}

void freeS(MyStack *s){
    free(s->innerStack);
    free(s);
}

void printS(MyStack *s){
    int i;

    for(i=0; i<s->size; i++){
        printf("%d ", s->innerStack[i]);
    }
    printf("\n");
}

int pushS(MyStack *s, int value){
    int cp, cp2, i;

    if(s->size == s->capacity){
        printf("満杯です\n");
        return -1;
    }

    s->innerStack[s->size] = value;
    s->size++;
    
}

int popS(MyStack *s){

    if(s->size <=0){
        return -1;
    }
    s->size--;

    return s->innerStack[s->size];//配列は０から始まるので-された後の値が出したい値になる

}

int peekS(MyStack *s){
    if(s->size <= 0){
        return -1;
    }
    return s->innerStack[s->size-1];

}