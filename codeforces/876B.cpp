#include <bits/stdc++.h>
#define endl "\n"
#define all(v) (v).begin(), (v).end()
#define pb push_back
using namespace std;

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    vector<pair<int, int> > vp;
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        vp.push_back({x, y});
}
    sort(all(vp));
    


}
int main(){

ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int t = 1; cin >> t; while(t--) solve();    

    return 0;
}