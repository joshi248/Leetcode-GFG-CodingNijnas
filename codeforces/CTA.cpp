// joshi248
#include <bits/stdc++.h>
#define endl "\n"
#define all(v) (v).begin(), (v).end()
#define pb push_back
using namespace std;

template <typename T>
istream &operator>>(istream &istream, vector<T> &v){for (auto &e : v) cin >> e; return istream;}
template <typename T>
ostream &operator<<(ostream &ostream, vector<T> &v){for (auto &e : v) cout << e << ' '; return ostream;}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int k = 1;
    for(int i = 1; i <= n ; ++i){
        for(int j = i; j <= n; ++j){
            if(abs(a[i] - a[k]) == abs(a[k] - a[j])){
                cout << i << " " << j << endl;
                ans.push_back(i, j);
            }
        }
        ++k;
    }
}
int main(){

ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int t = 1;
cin >> t;
while(t--) solve();

    return 0;
}