#include <bits/stdc++.h>
using namespace std;
int n, a[1010], b[1010];
struct Node {
    int x, y, pos;
    Node (int x_ = 0, int y_ = 0, int pos_ = 0) { x = x_; y = y_; pos = pos_; }
};
Node t[1010];
int l, r, rec[1010];
int t1[1010], t2[1010];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for(int i = 1; i <= n; i++) t[i] =  Node(a[i], b[i], i);
    for(int i = 1; i < n; i++)
        for(int j = i + 1; j <= n; j++)
            if(min(t[i].x, t[i].y) > min(t[j].x, t[j].y))
                swap(t[j], t[i]);
    l = 0; r = n + 1;
    for(int i = 1; i <= n; i++)
        if(min(t[i].x, t[i].y) == t[i].x) rec[++l] = i; else rec[--r] = i;
    for(int i = 1; i <= n; i++) {
        t1[i] = t1[i - 1] + t[rec[i]].x;
        t2[i] = max(t1[i] + t[rec[i]].y, t2[i - 1] + t[rec[i]].y);
    }
    printf("%d\n", t2[n]);
    for(int i = 1; i < n; i++) printf("%d ", t[rec[i]].pos); printf("%d\n", t[rec[n]].pos);
    return 0;
}
