#include <bits/stdc++.h>
#define endl "\n"
#define all(v) (v).begin(), (v).end()
#define pb push_back
using namespace std;

void solve(){
    
    // string s;
    // cin >> s;
    // char c;
    // cin >> c;
    // if(s[s.length()/2] == c) cout << "YES" << endl;
    // else cout << "NO" << endl;

    string s;
    cin >> s;
    char c;
    cin >> c;
    if(s.length() == 1){
        if(s[0] == c) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
        return;
    }
    int i = 0;bool found = false;
    while(i < s.length()){
        if(s[i]==c){
            cout << "YES" << endl;
            found = true;
            break;
        }
        i += 2;
    }
    if(!found) cout << "NO" << endl;
}
int main(){

ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int t = 1; cin >> t; while(t--) solve();    

    return 0;
}