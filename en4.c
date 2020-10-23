#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    char code[30], name[30];
    int price;
    FILE * fp;

    if((fp = fopen("s_mast.dat", "w+")) == NULL){
        printf("Error: ファイルを開けませんでした");
      return 1;
    }

    while(scanf("%s %s %d", code, name, &price) != EOF){
        fprintf(fp,"%s %s %d\n", code, name, price );
    }

    rewind(fp);


    printf("商品コード 商品名 単価\n");
    
    while(fscanf(fp,"%s %s %d", code, name, &price) != EOF){
      printf("%s %s %d\n", code, name, price);
    }

     if (fclose(fp) == EOF ) {
      printf("Error: ファイルを閉じれませんでした");
      return 1;
   }


    return 0;
}

