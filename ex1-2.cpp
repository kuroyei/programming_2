#include <iostream>
using namespace std;

int max(int *x, int n){
  int m=*x;
  for (int i=0; i<n; i++){
    if (m<*(x+i)){
      m=*(x+i);
    }
  }
  return m;
}

int main(){
  const int N=10;
  int x[N];  
  for (int i=0; i<N; i++){
    cin >> x[i]; 
  }
  /* 配列全体の最大を表示する */
  // ここを実装
  cout << max(x, N) << endl;

  /* 前半5つの要素の最大を表示する */
  // ここを実装
  cout << max(x, N/2) << endl;

  /* 後半5つの要素の最大を表示する */
  // ここを実装
  // cout << max(x, N/2, N) << endl;
  cout << max(x+N/2, N/2) << endl; // Because repeat 5 times

    return 0;
}
