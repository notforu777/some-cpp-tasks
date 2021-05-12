#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector <ll> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    ll ans = n;
    map <ll,ll> mp;
    for (int i = 0; i < n; ++i){
        mp.clear();
        ++mp[a[i]];
        ll mx = a[i];
        ll mn = a[i];
        for (int j = i + 1; j < n; ++j){
            ++mp[a[j]];
            ll sh = 0;
            mn = min(mn, a[j]);
            while (mp[a[j] + sh] == 2){
                mp[a[j] + sh] = 0;
                ++mp[a[j] + sh + 1];
                if (mn == a[j] + sh)
                    ++mn;
                ++sh;
            }
            mx = max(mx, a[j] + sh);
            if (mn == mx){
                ++ans;
            }
        }
    }
    cout << ans;
}
