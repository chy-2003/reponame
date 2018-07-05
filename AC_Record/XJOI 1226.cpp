//XJOI 1226
#include <bits/stdc++.h>
using namespace std;
const int bz[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};
int n, m, a[8][8], cnt;
char ch;
void dfs(int x, int y){
    if(a[x][y] == 1) return;
    if(x == n && y == m){
        cnt++;
        return;
    }
    a[x][y] = 1;
    for(int i = 0; i < 4; i++) dfs(x + bz[0][i], y + bz[1][i]);
    a[x][y] = 0;
    return;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> ch;
            if(ch == '*') a[i][j] = 0; else a[i][j] = 1;
        }
    for(int i = 1; i <= n; i++) {a[i][0] = 1; a[i][m + 1] = 1;}
    for(int i = 1; i <= m; i++) {a[0][i] = 1; a[n + 1][i] = 1;}
    dfs(1, 1);
    cout << cnt;
    return 0;
}