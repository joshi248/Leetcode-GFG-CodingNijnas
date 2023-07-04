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

void dfs(vector<int> &vis, vector<int> adj[], int index){
    vis[index] = 1;
    for(auto it: adj[index]){
        if(!vis[it]){
            dfs(vis, adj, it);
        }
    }
}

int numProvinces(vector<vector<int> > &adj, int V){
    // Converting to adj List
    vector<int> adjLs[V];
    for(int i = 0; i < V; ++i){
        for(int j = 0 ; j < V; ++j){
            if(adj[i][j] == 1 && i != j){
                adjLs[i].pb(j);
                adjLs[j].pb(i);
            }
        }
    }

    vector<int> vis(V);
    int count = 0;
    for(int i = 0; i < V; ++i){
        if(!vis[i]){
            count++;
            dfs(vis, adjLs, i);
        }
    }
    return count;
}


void solve(){
    int V;
    cin >> V;
    vector<vector<int> > adj;
    for(int i = 0; i < V; ++i){
        vector<int> temp(V);
        cin >> temp;
        adj.pb(temp);
    }

    cout << numProvinces(adj, V);


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