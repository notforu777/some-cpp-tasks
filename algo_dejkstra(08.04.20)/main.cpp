#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1000000001;

int main(){
    int n, d1, v;
    cin >> n >> d1 >> v;
    d1--;
    v--;
    int r;
    cin >> r;
    vector < pair< int, pair<int, int> > > g[n];
    vector <int> d(n, INF);
    for (int i = 0; i < r; ++i){
        int s, t1, f, t2;
        cin >> s >> t1 >> f >> t2;
        s--;
        f--;
        g[s].push_back({t1, {f, t2}});
    }
    d[d1] = 0;
    vector <bool> u(n);
    for (int i = 0; i < n; ++i) {
		int v = -1;
		for (int j = 0; j < n; ++j)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		if (d[v] == INF)
			break;
		u[v] = 1;
		for (int j = 0; j < g[v].size(); ++j) {
			int to = g[v][j].second.first, tf = g[v][j].second.second, ts = g[v][j].first;
			if (ts >= d[v]){
                if (tf < d[to]) {
                    d[to] = tf;
                }
			}
		}
    }
    if (d[v] < INF)
        cout << d[v];
    else
        cout << -1;
}
