#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int ans = 1;
    while(N >= (ans << 1)) ans <<= 1;
    cout << ans << endl;
}