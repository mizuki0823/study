#include <stdio.h>
#include <string.h>
#include <math.h>

// #define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

void max(FILE*, FILE*);

int main () {
    FILE *input = fopen("numbers.txt", "r");
    FILE *output = fopen("numbers_max.txt", "w");
    printf("%p, %p\n", input, output);
    max(input, output);
    fclose(input);
    fclose(output);

    return 0;
}

void max(FILE *FIN, FILE *FOUT){
    int v;

    fscanf(FIN, "%d", &v);
    int max = v;

    while(fscanf(FIN, "%d", &v) != EOF){
        if(v>max){
            max=v;
        }
    }

    fprintf(FOUT, "%d", max);

}