#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> p(n, 0);
    for (int i = 0; i < n; ++i){
        cin >> p[i];
    }
    vector <int> a(m, 0);
    for (int i = 0; i < m; ++i){
        cin >> a[i];
    }
    set <int> st;
    for (int i = 0; i < n; ++i){
        st.insert(i);
    }
    queue <int> q;
    ll ans = 0;
    map <int, int> mp;
    for (int i = 0; i < 2 * m; ++i){
        int x;
        cin >> x;
        if (x > 0){
            x--;
            if(!st.empty()){
                int pl = *st.lower_bound;
                ans += p[pl] * a[x];
                st.erase(pl);
                mp[x] = pl;
            }
            else{
                q.push(x);
            }
        }
        else{
            x = -x;
            x--;
            if (!q.empty()){
                int nw = q.front();
                q.pop();
                mp[nw] = mp[x];
                ans += a[nw] * p[mp[x]];
            }
            else{
                st.insert(mp[x]);
            }
        }
    }
    cout << ans;
}
