#include <bits/stdc++.h>
#define endl "\n"
#define all(v) (v).begin(), (v).end()
#define pb push_back
using namespace std;

void solve(){
    vector<int> v = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    int longest = 1;
    // Brute
    // for(auto &e: v){
    //     int count = 1;
    //     int x = e;
    //     while(find(all(v), x+1) != v.end()){
    //         count++;
    //         x++;
    //     }
    //     longest = max(longest, count);
        
    // }

    // Better
    // int n = v.size(), last_smallest = INT_MIN, count = 1;
    // sort(all(v));
    // for(int i = 0; i< n; ++ i){
    //     if(v[i] - 1 == last_smallest){
    //         count++;
    //         last_smallest = v[i];
    //     }
    //     else if(v[i] != last_smallest){
    //         count = 1;
    //         last_smallest = v[i];
    // }
    //     longest = max(longest, count);
    // }

    //  Optimal
    unordered_set<int> s; 
    for(auto &e: v) s.insert(e);
    for(auto &e: s){
        if(s.find(e-1) == s.end()){
            int count = 1;
            int x = e;
            while(s.find(x+1) != s.end()){
                count++;
                x++;
            }
            longest = max(longest, count);
        }
    }
    


    cout << longest << endl;
}
int main(){

ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int t = 1; cin >> t; while(t--) solve();    

    return 0;
}