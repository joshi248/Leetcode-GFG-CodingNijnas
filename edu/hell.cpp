#include <bits/stdc++.h>
#define endl "\n"
#define all(v) (v).begin(), (v).end()
#define pb push_back
using namespace std;

template <typename T>
istream &operator>>(istream &istream, vector<T> &v){for (auto &it : v) cin >> it; return istream;}
template <typename T>
ostream &operator<<(ostream &ostream, vector<T> &v){for (auto &it : v) cout << it << ' '; return ostream;}

bool check(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i == 0) return false;
    }
    return true;
}

void solve(){
    int n,m; cin >> n >> m;
    int ok = 0;
    if(check(m)) ok = 1;
    int c = 1;
    for(int i=0;i<n;i++){
        int idx = 0;
        if(ok) idx = (n * m - i) % m;
        vector<int> temp(m);
        for(int j=idx;j<m;j++) temp[j] = c++;
        for(int j=0;j<idx;j++) temp[j] = c++;
        cout << temp << '\n';
    }
    cout << "\n";
}
int main(){

ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int t = 1; cin >> t; while(t--) solve();    

    return 0;
}