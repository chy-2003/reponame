//XJOI 3584
#include <bits/stdc++.h>
using namespace std;
const int bz[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};
int n, m, a[30][30], x, y;
char ch;
int l, q[2][410], r;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> ch;
            if(ch == '.') a[i][j] = 0;
            if(ch == '#') a[i][j] = 1;
            if(ch == '@'){
                a[i][j] = 0;
                x = i; y = j;
            }
        }
    for(int i = 1; i <= n; i++){a[i][0] = 1; a[i][m + 1] = 1;}
    for(int j = 1; j <= m; j++){a[0][j] = 1; a[n + 1][j] = 1;}
    l = 0; r = 1;
    q[0][r] = x;
    q[1][r] = y;
    a[x][y] = 1;
    while(l < r){
        l++;
        for(int i = 0; i < 4; i++){
            x = q[0][l] + bz[0][i];
            y = q[1][l] + bz[1][i];
            if(a[x][y] == 0){
                r++;
                q[0][r] = x;
                q[1][r] = y;
                a[x][y] = 1;
            }
        }
    }
    cout << r;
    return 0;
}