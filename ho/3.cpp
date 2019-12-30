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