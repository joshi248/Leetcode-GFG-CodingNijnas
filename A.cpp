// #pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

int main(){

    /*
        ***PAIRS***   
    */
    pair<int, int> p = {1, 2};
    cout << p.first << ' ' << p.second << '\n';

    pair<int, int> arr[] = {{1, 3}, {2, 3}, {4, 5}};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0 ; i < n ; ++i){
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }

    /*
        ***VECTORS***   
    */

    vector<int> v;

    v.push_back(4);
    v.emplace_back(6);

    int n = v.size();
    for(int i = 0 ; i < n ; ++i){
        cout << v[i] << '\n';
    }


    vector<int> second = {1, 2, 3, 4, 5, 6, 7};
    for(int i = 0 ; i < second.size(); ++i){
    cout << second[i] << '\n';
    }

    vector<int>::iterator it = second.begin();
    cout << *it << '\n';


    it += 2;
    cout << *it << '\n';


    vector<int>::iterator k = second.end();
    k--;
    cout << *k << '\n';


    cout << "The value at the end of vector is " << second.back() << '\n';

    for(auto e: second) cout << e << ' ';
    cout << '\n';

    second.erase(second.begin() + 3, second.begin() + 6);
    for(int i = 0 ; i < second.size(); ++i){
        cout << second[i] << ' ';
    }



    /*
        ***STACK***   
    */
    stack<int> st;
    st.push(0);
    st.push(4);
    st.push(5);
    cout << st.top() << '\n';
    st.pop();
    cout << st.top() << '\n';




    /*
        ***QUEUE***   
    */
    queue<int> q;
    q.push(8);
    q.push(4);
    q.push(6);
    cout << q.front() << '\n';
    q.pop();
    cout << q.front() << '\n';
    int p = q.front();
    q.pop();
    cout << (q.front() == p ? "YES" : "NO") << '\n';



    /*
        ***PRIORITY_QUEUE***   
    */

    priority_queue<int> pq;
    pq.push(10);
    pq.push(8);
    cout << pq.top() << '\n';
    pq.push(11);
    cout << pq.top() << '\n';

    /*
        ***SETS***   
    */

    set<int> s;
    s.insert(4);
    s.insert(5);
    s.insert(8);
    s.insert(7);
    for(auto it: s) cout << it << ' ';
    cout << '\n';

    return 0;
}