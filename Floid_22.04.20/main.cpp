#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1000001;

int main(){
    int n, m, o;
    cin >> n >> m >> o;
    int d[n][n];
    int p[n][n];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            d[i][j] = INF;
        }
    }
    for (int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = - c;
    }
    vector <int> conc(o);
    for (int i = 0; i < o; ++i){
        cin >> conc[i];
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
    bool ind = false;
    for (int i = 1; i < o; ++i){
        int s = conc[i-1];
        int f = conc[i];
        if (d[s][f] + d[f][s] < 0){
            cout << "infinitely kind";
            ind = true;
            break;
        }
    }
}
