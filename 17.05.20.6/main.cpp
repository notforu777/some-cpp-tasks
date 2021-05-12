#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	vector< vector<ll> > a(8), b(8);
	for (int i = 0; i < 8; ++i){
		ll x;
		cin >> x;
		for (int j = 0; j < 8; ++j){
			if (x & (1 << j)){
				a[i].push_back(1);
			}
			else{
				a[i].push_back(0);
			}
		}
	}
	for (int i = 0; i < 8; ++i) {
		int x;
		cin >> x;
		for (int j = 0; j < 8; ++j) {
			if (x & (1 << j)){
				b[i].push_back(1);
			}
            else {
				b[i].push_back(0);
			}
		}
	}
	int ans = 65537;
	for (int msk = 0; msk < (1 << 16); ++msk){
		vector< vector<ll> > u = a;
		for (int i = 0; i < 8; ++i){
			if (msk & (1 << i)){
				for (int k = 0; k < 8; ++k)
                    u[i][k] = 1 - u[i][k];
			}
			if (msk & (1 << (8 + i))){
				for (int k = 0; k < 8; ++k)
                    u[k][i] = 1 - u[k][i];
			}
		}
		if (u == b) {
			ans = min(ans, (int)__builtin_popcountll(msk));
		}
	}
	cout << ans;
}
