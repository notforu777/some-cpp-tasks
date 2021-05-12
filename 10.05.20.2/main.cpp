#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,k;
bool used[101][101];
int d[101][101];
char g[101][101];

void bfs(pair <int, int> w){
    used[w.first][w.second] = 1;
    queue < pair<int,int> > q;
    q.push(w);
    while(!q.empty()){
        pair<int,int> v = q.front();
        q.pop();
        int x = v.first;
        int y = v.second;
        pair<int,int> nw;
        if (x<n-1){
           nw.first = x+1, nw.second = y;
           if (!used[nw.first][nw.second] && g[nw.first][nw.second] != '#'){
            d[nw.first][nw.second] = d[v.first][v.second] + 1;
            q.push(nw);
            used[nw.first][nw.second] = 1;
           }
        }
        if (x>0){
           nw.first = x-1, nw.second = y;
           if (!used[nw.first][nw.second] && g[nw.first][nw.second] != '#'){
            d[nw.first][nw.second] = d[v.first][v.second] + 1;
            q.push(nw);
            used[nw.first][nw.second] = 1;
           }
        }
        if (y<m-1){
           nw.first = x, nw.second = y+1;
           if (!used[nw.first][nw.second] && g[nw.first][nw.second] != '#'){
            d[nw.first][nw.second] = d[v.first][v.second] + 1;
            q.push(nw);
            used[nw.first][nw.second] = 1;
           }
        }
        if (y>0){
           nw.first = x, nw.second = y-1;
           if (!used[nw.first][nw.second] && g[nw.first][nw.second] != '#'){
            d[nw.first][nw.second] = d[v.first][v.second] + 1;
            q.push(nw);
            used[nw.first][nw.second] = 1;
           }
        }
    }
}

int main(){
    cin >> n >> m >> k;
    pair <int,int> s;
    pair <int,int> f;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> g[i][j];
            if (g[i][j] == 'S'){
                 s = make_pair(i,j);
            }
            if (g[i][j] == 'F'){
                 f = make_pair(i,j);
            }
        }
    }
    vector < pair <int, int> > r(k);
    for (int i = 0; i < k; ++i){
        int x1, x2;
        cin >> x1,x2;
        r[i] = make_pair(x1,x2);
    }
    bfs(s);
    if (k == 0){
        cout << d[f.first][f.second];
    }
}
