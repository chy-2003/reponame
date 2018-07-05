//XJOI 3585
#include <bits/stdc++.h>
using namespace std;
const int bz[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};
int n, m, a[210][210], b[210][210], x, y, xx, yy;
char ch;
int l, r, q[2][40010];
int main(){
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> ch;
            if(ch == '#') a[i][j] = -1;
            if(ch == '.') a[i][j] = 1000;
            if(ch == '@'){
                x = i; y = j;
                a[i][j] = 0;
            }
            if(ch == 'M'){
                xx = i; yy = j;
                a[i][j] = 1000;
            }
            if(ch == 'G'){
                b[i][j] = 1;
                a[i][j] = 1000;
            }
        }
    l = 0; r = 1;
    q[0][r] = x;
    q[1][r] = y;
    while(l < r){
        l++;
        for(int i = 0; i < 4; i++){
            x = q[0][l] + bz[0][i];
            y = q[1][l] + bz[1][i];
            if(a[x][y] != -1)
                if(a[q[0][l]][q[1][l]] + 1 + b[x][y] < a[x][y]){
                    r++;
                    q[0][r] = x; q[1][r] = y;
                    a[x][y] = a[q[0][l]][q[1][l]] + 1 + b[x][y];
                }
        }
    }
    if(a[xx][yy] == 1000) cout << "You can't save Mengxin"; else cout << a[xx][yy];
    return 0;
}