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

bool dfs(int index, int par, vector<int> adj[], vector<int> &vis){
    vis[index] = 1;
    for(auto e: adj[index]){
        if(!vis[e]){
            if(dfs(e, index, adj, vis)) return true;
        }
        else if (par != e) return true;
    }
    return false;
}

bool cycleDetection(int v, vector<int> adj[]){
    vector<int> vis(v+1);
    for(int i = 1; i <= v; ++i){
        if(!vis[i]){
            if(dfs(i, -1, adj, vis)) return true;
        }
    }
    return false;
}


void solve(){
    int v, e;
    cin >> v >> e;
    vector<int> adj[v+1];
    for(int i = 1 ; i <= e ; ++i){
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bool ans = cycleDetection(v, adj);
    cout << (ans ? "YES" : "NO") << endl;
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