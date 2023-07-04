#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

int main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    int i = 1;
    while(n--){
        int k, b;
        cin >> k >> b;

        int arr[k];
        for(int i = 0 ; i < k ; ++i){
            cin >> arr[i];
        }
        sort(arr, arr+k);
        int ans = 0;
        int j = 0;
        while(b >= arr[j] && j < k){
            b -= arr[j];
            ++j;
            ++ans;
        }
        cout << "Case #" << i << " :" << ans << endl;
        ++i;
    }


return 0;
}
