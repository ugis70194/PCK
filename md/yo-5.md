## 予選 5問目 ねこのあな
### 問題
中が行き止まりになっている横穴がある。この横穴は猫がちょうど一匹入れるくらいの横幅で、奥行きは100匹の猫が入るのに十分である。 
横穴に出入りした猫のリストが与えられるので、リストの先頭から順に見ていったとき、それより後ろを見なくても誤りと判定できる最初の位置を求めるプログラムを作成せよ。
ただし、猫は100匹いて、1から100までの番号が与えられているものとする。
$i$番目に横穴に入った猫の番号が$a_i$、出た猫の番号が#$-a_i$で与えられる。  
また、リストの長さ$L$は$1 \le L \le 10000$の範囲で与えられる。
### 解法
明らかに誤りなのは、リスト上で  
- 既に横穴に入っている猫が横穴に入ったとき
- 一匹も横穴に入っていないのに猫が出てきたとき
- 一番最後に入った猫でない猫が出てきたとき
- 横穴に入っていない猫が出てきたとき
の4つの状況が起こった場合である。  
横穴はスタック構造になっているのでスタックと配列を用いてシミュレーションをすればよい。
配列は今その番号の猫が横穴に入っているかどうかのフラグを管理するために用いる。   
上記4つをスタックと配列の操作に直せば以下のようになる。
- 今見ている値に横穴に入っているフラグが立っている
- スタックのサイズが0なのに今見ている値が負
- スタックの一番上の値といま見ている値に-1をかけたものが異なる
- 今見ている値に-1をかけたものに横穴に入っているフラグが立っていない
したがって、これらのパターンを検知するようにアルゴリズムを組めばよい。
リストを最後まで見る必要がある場合があるので、時間計算量は$O(L)$

### コード
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int L;
    cin >> L;
    vector<int> C(L);
    for(int i = 0; i < L; i++) cin >> C[i];
    vector<int> in(L+1,0);
    stack<int> s;

    int ans = 1e9;
    for(int i = 0; i< L; i++){
        if(C[i] > 0){
            if(in[C[i]]) ans = min(ans, i+1);
            else in[C[i]] = 1, s.push(C[i]);
        } 
        if(C[i] < 0){
            if(s.size() == 0) ans = min(ans, i+1);
            else if(in[-C[i]] && s.top() != -C[i]) ans = min(ans, i+1);
            else if(!in[-C[i]]) ans = min(ans, i+1);
            else in[-C[i]] = 0, s.pop();
        }
    }

    if(ans == 1e9) cout << "OK" << endl;
    else cout << ans << endl;
}
```
