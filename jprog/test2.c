#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main (int argc, char **argv) {
    int i;
    for(i=0; i<argc; i++){
        if(argv[i] == NULL)printf("null\n");
        printf("%d %d\n", i, strlen(argv[i]));
    }
    return 0;
}