#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    char *youbi[] = {"monday",
                     "tuesday",
                     "wedenesday",
                     "thursday",
                     "friday",
                     "saturday",
                     "sunday",
                     NULL};
    int i;

    for(i = 0; youbi[i] != NULL; i++){
        printf("第%d曜日は%s\n", i + 1, youbi[i]);
    }
    return 0;
}