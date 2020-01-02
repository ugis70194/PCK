## 予選 1問目 柴犬の数 
### 問題
公園に4種類の柴犬がいます。
柴犬の数はそれぞれ、$R, B, W, G$で与えられる。
このとき、柴犬の総数を求めるプログラムを作成せよ。  
ただし、$1 \le R,B,W,G \le 100$を満たす。
### 解法
$R, B, W, G$すべてを足したものを出力すればよい。
時間計算量のオーダーは$O(1)$となる。  

### コード
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int R, B, W, G;
    cin >> R >> B >> W >> G;
    cout << R + B + W + G << endl;
}
```