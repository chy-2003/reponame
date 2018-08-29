#include <bits/stdc++.h>
using namespace std;
int a[210], b[210], c[210], d[210], x, n, m;
void init() {
    memset(d, 0, sizeof(d));
    for(int i = 51; i <= 70; i++) {
        d[i] = x % 10;
        x = x / 10;
    }
    return;
}
bool bigger() {
    for(int i = 200; i >= 1; i--) {
        if(b[i] > d[i]) return true;
        if(b[i] < d[i]) return false;
    }
    return false;
}
bool les() {
    memset(b, 0, sizeof(b));
    b[51] = 1;
    for(int k = 1; k <= n; k++) {
        memset(c, 0, sizeof(c));
        for(int i = 1; i <= 70; i++) 
            for(int j = 1; j <= 70; j++) 
                c[i + j - 1] += a[i] * b[j];
        for(int i = 1; i <= 140; i++) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
        for(int i = 1; i <= 140; i++) b[i] = c[i + 50];
        if(bigger()) return false;
    }
    return true;
}
int main() {
    cin >> x >> n >> m;
    init();
    for(int i = 70; i > 0; i--) {
        for(int j = 9; j >= 0; j--) {
            a[i] = j;
            if(les()) break;
        }
    }
    int t = 70;
    for(; t > 51 && a[t] == 0; t--);
    for(int i = 1; i <= m; i++) printf("%d", a[t--]);
    printf("\n");
    return 0;
}
