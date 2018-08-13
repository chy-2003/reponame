#include <bits/stdc++.h>
using namespace std;
struct Node {
    int x, y;
    Node(int x_ = 0, int y_ = 0) { x = x_; y = y_; return;}
};
Node a[10010];
int n, P, Q;
bool cmp(Node x, Node y) {
    return x.x < y.x;
}
bool cmp2(Node x, Node y) {
    return x.y < y.y;
}
int ans = 0;
int main() {
    scanf("%d%d%d", &P, &Q, &n);
    int t = 0;
    for(int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[++t] = Node(x, y);
        a[++t] = Node(0, y);
    }
    a[++t] = Node(0, Q);
    a[++t] = Node(0, 0);
    a[++t] = Node(P, Q);
    a[++t] = Node(P, 0);
    n = t;
    sort(a + 1, a + n  + 1, cmp);
    for(int i = 1; i <= n; i++) {
        int x = Q, y = 0;
        for(int j = i + 1; j <= n; j++) {
            if(a[j].x == a[i].x) continue;
            ans = max(ans, (a[j].x - a[i].x) * (x - y));
            if(a[j].y >= a[i].y) x = min(x, a[j].y);
            if(a[j].y <= a[i].y) y = max(y, a[j].y);
        }
    }
    sort(a + 1, a + n + 1, cmp2);
    for(int i = 2; i <= n; i++) ans = max(ans, P * (a[i].y - a[i - 1].y));
    printf("%d\n", ans);
    return 0;
}
