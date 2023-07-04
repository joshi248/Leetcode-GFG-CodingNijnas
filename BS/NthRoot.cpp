// joshi248
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(v) (v).begin(), (v).end()
#define pb push_back

template <typename T>
istream &operator>>(istream &istream, vector<T> &v){for (auto &e : v) cin >> e; return istream;}
template <typename T>
ostream &operator<<(ostream &ostream, vector<T> &v){for (auto &e : v) cout << e << ' '; return ostream;}

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int func(int mid, int n, int m){
    long long ans = 1;
    for(int i = 1; i <= n ; ++i){
        ans = ans * mid;
        if(ans > m) return 2;
    }
    if(ans == m) return 1;
    return 0;
}
int NthRoot(int n, int m){
    int low = 1, hi = m;
    while(low <= hi){
        int mid = (low+hi)>>1;
        int midN = func(mid, n, m);
        if(midN == 1) return mid;
        else if(midN == 0) low = mid + 1;
        else hi = mid - 1;
    }
    return -1;

}


void solve(){
    int n, m;
    cin >> n >> m;
    cout << NthRoot(n, m);
}




int main(){

ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
cout << fixed << setprecision(25);
cerr << fixed << setprecision(10);

auto start = std::chrono::high_resolution_clock::now();
int t = 1;
// cin >> t;
while(t--) solve();
auto stop = std::chrono::high_resolution_clock::now(); 
auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
// cerr << "\nTime taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;

    return 0;
}