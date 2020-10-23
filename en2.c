#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main (int argc, char *argv[]) {

    int total = 0;
    int *num;

    num = malloc(sizeof(int)*(argc-1));

    for(int i = 1; i < argc; i++){
        num[i] = atoi(argv[i]); 
        total += (num[i]);
    }
    printf("%d\n", total);

    free(num);
    return 0;
}
