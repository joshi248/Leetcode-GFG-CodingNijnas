#include <bits/stdc++.h>
#define endl "\n"
#define all(v) (v).begin(), (v).end()
#define pb push_back
using namespace std;

void solve(){
    long long n, s;
    cin >> n >> s;
    cout << s/(n*n) << endl;
}
int main(){

ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int t = 1; cin >> t; while(t--) solve();    

    return 0;
}