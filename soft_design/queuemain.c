#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

#include "queue.h"
#include "queuef.c"

int main () {
    MyQueue *q= allocS(3);

    //enqueue test
    printQ(q);
    enqueueQ(q,1);
    printQ(q);
    enqueueQ(q, 2);
    printQ(q);

    //dequeue test
    printf("dequeue: %d\n", 1);
    dequeueQ(q);
    printQ(q);

    return 0;
}