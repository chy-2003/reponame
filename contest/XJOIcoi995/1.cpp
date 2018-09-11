#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 1000010;
int n, a[MAXN], b[MAXN];
int l, r, q[MAXN], lin;
int ans;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
    l = r = 1; lin = 0;
    memset(q, 0, sizeof(q));
    q[0] = -1000000000;
    ans = 0;
    for(int i = 1; i <= n; i++) {
        while(l <= r && q[l] < i) l++;
        if(lin < i) {
            lin = i;
            q[++r] = i;
        }
        while(lin < n && b[lin + 1] >= a[q[l]]) {
            lin++;
            while(l <= r && a[lin] >= a[q[r]]) r--;
            q[++r] = lin;
        }
        ans = std::max(ans, lin - i + 1);
    }
    printf("%d\n", ans);
    return 0;
}
