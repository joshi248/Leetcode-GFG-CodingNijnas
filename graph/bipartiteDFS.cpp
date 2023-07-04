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

class Solution {
    private:
        bool dfs(int index, int col, vector<int> &color, vector<int> adj[]){
            color[index] = col;
            for(auto n : adj[index]){
                if (color[n] == -1) {
                    if(!dfs(n, !col, color, adj)){
                        return false;
                    }
                }
                else if(color[n] == col){
                    return false;
                }
            }
            return true;
        }

    public:
        bool isBipartite(int v, vector<int> adj[]){
            vector<int> color(v, -1);
    
            for(int i = 0 ; i < v; ++i){
                if(color[i] == -1) {
                    if(!dfs(i, 0, color, adj)){
                        return false;
                    }   
                }
            }
            return true;
            
        }
};


void solve(){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		cout << (ans ? "YES" : "NO");
        
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