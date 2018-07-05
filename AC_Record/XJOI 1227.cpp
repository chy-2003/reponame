//XJOI 1227
#include <bits/stdc++.h>
using namespace std;
const int bz[2][8] = {{-1, -1, 0, 1, 1, 1, 0, -1}, {0, 1, 1, 1, 0, -1, -1, -1}};
int n, m, a[110][110];
char ch;
void dfs(int x, int y){
    if(a[x][y] == 0) return;
    a[x][y] = 0;
    for(int i = 0; i < 8; i++) dfs(x + bz[0][i], y + bz[1][i]);
    return;
}
int main(){
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> ch;
            if(ch == 'W') a[i][j] = 1; else a[i][j] = 0;
        }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i][j] == 1){
                cnt++;
                dfs(i, j);
            }
    cout << cnt;
    return 0;
}