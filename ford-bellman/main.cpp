#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct edge {
	int a, b, cost;
};

int n, m, v;
vector <edge> e;
//const int INF = 1000000001;

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int r;
            cin >> r;
            edge ed;
            ed.a = i, ed.b = j, ed.cost = r;
            if (r != 10000)
                e.push_back(ed);
        }
    }
    vector<int> d (n + 1, 0);
	vector <int> p (n + 1, -1);
	int y;
	for (int i = 0; i < n; ++i) {
		y = -1;
		for (int j = 0; j < e.size(); ++j)
            if (d[e[j].b] > d[e[j].a] + e[j].cost){
                d[e[j].b] = d[e[j].a] + e[j].cost;
                p[e[j].b] = e[j].a;
                y = e[j].b;
            }
	}
	if (y == -1)
		cout << "NO" << '\n';
	else{
        cout << "YES" << '\n';
		for (int i = 0; i < n; ++i)
			y = p[y];
		vector <int> path;
		for (int cur = y; ; cur = p[cur]) {
			path.push_back(cur);
			if (cur == y && path.size() > 1)
                break;
		}
		reverse (path.begin(), path.end());
		cout << path.size() << '\n';
		for (int i = 0; i < path.size(); ++i)
			cout << path[i] << ' ';
	}
}
