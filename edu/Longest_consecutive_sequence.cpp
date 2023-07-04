#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;

void solve(){
    vector<int> v = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    int ans = 0;
    // for(int i=0;i<v.size(); ++i){
    //     int x = v[i];
    //     int count = 1;
    //     while(find(begin(v), end(v), x+1) != v.end()){
    //         x += 1;
    //         count++;
    //     }
    //     ans = max(ans, count);
    // }

    // sort(all(v));
    // int count = 0, last_smallest = INT_MIN, longest = 1, n = v.size();
    // for(int i=0;i<n;++i){
    //     if(v[i] - 1 == last_smallest){
    //         count++;
    //         last_smallest = v[i];
    //     }
    //     else if(last_smallest != v[i]){
    //         count = 1;
    //         last_smallest = v[i];
    //     }
    //     longest = max(longest, count);
    // }

    unordered_set<int> s;
    for(auto &e: v) s.insert(e);
    int longest = 1;

    for(auto &e: s){
        if(s.find(e - 1) == s.end()){
            int count = 1;
            int x = e;
            while(s.find(x+1) != s.end()){
                count += 1;
                x += 1;
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