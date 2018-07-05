//XJOI 1229
#include <bits/stdc++.h>
using namespace std;
const int bz[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};
int n, m, a[30][30], x, y, cnt = 0;
char ch;
void dfs(int x, int y){
    if(a[x][y] == 1) return;
    a[x][y] = 1;
    cnt++;
//  cout << x << " " << y << endl;
    for(int i = 0; i < 4; i++) dfs(x + bz[0][i], y + bz[1][i]);
    return;
}
int main(){
    cin >> m >> n;
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> ch;
            if(ch == '#') a[i][j] = 1; else
            if(ch == '@'){
                x = i; y = j;
            }
        }
    for(int i = 1; i <= n; i++){a[i][0] = 1; a[i][m + 1] = 1;}
    for(int i = 1; i <= m; i++){a[0][i] = 1; a[n + 1][i] = 1;}
    dfs(x, y);
    cout << cnt;
    return 0;
}