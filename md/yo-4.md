## 予選 4問目 集会所
### 問題

### 解法

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