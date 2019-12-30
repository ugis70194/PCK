## 予選 3問目 ２の累乗
### 問題

### 解法

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