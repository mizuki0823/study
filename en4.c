#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    char code[30], name[30];
    int price;
    FILE * fp;

    if((fp = fopen("s_mast.dat", "w+")) == NULL){   //fileopenテキスト読み書き
        printf("Error: ファイルを開けませんでした");
      return 1;
    }

    while(scanf("%s %s %d", code, name, &price) != EOF){  //コード、商品名、値段書き込み
        fprintf(fp,"%s %s %d\n", code, name, price );
    }

    rewind(fp);//ファイル先頭にもどる


    printf("商品コード 商品名 単価\n");
    
    while(fscanf(fp,"%s %s %d", code, name, &price) != EOF){//fpからファイル読み込み→ターミナルへ出力
      printf("%s %s %d\n", code, name, price);
    }

     if (fclose(fp) == EOF ) {
      printf("Error: ファイルを閉じれませんでした");
      return 1;
   }


    return 0;
}

