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

int count(int pages, vector<int> &arr){
    int student = 1, pageStudent = 0;
    for(int i = 0; i < arr.size(); ++i){
        if(pageStudent + arr[i] <= pages){
            pageStudent += arr[i];
        }
        else{
            student++;
            pageStudent = arr[i];
        }
    }
    return student;

}


void solve(){
    int n, m;
    cin >> n >> m;
    if(m > n){
        cout << -1;
        return;
    }
    vector<int> arr(n);
    cin >> arr;
    int low = *max_element(all(arr));
    int hi = accumulate(all(arr), 0);
    while(low <= hi){
        int mid = (low + hi)>>1;
        int students = count(mid, arr);
        if(students > m) low = mid + 1;
        else hi = mid - 1;
    }
    cout << low;
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