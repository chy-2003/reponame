#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
const int bz[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};
int n, m, a[210][210], b[210][210], map[210][210];
int x1, x2, y1, y2, l = 0, x[40010], y[40010];
char ch;

void bfs1(int x, int y);
void bfs2(int x, int y);
int min(int x, int y){ return (x < y) ? x : y; }
char get(){
    char ch = getchar();
    while(!(ch == '@' || ch == '&' || ch == 'F' || ch == '#' || ch == '.')) ch = getchar();
    return ch;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            ch = get();
            if(ch == '@'){ x1 = i; y1 = j; map[i][j] = 0; }
            if(ch == '&'){ x2 = i; y2 = j; map[i][j] = 0; }
            if(ch == 'F'){ l++; x[l] = i; y[l] = j; map[i][j] = 0; }
            if(ch == '#') map[i][j] = -1;
            if(ch == '.') map[i][j] = 0;
        }
    for(int i = 1; i <= n; i++){ map[i][0] = -1; map[i][m + 1] = -1; }
    for(int j = 1; j <= m; j++){ map[0][j] = -1; map[n + 1][j] = -1; }
    memset(a, 255, sizeof(a));
    memset(b, 255, sizeof(b));
    bfs1(x1, y1);
    bfs2(x2, y2);
    int ans = 100010;
    for(int i = 1; i <= l; i++)
        if(a[x[i]][y[i]] != -1 && b[x[i]][y[i]] != -1)
            ans = min(ans, a[x[i]][y[i]] + b[x[i]][y[i]]);
    if(ans < 100010)
        std::cout << ans << std::endl;
    else printf("Meeting cancelled\n");
    return 0;
}

int lq, rq, q[2][40010];
int rec[210][210];

void bfs1(int x, int y){
    lq = 0; rq = 1;
    q[0][1] = x; q[1][1] = y;
    memset(rec, 0, sizeof(rec));
    rec[x][y] = 1;
    a[x][y] = 0;
    while(lq < rq){
        lq++;
        for(int i = 0; i < 4; i++){
            x = q[0][lq] + bz[0][i];
            y = q[1][lq] + bz[1][i];
            if(rec[x][y] == 0 && map[x][y] != -1){
                rq++;
                q[0][rq] = x; q[1][rq] = y; rec[x][y] = 1; 
                a[x][y] = a[q[0][lq]][q[1][lq]] + 1;
            }
        }
    }
    return;
}

void bfs2(int x, int y){
    lq = 0; rq = 1;
    q[0][1] = x; q[1][1] = y;
    memset(rec, 0, sizeof(rec));
    rec[x][y] = 1;
    b[x][y] = 0;
    while(lq < rq){
        lq++;
        for(int i = 0; i < 4; i++){
            x = q[0][lq] + bz[0][i];
            y = q[1][lq] + bz[1][i];
            if(rec[x][y] == 0 && map[x][y] != -1){
                rq++;
                q[0][rq] = x; q[1][rq] = y; rec[x][y] = 1; 
                b[x][y] = b[q[0][lq]][q[1][lq]] + 1;
            }
        }
    }
    return;
}
