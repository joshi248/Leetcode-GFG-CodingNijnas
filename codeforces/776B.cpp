#include <bits/stdc++.h>
#define endl "\n"
#define all(v) (v).begin(), (v).end()
#define pb push_back
using namespace std;

int temp(long long x, long long y){
    return ((x/y) + (x%y));
}
void solve(){
    long long x,y,a; cin >> x >> y >> a;
		long long ans = 0;
		int k = y%a;
		if(k == (a-1)){
			cout << temp(y,a) << endl;
		}
		else{
			if(y-k-1 >= x){
				cout << temp(y-k-1,a) << endl;
			}
			else{
				cout << temp(y,a) << endl;
			}
		}
}
int main(){

ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int t = 1; cin >> t; while(t--) solve();    

    return 0;
}