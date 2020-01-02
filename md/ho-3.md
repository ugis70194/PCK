## 本選 3問目 海苔 
### 問題
二枚の長方形の海苔があります。  
二枚の海苔それぞれの左端の座標の幅と高さが与えられたとき、重なっていない部分の海苔の面積を出力するプログラムを作成せよ。  
ただし、海苔の左端の座標$x,y$、幅$w$、高さ$h$は$(0 \le x, y, w, h \le 1000)$の範囲で与えられる。  
### 解法
全体の面積から重なっている部分の面積を引けばよい。  
簡単のために、より左側にある海苔を一枚目の海苔とする。  
![](./ho-3.png)  
そうすれば、海苔の重なり方は上図の3通りになる。　　
重なっている幅は$x+w - X$と$W$の小さい方か、その小さい方が負になる場合は$0$になる。 
重なっている幅と高さはそれぞれ独立に求められるので、それぞれ独立に求めて重なっている面積を計算すれば良い。  
時間計算量のオーダーは$O(1)$になる。  
### コード
```cpp
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main(){
    i64 x, y, w, h;
    i64 X, Y, W, H;
    cin >> x >> y >> w >> h;
    cin >> X >> Y >> W >> H;

    if(x > X) { swap(x ,X), swap(y, Y), swap(w, W), swap(h, H); }
    i64 width = max(min(x+w - X, W), 0ll);
    if(y > Y) { swap(x ,X), swap(y, Y), swap(w, W), swap(h, H); }
    i64 height = max(min(y+h - Y, H), 0ll);

    cout << (w*h + W*H) - 2*(width*height) << endl; 
}
```
