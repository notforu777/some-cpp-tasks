#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    vector <ll> f(n), used(511111);
    f[n - 1] = 1;
    used[0] = 1;
    while (f.back() < 100000){
        ll x = 0;
        for (int i = 0; i < n; ++i){
            x += f[f.size() - 1 - i];
        }
        f.push_back(x);
        used[x] = 1;
    }
    for (int i = min(a, b); i <= max(a, b); ++i) {
        cout << used[i];
    }
}
