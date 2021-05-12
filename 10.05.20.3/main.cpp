#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,k;
bool used[101][101][7];
int d[101][101][7];
char g[101][101];

void bfs(pair <int, int> w, int i){
    used[w.first][w.second][i] = 1;
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
           if (!used[nw.first][nw.second][i] && g[nw.first][nw.second] != '#'){
            d[nw.first][nw.second][i] = d[v.first][v.second][i] + 1;
            q.push(nw);
            used[nw.first][nw.second][i] = 1;
           }
        }
        if (x>0){
           nw.first = x-1, nw.second = y;
           if (!used[nw.first][nw.second][i] && g[nw.first][nw.second] != '#'){
            d[nw.first][nw.second][i] = d[v.first][v.second][i] + 1;
            q.push(nw);
            used[nw.first][nw.second][i] = 1;
           }
        }
        if (y<m-1){
           nw.first = x, nw.second = y+1;
           if (!used[nw.first][nw.second][i] && g[nw.first][nw.second] != '#'){
            d[nw.first][nw.second][i] = d[v.first][v.second][i] + 1;
            q.push(nw);
            used[nw.first][nw.second][i] = 1;
           }
        }
        if (y>0){
           nw.first = x, nw.second = y-1;
           if (!used[nw.first][nw.second][i] && g[nw.first][nw.second] != '#'){
            d[nw.first][nw.second][i] = d[v.first][v.second][i] + 1;
            q.push(nw);
            used[nw.first][nw.second][i] = 1;
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
        cin >> x1 >> x2;
        r[i] = make_pair(x1,x2);
    }
    bfs(s, 0);
    if (k == 0){
        if (d[f.first][f.second][0] == 0)
            cout << -1;
        else
            cout << d[f.first][f.second][0];
    }
    else if (k<=5){
        vector < pair <int,int> > p[6];
        for (int i = 0; i < k; ++i){
            int x = r[i].first;
            int y = r[i].second;
            if (x<n-1){
                if (g[x+1][y] != '#')
                    p[i].push_back({x+1,y});
            }
            if (x>0){
                if (g[x-1][y] != '#')
                    p[i].push_back({x-1,y});
            }
            if (y<m-1){
                if (g[x][y+1] != '#')
                    p[i].push_back({x,y+1});
            }
            if (y>0){
                if (g[x][y-1] != '#')
                    p[i].push_back({x,y-1});
            }
        }
        ll mn = 100000000;
        for (int i = 0; i < p[0].size(); ++i){
            ll nw = 0;
            nw+=d[p[0][i].first][p[0][i].second][0];
            bfs(p[0][i], 1);
            if (k>1 && (d[p[0][i].first][p[0][i].second][0]>0 || p[0][i]==s) ){
                for (int j = 0; j < p[1].size(); ++j){
                    nw+=d[p[1][j].first][p[1][j].second][1];
                    bfs(p[1][j], 2);
                    if (k>=3 && (d[p[1][j].first][p[1][j].second][1]>0 || p[0][i]==p[1][j])){
                        for (int j3 = 0; j3 < p[2].size(); ++j3){
                            nw+=d[p[2][j3].first][p[2][j3].second][2];
                            bfs(p[2][j3], 3);
                            if (k>=4 && (d[p[2][j3].first][p[2][j3].second][2]>0 || p[2][j3]==p[1][j])){
                                for (int j4 = 0; j4 < p[3].size(); ++j4){
                                    nw+=d[p[3][j4].first][p[3][j4].second][3];
                                    bfs(p[3][j4], 4);
                                    if (k==5 && (d[p[3][j4].first][p[3][j4].second][3]>0 || p[3][j4]==p[2][j3])){
                                        for (int j5 = 0; j5 < p[4].size(); ++j5){
                                            nw+=d[p[4][j5].first][p[4][j5].second][4];
                                            if (d[p[4][j5].first][p[4][j5].second][4] > 0 || p[3][j4]==p[4][j5]){
                                                bfs(p[4][j5], 5);
                                                nw+=d[f.first][f.second][5];
                                                if (d[f.first][f.second][5]>0 || p[4][j5]==f)
                                                    mn = min (nw, mn);
                                            }
                                            //cout << nw << endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (mn == 100000000)
            cout << -1;
        else
            cout << mn;
    }
}
