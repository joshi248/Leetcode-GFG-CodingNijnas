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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    // It contains duplicates
    cin >> arr;
    int low = 0, hi = n-1;
    bool ok =false;
    while(low <= hi){
        int mid = (low+hi)>>1;
        if(arr[mid] == k) {
            ok = true;
            break;
        }
        if(arr[mid] == arr[low] && arr[hi] == arr[mid]){
            low = low+1;
            hi = hi-1;
            continue;
        }
        
        // Check if left half is sorted
        if(arr[mid] >= arr[low]){
            // Check if k lies in left or right half
            if(k <= arr[mid] && k >= arr[low]){
                // Bring hi here
                hi = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{ // right half is sorted
            // Chekc if k lies in the left or right half
            if(k <= arr[hi] && k >= arr[mid]){
                // Bring low here
                low = mid + 1;
            }
            else hi = mid - 1;
        }
    }
    cout << (ok ? "YES" : "NO");
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