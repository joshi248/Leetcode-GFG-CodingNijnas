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

int orangesRotting(vector<vector<int> > &grid){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int> (m, 0));
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            if(grid[i][j] == 2){
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;
            }
        }
    }
    int time = 0;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    while(!q.empty()){
        int r = q.front().first.first;
        // cout << "Hello World" << endl;
        int c = q.front().first.second;
        int t = q.front().second;
        time = max(time, t);
        q.pop();
        for(int i = 0 ; i < 4; ++i){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow >= 0 && ncol >= 0 && ncol < m && nrow < n && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                q.push({{nrow, ncol}, t+1});
                vis[nrow][ncol] = 2;
            }
        }

    }

    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            if(vis[i][j] != 2 && grid[i][j] == 1){
                return -1;
            }
        }
    }
    return time;


}


void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > grid(n, vector<int> (m, -1));
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            cin >> grid[i][j];
        }
    }
    int ans = orangesRotting(grid);
    cout << ans;
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