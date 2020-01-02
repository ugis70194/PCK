## 予選 3問目 ２の累乗
### 問題
数値$N$が与えられる。  
$N$以下の数の中で最大の2の累乗を求めるプログラムを作成せよ。  
### 解法
数値のbit表現を利用する。bit表現においてbitが一つだけ立っているときは、10進数では2の累乗になる。  
したがって、立っているbitを左にずらしたときに与えられた数より大きくならなければ、bitを左にずらし続ければよい。
時間計算量のオーダーは$O(\log_2 N)$となる。 

### コード
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int ans = 1;
    while(N >= (ans << 1)) ans <<= 1;
    cout << ans << endl;
}
```