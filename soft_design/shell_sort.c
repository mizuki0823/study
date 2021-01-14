#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>
#include <time.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)
#define N 10

void shell_sort(int*, int, int);
void shell_sort2(int*, int, int);
void shell_sort3(int*, int, int);

int main () {
    clock_t start, end;

    int ary[N];
    int i;
    int result;
    int asc =1;
    srand(time(NULL));

    for(i=0; i<N; i++){
        ary[i] = rand() % 10;
    }
    printf("ソート前 ");
    for(i=0; i<N; i++){
        printf("%d ", ary[i]);
    }
    printf("\n");
    printf("ソート後 ");
    start=clock();
    shell_sort(ary, N, asc);
    end=clock();

    for(i=0; i<N; i++){
        printf("%d ", ary[i]);
    }
    printf("\n");

    printf("かかった時間%f\n", (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}

void shell_sort(int *ary, int anum, int asc){
    int h,g,i,j;
    int tmp;

    for(h = anum/2; h>=1; h/=2){
        for(g=0; g<h; g++){

            for(i=g+1; i<=anum-1; i+=h){
                for(j=i; j>=g+h; j-=h){
                    if((asc && ary[j-h]>ary[j]) || (!asc && ary[j-h]<ary[j])){
                        tmp=ary[j-h];
                        ary[j-h]=ary[j];
                        ary[j]=tmp;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
}

void shell_sort2(int *ary, int anum, int asc){
    int h,g,i,j;
    int tmp;

    while (h < anum/10)
    {
        h = (h*2)+1;
    }
    

    for(h = anum/2; h>=1; h=(h-1)/2){
        for(g=0; g<h; g++){

            for(i=g+1; i<=anum-1; i+=h){
                for(j=i; j>=g+h; j-=h){
                    if((asc && ary[j-h]>ary[j]) || (!asc && ary[j-h]<ary[j])){
                        tmp=ary[j-h];
                        ary[j-h]=ary[j];
                        ary[j]=tmp;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
}

void shell_sort3(int *ary, int anum, int asc){
    int h,g,i,j;
    int tmp;

    for(h = (anum-1)/3; h>=1; h=(h-1)/3){
        for(g=0; g<h; g++){

            for(i=g+1; i<=anum-1; i+=h){
                for(j=i; j>=g+h; j-=h){
                    if((asc && ary[j-h]>ary[j]) || (!asc && ary[j-h]<ary[j])){
                        tmp=ary[j-h];
                        ary[j-h]=ary[j];
                        ary[j]=tmp;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
}
