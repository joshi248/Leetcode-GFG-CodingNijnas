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
    vector<int> v = {1, 2, 3, 4, 5};
    // Output = {2, 3, 4, 5, 1}
    int n = v.size();
    int test;
    cin >> test;
    cout << "After roating for the " << test << " times the final array is: " << endl;
    while(test > 0){
    int temp = v[0];
    for(int i = 1; i < n; ++i){
        v[i-1] = v[i];
    }
    v[v.size()-1] = temp;
    test -= 1;
    }
    cout << v << endl;
}
int main(){

ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int t = 1;
cin >> t;
while(t--) solve();

    return 0;
}