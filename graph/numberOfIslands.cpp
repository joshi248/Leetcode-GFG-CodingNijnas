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

void bfs(int i, int j, vector<vector<int> > &vis, vector<vector<char> > &grid){
    int n = grid.size();
    int m = grid[0].size();

    vis[i][j] = 1;
    queue<pair<int, int> > q;
    q.push({i, j});
    
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // Traverse in all 8 directions
        for(int Drow = -1; Drow <= 1; ++Drow){
            for(int Dcol = -1; Dcol <= 1; ++Dcol){
                int Nrow = row + Drow;
                int Ncol = col + Dcol;
                if(Nrow >= 0 && Ncol >= 0 && Nrow < n && Ncol < m && grid[Nrow][Ncol] == '1' && vis[Nrow][Ncol] == 0){
                    vis[Nrow][Ncol] = 1;
                    bfs(Nrow, Ncol, vis, grid);
                }
            }
        }
    }
}



int numIslands(vector<vector<char> > &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int> > vis(n, vector<int> (m, 0));
    int count = 0;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            if(!vis[i][j] && grid[i][j] == '1'){
                count ++;
                bfs(i, j, vis, grid);
            }
        }
    }
    return count;
}


void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<char> > grid(n, vector<char> (m, '#'));
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            cin >> grid[i][j];
        }
    }
    cout << numIslands(grid) << endl;
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