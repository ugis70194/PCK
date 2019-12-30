## 本選 4問目 
### 問題

### 解法

### コード
```cpp
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 POW(i64 x, i64 n){
    i64 res = 1;
    while(n){
        if(n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

int main(){
    i64 L, N;
    string snake;
    cin >> L >> N >> snake;

    i64 A = 0;
    for(int i = 1; i < L; i++) {
        if(snake[i-1] == snake[i] && snake[i] == 'o') A++;
    }

    cout << L + 3ll*A*(POW(2, N) - 1ll) << endl;
}
```