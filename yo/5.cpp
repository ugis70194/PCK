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