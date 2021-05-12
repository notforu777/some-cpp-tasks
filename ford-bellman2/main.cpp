#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct edge{
	int a, b, cost;
};

int n, m, k, s, f, sh;
vector <edge> e(100001);
vector <bool> used(100001);
const int INF = 100000001;

int main(){
    cin >> n >> m >> k >> s >> f;
    for (int i = 0; i < m; ++i)
        cin >> e[i].a >> e[i].b >> e[i].cost;
    vector <int> d (n + 1, INF);
    vector <int> t (n + 1, INF);
	d[s] = 0;
	t[s] = 0;
	used[s] = 1;
	while(sh < k){
		bool any = false;
		for (int j = 0; j < m; ++j)
			if (d[e[j].a] < INF)
				if (t[e[j].b] > d[e[j].a] + e[j].cost) {
					t[e[j].b] = d[e[j].a] + e[j].cost;
					used[e[j].b] = 1;
					any = true;
				}
		if (!any)
            break;
        ++sh;
        d = t;
	}
	if (used[f])
        cout << t[f];
    else
        cout << -1;
}
