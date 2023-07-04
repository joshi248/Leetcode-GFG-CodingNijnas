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




void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v;
    int low = 0, hi = n-1, index = -1, curr = INT_MAX;
    while (low <= hi){
        int mid = (hi+low)>>1;
        if(v[low] <= v[hi]){
            if(v[low] < curr){
                curr = v[low];
                index = low;
            }
            break;
        }

        // Check right half
        if(v[hi] >= v[mid]){
            if(v[mid] < curr){
                curr = v[mid];
                index = mid;
            }
            hi = mid - 1;
        }
        else{ // check left half
            if(v[low] < curr){
                curr = v[low];
                index = low;
            }
            low = mid + 1;
        }
    }
    cout << index;
    
    
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
//cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;

    return 0;
}