#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

//間違えた問題をやっていこう
//まず１．１ということで
// はーい
//アドレスを出力するやつですね

int main () {

    int a = 10;

    printf("%p\n",a);  //ここのところをaってかいちゃったのよね
    // 「%」 はあくまで「書式指定子」で、「与えられた内容をどう表現するか」を決めるものなので、a ではないっていうのはわかる？
    // aはint型の変数であってポインタじゃないからエラーを吐きそう
    // （そういえばエラーになるかどうかは知らないな…試してみてもいい気がする、せっかくだし。）
    // 実行してみますか　
    // warning == 警告なので実行はできるはず
    // 0xa == 16進数で「a」なので10が出てますね
    // 今の状態だと、
    printf("%p\n", 10);
    // と変わんないからね

    //できるんだ　たしかにポインタじゃなくて中身まんまだね１６進になっただけというか
    // ですね
    
    // 後は A のアドレスはどうやったらわかるのかって話何ですけど、わかる？
    printf("%p\n",&a);//こうかな？
    // 実行してみましょう
    //できた
    // おしまい！
    return 0;
}