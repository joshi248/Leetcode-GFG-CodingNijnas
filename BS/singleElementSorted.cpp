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

int find(vector<int> &v, int n){
        if(n==1) return v[0];
        if(v[0] != v[1]) return v[0];
        if(v[n-1] != v[n-2]) return v[n-1];
        int low = 1, hi = n-2;
        while(low <= hi){
            int mid = (low+hi)>>1;
            // {1, 1, 4, 4, 15, 16, 16}
            // {0  1  2  3  4   5   6}
            if(v[mid] != v[mid+1] && v[mid] != v[mid-1]) return v[mid];

            // We are in the left half
            if((mid%2==1 && v[mid] == v[mid-1]) || (mid%2==0 && v[mid] == v[mid+1])){
                low = mid + 1;            
            }
            else{
                hi = mid - 1;
            }
        }
        return -1;
}


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v;
    cout << find(v, n);
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
// cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;

    return 0;
}