#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

void sub_1(int);
void sub_2(int);
char data_1 = 1;

int main () {
    auto int data_2 = 2; 
    static int data_3 = 3;

    sub_1(data_2);
    sub_2(data_3);
    printf("[main] data_1 = %d\n", data_1);
    printf("[main] data_2 = %d\n", data_2);
    printf("[main] data_3 = %d\n", data_3);
       
    return 0;
}

static int data_4 = 4;

void sub_1(int data_5) {
    auto int data_6 = 6;
    printf("[sub_1] data_1 = %d\n", data_1);
    printf("[sub_1] data_4 = %d\n", data_4);
    printf("[sub_1] data_5 = %d\n", data_5);
    printf("[sub_1] data_6 = %d\n", data_6);
} 

void sub_2(int data_7){
    static int data_8 = 8;
    printf("[sub_2] data_1 = %d\n", data_1);
    printf("[sub_2] data_4 = %d\n", data_4);
    printf("[sub_2] data_7 = %d\n", data_7);
    printf("[sub_1] data_8 = %d\n", data_8);
}