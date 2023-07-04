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

int f(int i, int j, vector<vector<int> > &triangle, int n,  vector<vector<int> > &dp){
    if(i == n-1){
        return triangle[n-1][j];
    }
    if(dp[i][j] != -1) return dp[i][j];
    int row = triangle[i][j] + f(i+1, j, triangle, n, dp);
    int dg = triangle[i][j] + f(i+1, j+1, triangle, n, dp);
    return  dp[i][j] = min(row, dg);
}


int minimumPathSum(vector<vector<int> > &triangle, int n){
    //  vector<vector<int> > dp(n, vector<int> (n, -1));
    // return f(0, 0, triangle, n, dp);
     vector<vector<int> > dp(n, vector<int> (n, 0));
    for(int j = 0; j <n ; ++j){
       dp[n-1][j] = triangle[n-1][j];
    }
    for(int i = n-2; i >= 0; --i){
        for(int j = i; j>= 0; --j){
            int d = triangle[i][j] + dp[i+1][j];
            int dg = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(d, dg);
        }
    }
    return dp[0][0];
}


void solve(){
    int n;
    cin >> n;
    vector<vector<int> > triangle;
    int i = 1;
    for(int j = 1; j <= n ; ++j){
        vector<int> temp(i);
        cin >> temp;
        triangle.pb(temp);
        i++;
    }
    vector<vector<int> > dp(n, vector<int> (n, -1));
    cout << minimumPathSum(triangle, n) << endl;


}




int main(){

ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
cout << fixed << setprecision(25);
cerr << fixed << setprecision(10);
auto start = std::chrono::high_resolution_clock::now();

int t = 1;
cin >> t;
while(t--) solve();
auto stop = std::chrono::high_resolution_clock::now(); 
auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;

    return 0;
}