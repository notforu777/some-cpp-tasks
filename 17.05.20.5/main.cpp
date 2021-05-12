#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int p = 31;
const ll M = 10000000007;

int main(){
    int a;
    cin >> a;
    if (a == 1){
        int n;
        cin >> n;
        vector <ll> v(n, 0);
        for (int i = 0; i < n; ++i){
            string s;
            cin >> s;
            ll nw = 0;
            ll pn = p;
            for (int j = 0; j < s.size(); ++j){
                nw += ((s[j] - 'a' + 1) * pn) % M;
                nw %= M;
                pn *= p;
                pn %= M;
            }
            v[i] = nw;
        }
        for (int i = 0; i < 1024; ++i){
            if (i < n){
                cout << v[i] << ' ';
            }
            else{
                cout << -i << ' ';
            }
        }
    }
    else{
        set <ll> st;
        for (int i = 0; i < 1024; ++i){
            int x;
            cin >> x;
            if (x >= 0)
                st.insert(x);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i){
            string s;
            cin >> s;
            ll nw = 0;
            ll pn = p;
            for (int j = 0; j < s.size(); ++j){
                nw += ((s[j] - 'a' + 1) * pn) % M;
                nw %= M;
                pn *= p;
                pn %= M;
            }
            if (st.count(nw))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
