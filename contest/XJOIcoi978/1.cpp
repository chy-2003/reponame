#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100010], cnt[10010], ans = 0, num = 0;
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) {
        if(cnt[a[i]] == ans) ++cnt[a[i]], ++num;
        if(num == k) ++ans, num = 0;
    }
    printf("%d\n", ans + 1);
    return 0;
}
