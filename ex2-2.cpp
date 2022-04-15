/*
 * プログラミング2 レポート2-2
 * C文字列dstが，C文字列srcの先頭からcount文字をコピーした文字列とし、
 * できた文字列の先頭アドレスを返却する関数strncopy
 */

#include <iostream>
using namespace std;

char* strncopy(char *dst, const char *src, unsigned count){
  // copy src[<=count-1] to dst

  /* 解説

    i は 何番目であるかを示す
    入出力を見てみよう
    in : ABCDEFGHIJKLMNOPQURSTVUWXYZ 5
    out: ABCDE

    最初の5文字が表示されている
    ここで，Aは0番目，...，Eは4番目
    すなわち，5番目まで表示すればよい
    よって，i < count という条件がある

    また，問題には「元の文字列srcの文字数がcountより少ない場合には、文字列全体をコピーするとする」とある
    i < count という条件だけでは駄目なのである
    もし，i が srcの文字列 を上回ると，*(str+i) == '\0' を満たすことになる．
    よって，while() の条件に *(str+i) == '\0' がある

    && としないと，*(str+i) == '\0' であっても while() が実行されるため注意である

    while()の後，配列の最後に '\0' を代入している．
    i の値が増えてから while() は閉じるから，i は dst 配列の最後を指していると思ってよい
    

  */

  int i = 0;
  while(i < count && *(src+i) != '\0'){
    dst[i] = src[i];
    ++i;
  }
  dst[i] = '\0';

  return dst;
}

int main(){
  char str1[1024]={'\0'};
  char str2[1024]={'\0'};
  unsigned n=0;

  while (cin >> str1){
    cin >> n;
    cout << strncopy(str2, str1, n) << endl;
  }

  return 0;
}
