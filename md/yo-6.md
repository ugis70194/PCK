## 予選 6問目 床
### 問題
博士の家の床には正方形のタイルが敷きつめられている。はじめに部屋の適当なタイルをひとつ選び、以下の方法で色を塗っていく。
- タイルを塗る色を、赤、黄、青の順に変えていき、青の次はまた赤から始める。
- すでに色を塗った領域の隣に正方形を追加し、そこに色を塗る。それらを合わせた領域が長方形になるようにする。正方形を追加する方向は、東、北、西、南の順に変えていき、南の次はまた東から始める。
最初に赤く塗ったタイルから東を$x$の正の方向、北を$y$の正の方向として、東西方向に$x$個,南北方向に$y$個移動したところにあるタイルの色を求めるプログラムを作成せよ。  
ただし、$x, y$は$-10^6 \le x, y \le 10^6$の範囲で与えられる。
### 解法
![](./yo-6.jpg)
タイルに色を塗っていくと上の図のようになる。  
図を見ると、正方形の大きさはかなりの速さで増加していくことが分かる。  
正方形の一辺の長さは1, 1, 2, 3, 5 ...となっている。  
これはフィボナッチ数列であるので、$i$個目の正方形の一辺の長さは動的計画法を用いて高速に求められる。 
最初に赤く塗ったタイルの左下端を原点(0,0)として、$i$個目の正方形の左下端の座標と右上端の座標をもっておけば、
座標(x,y)の位置のタイルが何個目の正方形に属しているかがわかる。  
したがって、$i$個目の正方形の左下端の座標と右上端の座標、面積、色を最初に赤く塗ったタイルから順に求めていって、
座標(x, y)が正方形の中に入っているか逐次判定すればよい。  
フィボナッチ数列は2の累乗よりもすこし増加量が小さいので時間計算量はおおまかに$\log (max(|x|, |y|))$程度となる。  
### コード
```cpp
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

struct coor{
    pair<i64, i64> x, y;
};

int main(){
    i64 X,Y;
    cin >> X >> Y;
    vector<i64> fib(500);
    fib[0] = fib[1] = 1;
    for(int i = 2; i < 500; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    coor now = {{0, 1}, {0, 1}};
    i64 way = 0;
    i64 color = 0;
    int i = 1;
    while(i < 500){

        //cout << color << " -----" << endl;
        //cout << now.x.first << " " << now.x.second << endl;
        //cout << now.y.first << " " << now.y.second << endl;

        if(now.x.first <= X && X < now.x.second 
        && now.y.first <= Y && Y < now.y.second){
            cout << color+1 << endl;
            return 0;
        }
        
        coor next;
        if(way == 0) {
            next.x.first = now.x.second;
            next.x.second = next.x.first + fib[i];
            next.y.first = now.y.first;
            next.y.second = next.y.first + fib[i];
        }
        if(way == 1){
            next.x.second = now.x.second;
            next.x.first = next.x.second - fib[i];
            next.y.first = now.y.second;
            next.y.second = next.y.first + fib[i];
        }
        if(way == 2){
            next.x.second = now.x.first;
            next.x.first = next.x.second - fib[i];
            next.y.second = now.y.second;
            next.y.first = now.y.second - fib[i]; 
        }
        if(way == 3){
            next.x.first = now.x.first;
            next.x.second = next.x.first + fib[i];
            next.y.second = now.y.first;
            next.y.first = next.y.second - fib[i];
        }

        now = next;
        i++, way++, color++;
        way %= 4;
        color %= 3;
    }

    cout << 0 << endl;
}
```
