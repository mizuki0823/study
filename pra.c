#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)
#define ADD(x) (x + 2)

int main () {
  char moji_b, mask_b = 0x20;

  printf("英文字１字入力 ");
  scanf("%c", &moji_b);
  // 変換って何やるの ビット演算だっけ
  // ググったら出てきた https://www.google.com/search?q=c+%E5%A4%A7%E6%96%87%E5%AD%97+%E5%B0%8F%E6%96%87%E5%AD%97+%E5%A4%89%E6%8F%9B+%E3%83%93%E3%83%83%E3%83%88%E6%BC%94%E7%AE%97
  // で、
  // 全然関係ないんだけど、インデントは2と4のどっち派ですか
  // 3 なのでとても気になってしまう　初めて考えたけど２じゃないかな
  //大先生からもらったshortcutって多分最初３ではじまるきがする←４だったわ
  // shortcut ってなに? 草
  //排他的論理和とれって話だったね
  // そう
  //小文字は大文字、大文字は小文字
  //シフト演算もしくは論理演算っていう単元
  printf("入力された文字は%c,変換した文字は%c\n", moji_b, moji_b ^ mask_b);  //←ここになんか入れる問題なんだけどよくわからん←
  return 0;
  // したのSpaces: N ってなってるところでデフォルトのインデント変更できるよ　おおー
  //初期４でしたわ
  // 👍👏👏👏
  
}
// こんにちは　 なにやるんだっけか
//よっす
//なんか問題にされるとこの単元全然わかんなくなるんですよね　ふむてんてんてん。。。
// 多分、テストに出るのはいくつかのパターンなので何回もやればできるようになると思う
// 結果的に理解できているなら問題ないかと
/* #include <stdio.h>
#include <string.h>
#include <math.h> while( x > 0 ){
        a[k] = x & 1;
        x >>= 1;
        k ++;
    }

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    
    return 0;
}
*/
// 完全に理解した
//これがかってに全部出てくるっていう
//live shareってページこえたらおっつかないんだっけ
// 今pra.cにいるけど例えばp139.cに移ってもみれるん？　ほ〜
// ページ超えたらとは?どこにいるかは左のLiveShareメニューから確認できる
// 開いているディレクトリは全部閲覧可能
// だから本来は~/Desktop/oonishi をVSCodeで開くのが良い
// code コマンドをインストールしておけば、ターミナルで　o-nishi@onishi-ThinkPad-E490:~ $ cd desktop/oonishi; code . で開ける==もしくはo-nishi@onishi-ThinkPad-E490:~ $ code desktop/oonishi
// ctrl + shift + p 押したあとに command で検索すればコマンドがインストールできるはず
//  tips: control + / でコメントアウト/インの切り替えできるよ

