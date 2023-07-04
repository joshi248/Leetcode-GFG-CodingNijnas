#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
using namespace std;

void solve(){
    int x = 105;
    for(int i=31;i >= 0 ;--i){
        if(x &(1<<i)) cout << "1";
        else cout << "0";
    }
}
int main(){

ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int t = 1; cin >> t; while(t--) solve();    

    return 0;
}