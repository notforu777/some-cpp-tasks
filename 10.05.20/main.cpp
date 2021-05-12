#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
bool ch = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    map <ll, ll> mp;
    ll i = 0;
    ll sum = 0;
    ll mx = 0;
    bool ind1 = 1;
    while (i < s.size()){
        ll x = 0;
        if (s[i] != '+' && s[i] != '-'){
            ll j = i;
            while (s[i] != '+' && s[i] != '-' && i < s.size()){
                x = x * 10 + s[i] - '0';
                ++i;
            }
            mp[j] = x;
            if (ind1)
                sum += x;
            else
                sum -= x;
        }
        if (s[i] == '+')
            ind1 = 1;
        else if (s[i] == '-')
            ind1 = 0;
        ++i;
    }
    i = 0;
    mx = -1e18;
    vector <ll> t(20, 0);
    t[0] = 1;
    for (int p = 1; p < 13; ++p){
        t[p] = t[p - 1] * 10;
    }
    bool ind = 1;
    //cout << sum << endl;
    while (i < s.size()){
        ll y = 0;
        if (s[i] != '+' && s[i] != '-'){
            ll j = i;
            while (s[i] != '+' && s[i] != '-' && i < s.size()){
                ++i;
            }
            y = mp[j];
        }
        if (i < s.size()){
            if (s[i] == '+' && ind){
                ll nw = sum;
                nw -= y + mp[i + 1];
                ll k = mp[i + 1];
                ll sh = 0;
                while (k > 0){
                    ++sh;
                    k /= 10;
                }
                y *= t[sh];
                y += mp[i + 1];
                nw += y;
                if (nw == sum)
                    ch = 1;
                mx = max(mx, nw);
            }
            else if (s[i] == '-' && ind){
                ll nw = sum;
                //cout << y << ' ' <<  mp[i + 1] << ' '<< nw << endl;
                nw -= y - mp[i + 1];
                ll k = mp[i + 1];
                ll sh = 0;
                while (k > 0){
                    ++sh;
                    k /= 10;
                }
                y *= t[sh];
                y += mp[i + 1];
                nw += y;
                if (nw == sum)
                    ch = 1;
                mx = max(mx, nw);
                ind = 0;
                //cout << mx << ' ' << i  << ' ' << endl;
            }
            if (s[i] == '-'){
                //cout << i << endl;
                ll k = mp[i + 1];
                ll nw = sum;
                //cout << nw << endl;
                nw += k;
                ll sh = 0;
                while (k > 0){
                    ++sh;
                    k /= 10;
                }
                k = mp[i + 1];
                ll l = 0;
                ll r = k;
                ll ud = sh - 1;
                ll mn1 = 1e18;
                for (int w = 1; w <= sh; ++w){
                    l = l * 10;
                    ll o = r / t[ud];
                    r %= t[ud];
                    ll nw1 = l * t[ud]/10 + r;
                    mn1 = min(mn1, nw1);
                    l += o;
                    --ud;
                }
                //cout << nw << ' ' << mn1 << endl;
                nw -= mn1;
                if (nw == sum)
                    ch = 1;
                mx = max(mx, nw);
                ind = 0;
            }
            else
                ind = 1;
        }
        ++i;
    }
    if (mx == -1e18)
        mx = sum;
    if (!ch && mx == sum){
        //cout << "ch" << endl;
        ll k = mx;
        ll sh = 0;
        while (k > 0){
            ++sh;
            k /= 10;
        }
        ll l = 0;
        ll r = mx;
        ll ud = sh - 1;
        //cout << sh << endl;
        ll mx2 = -1e18;
        for (int i = 1; i <= sh; ++i){
            l = l * 10;
            ll o = r / t[ud];
            r %= t[ud];
            ll nw = l * t[ud]/10 + r;
            //cout << l * t[ud]/10 << ' ' << r << endl;
            mx2 = max(mx2, nw);
            l += o;
            --ud;
            //cout << nw << endl;
        }
        cout << mx2;
    }
    else
        cout << mx;
}




