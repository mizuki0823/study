#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

void ryaku(char **);

int main () {
    char *youbi[] = {"monday",
                     "tuesday",
                     "wedenesday",
                     "thursday",
                     "friday",
                     "saturday",
                     "sunday",
                     NULL};
    ryaku(youbi);
    return 0;
}

void ryaku(char **p_youbi){
    int i, j;

    for(i = 0; p_youbi[i]; i++){
        for(j = 0; j < 3; j++)
            printf("%c", p_youbi[i][j]);
        printf("は%sの略です。\n", p_youbi[i]);
    }
}