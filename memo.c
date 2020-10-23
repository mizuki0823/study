#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

void ave();
// 　　　　　^ セミコロンが必要ですあざす

// 今は main 関数一つだけでやっているけど、今のmainに書いている読み込み→出力の一連の処理を、関数 ave を作ってその中に書き写してみましょう
//
/*
int main () {
   // ave 関数に渡す引数も、返ってくる戻り値もないです！！
   //そうだわ 関数つくるのってこんなんだったっけ
   // ですね　ただ、戻り値がないので、dobule ave ではなく void ave ですね
   ave(); // ← main関数はこれだけにしたい main関数の下につくるかんじですよね　忘れてた
   // OKです ただ、プロトタイプ宣言は必要なので忘れずに〜〜
   // 一文字変数だと頭が燃えるので変えましょう
   // https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools　←ここにでてくるコマンドってコマンドパレットじゃなくてターミナルにうつの？
   // discord　にリンク貼った
   // これ入れてみてください　これはなんの機能すか
   // 変数名↓のところで、右クリックしたら、rename symbol ってあるとおもうんだけど、それを使うと、変数の名前の変更が簡単にできる
   // あと、構文とかで問題があったら赤下なみせんで指摘してくれる

   // total も number の一種なので△ですね
   // count とかがいいと思います←かしこい
   double total, ans, read;
   int count; //ってこと？ですですヨシ！💯
   // もう一つ、count は 整数だけでいいね
   // 今はそのままiを出力しているけど、これの平均をとって、printf表示するようにしてみてください
   //読み込んだやつを順にたして最後にiで割ればいいかな
   //シンボルの名前変更ってやつよね　エンター押したら戻っちゃう
   // 多分それだとおもう😭😭😭😭
   // 今日は普通に自力で変えますか……うん。(もうしわけない)いえいえ
   // 今のコードだと、iが読み込んだやつですね　個数で割ればOKです
   //おうこれfor文になる　おう
   // どっちでもいいよ while でも個数は数えられるので、個人の好みです
   // 大丈夫そうなので実行してみましょうか
   // i 初期化してないですね←iって＝０いるのか
   // 確かに、ええと、コンパイラによっては(指定しなかったら)0を入れてくれるものもあったわ()
   // ↓ 多分最初は0じゃないか
   // 1つ入力した後に `++a` するので なる
   //ターミナルうっかり全角でうったから止まったかもしれん
   // 開きなおしますかー←強制終了してだいじょうぶ
   // okたぶんよし

   // よく考えたら total に上書きで読み込んでるのおかしくないですか
   // 1 2 3 だと (3 + 3) / 3 == (1+2+3) / 3  だから良いけど、1 2 で試してみて欲しい 多分 (2+2) / 2 で2 になるとおもう(1+2) / 2 = 1.5 が正しいはずだけど
   // 読み込み用の変数を用意しましょう
   while(scanf("%lf", &read) != EOF){
      total += read;
      count++; // ←ここで1になるべきなはず
      // 今は int なので 切り捨てになっているけど　
      // 小数にも対応していきましょう 試してみよう　せっかくなので doubleって%なんだっけfはfloatだって
      // だっておこ
      // だっておほえー   やさしいなあ おおう

      // コンパイラくんは優しいので %lf じゃない？っていてるみたいだよ
   }
   ans = total / count;
   printf("%lf\n", ans);
}
*/

// というわけで、標準入力/出力ではできたのですが、これをファイルの入出力に変えるのが今回の課題です humu
// ファイルの名前を指定するとかいうわけではなくて、今回は FILE 構造体 が渡されるという課題です
// この構造体のポインタを、fscanf/fprintf 関数とわちゃわちゃすると、ファイルから読み込み/へ書き込みができます
// fscanf を使うとファイルから読み込めるわけですが、どのファイルから読み込むのかを指定するために、ファイル構造体があります
void ave(FILE *FIN, FILE *FOUT){ 
   double total, ans, read;
   int count; 

   // ファイル構造体を最初の引数とする以外は、いつものscanfと同じです
   //この場合のEOFってなに？ほう　なんか１　２　３　ってうってコンパイルすると0.000185になった
   // ファイルを最後まで読み込み終わったらEOF
   // なんでだろう…読み込んだ値をprintfしてみたり、平均をprintfしてみたりして、どこでおかしくなっているのかみてみよう
   count = 0; // これでやってみますか できたやったあmimasuka　まあ余裕持って言ったんでだいじょうぶ　
   
   // 見えた　👏👏👏　6時は少しすぎてしまいましたが() よかった ではまた　ういありがとー👍
   while(fscanf(FIN, "%lf", &read) != EOF){
      printf("read: %lf\n", read);
      // "read: %lf\n"とかの方が見やすいかも
      total += read;
      printf("total: %lf\n", total);
      count++; 
      printf("count: %d\n", count); //countがおかしいな
      
   }

   ans = total / count;
   printf("ans: %lf\n", ans);
   // printf も fprintf に書き換えてみましょう。出力先は、さっき引数に定義した FOUT です
   fprintf(FOUT, "%lf", ans);
}
// これで今回の課題は終了なんですけど、これだと確かめられないので、ファイルの構造体を作ってテストをできるようにしたのが、前にDiscordで送ったやつです
// さっきまでの main 関数はコメントアウトしました
int main(void) {
   FILE *numbers_from;
   FILE *calculated_avegage_dest;

   // numbers.txt というファイルを用意して実行すると、average_of_numbers.txtに平均が書き込まれるはずなのでやってみてください。
   if ((numbers_from = fopen("numbers.txt", "r")) == NULL || (calculated_avegage_dest = fopen("average_of_numbers.txt", "w")) == NULL) {
      printf("Error: could't open file.");
      return 1;
   }

   ave(numbers_from, calculated_avegage_dest);

   if (fclose(numbers_from) == EOF || fclose(calculated_avegage_dest) == EOF) {
      printf("Error: could't open file.");
      return 1;
   }

   return 0;
}