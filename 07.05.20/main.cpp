#include <bits/stdc++.h>

using namespace std;

int n, m;
int d[1001][1001];
bool used[1001][1001];

void dfs (int x, int y){
    used[x][y] = 1;
    if (x + 1 < n){
        if (d[x + 1][y] == 1 && !used[x + 1][y]){
            dfs(x + 1, y);
        }
    }
    if (x - 1 >= 0){
        if (d[x - 1][y] == 1 && !used[x - 1][y]){
            dfs(x - 1, y);
        }
    }
    if (y + 1 < m){
        if (d[x][y + 1] == 1 && !used[x][y + 1]){
            dfs(x, y + 1);
        }
    }
    if (y - 1 >= 0){
        if (d[x][y - 1] == 1 && !used[x][y - 1]){
            dfs(x, y - 1);
        }
    }
}

int main(){
    cin >> n >> m;
    bool proof = 0;
    bool check1 = 0;
    bool check2 = 0;
    for (int i = 0; i < n; ++i){
        bool ind = 0;
        bool dot = 0;
        for (int j = 0; j < m; ++j){
            char a;
            cin >> a;
            if (a == '#'){
                d[i][j] = 1;
                if (!ind)
                    ind = 1;
                else if (dot){
                    proof = 1;
                    //cout << i << ' ' << j << endl;
                }
            }
            else if (ind)
                dot = 1;
        }
        if (!ind)
            check1 = 1;
    }
    for (int j = 0; j < m; ++j){
        bool ind = 0;
        bool dot = 0;
        for (int i = 0; i < n; ++i){
            if (d[i][j] == 1){
                if (!ind)
                    ind = 1;
                else if (dot){
                    proof = 1;
                    //cout << i << ' ' << j << endl;
                }
            }
            else if (ind)
                dot = 1;
        }
        if (!ind)
            check2 = 1;
    }
    if (!check2 && check1 || check2 && !check1)
        proof = 1;
    if (proof)
        cout << -1 << '\n';
    else{
        int ans = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (d[i][j] == 1 && !used[i][j]){
                    ++ans;
                    dfs(i, j);
                }
            }
        }
        cout << ans << '\n';
    }
}
