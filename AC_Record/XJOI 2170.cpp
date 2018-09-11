#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;
int n, father[30010], deep[30010], val[30010], size[30010];
int read_int() {
    char ch = getchar(); int t = 0;
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t;
}
int read_char() {
    char ch = getchar();
    while(!(ch == 'M' || ch == 'C')) ch = getchar();
    return ch;
}
int get_father(int x) {
    if(father[x] == x) return x;
    int t = father[x];
    father[x] = get_father(father[x]);
    deep[x] = deep[t] + val[x]; val[x] = deep[x];
    return father[x];
}
char ch;
int x, y, xx, yy;
int main() {
    for(int i = 1; i <= 30000; i++) father[i] = i;
    for(int i = 1; i <= 30000; i++) size[i] = 1;
    memset(deep, 0, sizeof(deep));
    n = read_int();
    for(int i = 1; i <= n; i++) {
        ch = read_char(); x = read_int(); y = read_int();
        if(ch == 'M') {
            xx = get_father(x); yy = get_father(y);
            if(xx != yy) {
                father[xx] = yy; val[xx] = size[yy]; size[yy] += size[xx];
            }
        } else {
            xx = get_father(x); yy = get_father(y);
            if(xx != yy) printf("-1\n"); else printf("%d\n", abs(deep[x] - deep[y]) - 1);
        }
    }
    return 0;
}
