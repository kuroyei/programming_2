/*
 * プログラミング2 レポート2-2
 * C文字列dstが，C文字列srcの先頭からcount文字をコピーした文字列とし、
 * できた文字列の先頭アドレスを返却する関数strncopy
 */

#include <iostream>
using namespace std;

char* strncopy(char *dst, const char *src, unsigned count){
  // copy src[<=count-1] to dst

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