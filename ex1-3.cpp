#include<iostream>
#include<cmath>
using namespace std;

void showArray(int *l, int *r){
  for (int* p=l; p<=r; p++){
    cout << *p << ",\n"[p==r]; // (p==r ? "\n" : ",")
  }
}

void bubbleSort(int *l, int *r){
  int tmp;

  for(int *i=l;i<r;i++){
    for(int *j=i+1;j<=r;j++){
      if(*i > *j){
        tmp = *i;
        *i = *j;
        *j = tmp;
      }
    }
   }

  
}

int main(){
  const int N=10;
  int x[N]; // N人の点数を入れる(配列)
  
  for (int i=0; i<N; i++){
    cin >> x[i]; // 配列に順番に格納する
  }
  showArray(x, x+N-1);

  bubbleSort(x, x+N-1);

  showArray(x, x+N-1);

  
  return 0;
}
