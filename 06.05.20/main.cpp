#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    vector <ll> s;
    s.push_back(2);
    int i = 0;
    while(s[i] <= 1e9){
        ++i;
        int x = s[i - 1] + (i + 1) * 2 + i;
        s.push_back(x);
    }
    while(t--){
        int n;
        cin >> n;
        int l = 0;
        int r = i;
        int k = 0;
        while(n >= s[0]){
            if (k > 0){
                r = l + 1;
            }
            l = 0;
            while (r - l > 1){
                int m = (r + l) / 2;
                if (s[m] > n)
                    r = m;
                else
                    l = m;
            }
            //cout << n << ' ';
            n -= s[l];
            //cout << s[l] << endl;
            ++k;
        }
        cout << k << '\n';
    }
}
