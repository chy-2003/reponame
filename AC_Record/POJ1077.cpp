#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int fact[10];
void init() {
    fact[0] = 1;
    for(int i = 1; i <= 9; i++) fact[i] = fact[i - 1] * i;
    return;
}
int a[10];
void read() {
    char ch;
    for(int i = 1; i <= 9; i++) {
        cin >> ch;
        if(ch == 'x') a[i] = 9; else a[i] = ch - '0';
    }
    return;
}
void ihash(int x) {
    int vis[10];
    memset(vis, 0, sizeof(vis));
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= 9; i++) 
        for(int j = 1; j <= 9; j++) {
            if(vis[j]) continue;
            if(x < fact[9 - i]) {
                vis[j] = 1;
                a[i] = j;
                break;
            }
            x -= fact[9 - i];
        }
    return;
}
int hash() {
    int vis[10];
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    for(int i = 1; i <= 9; i++) { 
        for(int j = 1; j < a[i]; j++) {
            if(vis[j]) continue;
            ans += fact[9 - i];
        }
        vis[a[i]] = 1;
    }
    return ans;
}
int get_empty() {
    for(int i = 1; i <= 9; i++) 
        if(a[i] == 9) {
            return i;
            break;
        }
    return 0;
}
int l, r, q[400010][3], rec[400010];
void print(int x) {
//    printf("In funtion print(%d)\n", x);
    if(q[x][1] != -1) print(q[x][1]);
    if(q[x][2] == 0) printf("u");
    if(q[x][2] == 1) printf("r");
    if(q[x][2] == 2) printf("d");
    if(q[x][2] == 3) printf("l");
    return;
}
void bfs(int x) {
    if(x == 0) {
        return;
    }
    getchar();
    l = r = 0;
    memset(q, 255, sizeof(q));
    memset(rec, 0, sizeof(rec));
    r = 1;
    q[1][0] = x;
    rec[x] = 1;
//    printf("BFS starting...\n");
    while(l < r) {
        getchar();
        l++;
        ihash(q[l][0]);
//        printf("try spanding at : \n");
//        for(int i = 1; i <= 9; i++) printf("%d", a[i]); printf("\n");
        int t = get_empty();
//        if(t == 0) { printf("Program ERROR!!!\n"); continue; }
        if(t >= 4) {
            swap(a[t], a[t - 3]);
            int x = hash();
            if(!rec[x]) {
                rec[x] = 1;
                r++; q[r][0] = x; q[r][1] = l; q[r][2] = 0;
//                printf("up valid\n");
                if(x == 0) {
//                    printf("SUCCESSED!!!\n");
                    print(r);
                    return;
                }
            }
            swap(a[t], a[t - 3]);
        }
        if(t % 3 != 1) {
            swap(a[t], a[t - 1]);
            int x = hash();
            if(!rec[x]) {
                rec[x] = 1;
                r++; q[r][0] = x; q[r][1] = l; q[r][2] = 3;
//                printf("left valid\n");
                if(x == 0) {
//                    printf("SUCCESSED!!!\n");
                    print(r);
                    return;
                }
            }
            swap(a[t], a[t - 1]);
        }
        if(t <= 6) {
            swap(a[t], a[t + 3]);
            int x = hash();
            if(!rec[x]) {
                rec[x] = 1;
                r++; q[r][0] = x; q[r][1] = l; q[r][2] = 2;
//                printf("down valid\n");
                if(x == 0) {
//                    printf("SUCCESSED!!!\n");
                    print(r);
                    return;
                }
            }
            swap(a[t], a[t + 3]);
        }
        if(t % 3 != 0) {
            swap(a[t], a[t + 1]);
            int x = hash();
            if(!rec[x]) {
                rec[x] = 1;
                r++; q[r][0] = x; q[r][1] = l; q[r][2] = 1;
//                printf("right valid\n");
                if(x == 0) {
//                    printf("SUCCESSED!!!\n");
                    print(r);
                    return;
                }
            }
            swap(a[t], a[t + 1]);
        }
    }
    printf("unsolvable");
    return;
}
int main() {
    init();
    read();
//    printf("check point 1\n");
    bfs(hash());
    printf("\n");
    return 0;
}
