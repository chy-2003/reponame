#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
struct Node {
    int x, y;
    Node (int x_ = 0, int y_ = 0) { x = x_; y = y_; return; }
};
int a[10][10];
int num = 0;
Node aa[25], rec;
int NEED = 0, SUC;
void dfs(int nu, int la);
bool check();
int main() {
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 5; j++) {
            char ch;
            cin >> ch;
            a[i][j] = ch - '0';
            if(a[i][j]) {
                NEED = 1;
                rec = Node(i, j);
            }
        }
    if(NEED == 0) {
        printf("0\n");
        return 0;
    }
    if(check()) {
        printf("0\n");
        return 0;
    }
    int la = 4;
    for(int i = 1; i <= 5; i++) {
        int t = 0;
        while(a[i][t + 1] != 1 && t + 1 <= la - 1) a[i][++t] = -1;
        la = t;
    }
    la = 2;
    for(int i = 1; i <= 5; i++) {
        int t = 6;
        while(a[i][t - 1] != 1 && t - 1 >= la + 1) a[i][--t] = -1;
        la = t;
    }
    la = 4;
    for(int i = 5; i >= 1; i--) {
        int t = 0;
        while(a[i][t + 1] != 1 && t + 1 <= la - 1) a[i][++t] = -1;
        la = t;
    }
    la = 2;
    for(int i = 5; i >= 1; i--) {
        int t = 6;
        while(a[i][t - 1] != 1 && t - 1 >= la + 1) a[i][--t] = -1;
        la = t;
    }
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 5; j++)
            if(a[i][j] == 0)
                aa[++num] = Node(i, j);
    for(int i = 1; i <= num; i++) {
        SUC = 0;
        NEED = i;
        dfs(0, 0);
        if(SUC) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
int b[10][10];
const int bz[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};
void dfs2(Node x) {
    b[x.x][x.y] = 0;
    for(int i = 0; i < 4; i++) {
        int xx = x.x + bz[0][i];
        int yy = x.y + bz[1][i];
        if(b[xx][yy] == 1) dfs2(Node(xx, yy));
    }
    return;
}
bool check() {
    for(int i = 0; i <= 6; i++)
        for(int j = 0; j <= 6; j++)
            b[i][j] = a[i][j];
    dfs2(rec);
    bool ans = true;
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 5; j++)
            if(b[i][j] == 1) {
                ans = false;
                break;
            }
    return ans;
}
void dfs(int nu, int last) {
    if(nu == NEED) {
        if(check()) SUC = 1;
        return;
    }
    for(int i = last + 1; i <= num - (NEED - nu) + 1; i++) {
        a[aa[i].x][aa[i].y] = 1;
        dfs(nu + 1, i);
        a[aa[i].x][aa[i].y] = 0;
        if(SUC) return;
    }
    return;
}
