#include <cstdio>
#include <cstring>
using namespace std;
struct Node {
    int a[150], len;
};
int n;
Node a[150];
int ans;
Node t1, t2;
char ch[150];
int rec[150][150], id1, id2;
int cmp(Node x, Node y) {
    if(x.len > y.len) return 1;
    if(x.len < y.len) return -1;
    for(int i = x.len; i >= 1; i--)
        if(x.a[i] > y.a[i]) return 1; else
        if(x.a[i] < y.a[i]) return -1;
    return 0;
}
int main() {
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++) {
        scanf("%s", ch);
        a[i].len = strlen(ch);
        for(int j = 0; j < a[i].len; j++)
            a[i].a[a[i].len - j] = ch[j] - '0';
    }
    ans = 0;
    memset(rec, 0, sizeof(rec));
    for(int i = 0; i <= 9; i++) {
        t1.len = t2.len = 0;
        t1.a[1] = t2.a[1] = 0;
        for(int j = 1; j <= n; j++) {
            if(a[j].a[a[j].len] != i) continue;
            if(cmp(a[j], t1) == 1) {
                t2 = t1; t1 = a[j];
                id2 = id1;
                id1 = j;
            } else
            if(cmp(a[j], t2) == 1) {
                t2 = a[j]; id2 = j;
            }
        }
        if(t2.len == 0) continue;
        rec[id1][id2] = 1;
    }
    for(int i = 0; i <= 9; i++) {
        t1.len = t2.len = 0;
        t1.a[1] = t2.a[1] = 0;
        for(int j = 1; j <= n; j++) {
            if(a[j].a[1] != i) continue;
            if(cmp(a[j], t1) == 1) {
                t2 = t1; t1 = a[j];
                id2 = id1;
                id1 = j;
            } else
            if(cmp(a[j], t2) == 1) {
                t2 = a[j]; id2 = j;
            }
        }
        if(t2.len == 0) continue;
        rec[id1][id2] = 1;
    }
    ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            ans += rec[i][j];
    printf("%d\n", ans);
    return 0;
}

