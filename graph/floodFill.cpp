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

void dfs(vector<vector<int> > &image, int sr, int sc, int delRow[], int delCol[], vector<vector<int> > &ans, int newColor, int initial_color){
    ans[sr][sc] = newColor;
    int n = image.size();
    int m = image[0].size();
    for(int i = 0; i < 4; ++i){
        int Nrow = sr + delRow[i];
        int Ncol = sc + delCol[i] ;
        // cout << Nrow << " " << Ncol << endl;
        if(Ncol >= 0 && Nrow >= 0 && Ncol < m && Nrow < n && image[Nrow][Ncol] == initial_color && ans[Nrow][Ncol] != newColor){
            dfs(image, Nrow, Ncol, delRow, delCol, ans, newColor, initial_color);
        }
    }
}

vector<vector<int> > floodFill(vector<vector<int> > &image, int sr, int sc, int newColor){
    vector<vector<int> > ans = image;
    int initial_color = image[sr][sc];
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    dfs(image, sr, sc, delRow, delCol, ans, newColor, initial_color);
    return ans;
}


void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > image;
    for(int i = 0 ; i < n ; ++i){
        vector<int> temp;
        for(int j = 0 ; j < m ; ++j){
            int x;
            cin >> x;
            temp.push_back(x);
        }
        image.push_back(temp);
        
    }
    // cout << endl;
    // cout << endl;
    // cout << endl;
    // cout << "*******NEW AGAIN*****" << endl;
    // for(auto e: image){
    //     cout << e;
    //     cout << endl;
    // }
    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;
    vector<vector<int> > d = floodFill(image, sr, sc, newColor);
    for(auto it: d){
        cout << it;
        cout << endl;
    }
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