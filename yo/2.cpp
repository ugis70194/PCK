#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    if(65 <= N && N <= 90) cout << 1 << endl;
    else if(97 <= N && N <= 122) cout << 2 << endl;
    else cout << 0 << endl;
}