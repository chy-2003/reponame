#include <bits/stdc++.h>
using namespace std;
int n, m, a[10010], b[10010], c[10010];
int used[10010];
int get_(int x, int y) {
    return a[x] * y * y + b[x] * y + c[x];
}
struct cmp {
    bool operator () (int x, int y) {
        return get_(x, used[x] + 1) > get_(y, used[y] + 1);
    }
};
priority_queue<int, vector<int>, cmp> pq;
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
    memset(used, 0, sizeof(used));
    for(int i = 1; i <= n; i++) pq.push(i);
    for(int i = 1; i <= m; i++) {
        int t = pq.top();
        pq.pop();
        printf("%d ", get_(t, used[t] + 1));
        used[t]++;
        pq.push(t);
    }
    printf("\n");
    return 0;
}

