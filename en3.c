#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct shop
    {
        int  price;     //値段・合計
        char name[30];  //商品名
    };

int main () {
    
    // int i,total;
    struct shop date[20]; 

    int i = 0;
    int total = 0;
    while((scanf("%s %d", date[i].name, &date[i].price) != EOF) && i < 20) {
        total += date[i].price;
        i++;
    }
    
    printf("商品名      金額\n");
    for(int j=0; j < i; j++){
        printf("%s      %d\n", date[j].name, date[j].price);
    }
    printf("合計        %d\n", total);
    
    return 0;
}