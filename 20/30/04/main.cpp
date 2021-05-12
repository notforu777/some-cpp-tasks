#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector <ll> a(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n - 1; ++i){
        ll o, p;
        cin >> o >> p;
    }
    vector <ll> d1(n, 0);
    vector <ll> d2(n, 0);
    vector <ll> d3(n, 0);
    vector <ll> d4(n, 0);
    for (int i = 1; i < n; ++i){
        d1[i] = d1[i - 1] + a[i - 1];
        d3[i] = d3[i - 1] + d1[i];
    }
    for (int i = n - 2; i >= 0; --i){
        d2[i] = d2[i + 1] + a[i + 1];
        d4[i] = d4[i + 1] + d2[i];
    }
    int ans = 1e6 + 1;
    ll mx = 1e18;
    for (int i = 0; i < n; ++i){
        if (d3[i] + d4[i] < mx){
            mx = d3[i] + d4[i];
            ans = i;
        }
    }
    cout << ans;
}
