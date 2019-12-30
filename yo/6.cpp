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