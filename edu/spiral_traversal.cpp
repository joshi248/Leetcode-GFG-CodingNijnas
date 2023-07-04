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
    vector<vector<int>> v = {
        {1, 2, 3},
        {2, 4, 6},
        {5, 6, 4},
    };
    int row = v.size(), col = v[4].size();
    int top = 0, left = 0;
    int bottom = row - 1, right = col-1;
    vector<int> ans;
    while(top <= bottom && left <= right){
        for(int i = left; i <= right; ++i){
            ans.pb(v[top][i]);
        }
        top++;
        for(int i = top; i <= bottom; ++i){
            ans.pb(v[i][right]);
        }
        right--;
        if(top <= bottom){
        for(int i = right; i >= left; --i){
            ans.pb(v[bottom][i]);
        }
        bottom--;
        }
        if(left <= right){
        for(int i = bottom; i >= top; --i){
            ans.pb(v[i][left]);
        }
        left++;
        }
    }
    cout << ans << endl;
}
int main(){

ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int t = 1;
cin >> t;
while(t--) solve();

    return 0;
}