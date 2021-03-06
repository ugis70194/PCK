## 予選 4問目 集会所
### 問題
東西に一直線に伸びる道路に沿った村がある。  
最も西の地点を0番目として、等間隔に東に向かって順に地区番号が与えられている。
ある時刻に一斉にすべての村人が自分の家から集会所に向かったとき、全員が集まるのに必要な時間が最小になるような場所に集会所を建てることにした。  
家の立っている地点の番号が与えられたとき、最適な場所に集会所と建てた場合に、すべての村人が集会所に集まるのに必要な時間の最小値を求めるプログラムを作成せよ。  
ただし、家の数$N$は$1 \le N \le 1000$を、家が立っている地区番号$x_i$は$0 \le x_i \le 2000$を満たす。  
集会所はすで家が立っている地区に建ててもよい。
また、すべての村人は隣の地区まで1分で移動できるものとする。  
### 解法
集会所にたどり着くのに最も時間がかかるのは西の端か、東の端の家に住んでいる村人なので、そこだけ考えればよい。  
そして、集会所がこれら2つの地区のちょうど真ん中に建っているとき、村人全員が集会所に集まるまでにかかる時間が最小になる。  
したがって、西の端の家から集会所までの距離と東の端から集会所までの距離のより大きい方が最小の時間になる。  
時間計算量のオーダーは$O(N)$となる。  
### コード
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> X(N);
    for(int i = 0;i < N; i++) cin >> X[i];
    int MIN = *min_element(begin(X), end(X));
    int MAX = *max_element(begin(X), end(X));
    int m = (MIN + MAX) / 2;
    cout << max(abs(MIN - m), abs(MAX - m)) << endl;
}
```