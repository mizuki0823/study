#include <stdio.h>
#include <string.h>

int a[4], *least, *most;


int main () {
    for(int i = 0; i < 5; i++){
        scanf("%d", (a + i));
    }

    if(a[0] < a[1]){
        least = a;
        most = a + 1;
    }

    else
    {
        least = a + 1;
        most = a;
    }
    

    for(int j = 2; j < 5; j++){
        if(a[j] < *least){
            least = a + j;
        }

        else if(a[j] > *most){
            most = a + j;
        }

    }
    printf("最大値：%d\n最小値：%d\n", *most, *least);
    return 0;
}