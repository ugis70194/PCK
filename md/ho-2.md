## 本選 2問目 
### 問題

### 解法

### コード
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<queue<int>> lanes(N);
    for(int i = 0; i < M; i++){
        int b, n;
        cin >> b >> n;
        if(b == 0){
            n--;
            cout << lanes[n].front() << endl;
            lanes[n].pop();
        } else {
            int lane = 0;
            int len = 1e9;
            for(int l = 0; l < N; l++) {
                if(len > lanes[l].size()){
                    lane = l;
                    len = lanes[l].size();
                }
            }
            lanes[lane].push(n);
        }
    } 
}
```