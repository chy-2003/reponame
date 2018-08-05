#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 5;

int n, m, k, a[MAXN];
char s[MAXN];

bool check2(int x) {
    int num = 0;
    for(int i = 1; i <= m; i ++)
        num += a[i] / (x + 1);
    return num <= k;
}

bool check1() {
    int num = 0;
    for(int i = 1; i <= n; i ++)
        if(s[i] - '0' == i % 2) num ++;
    return min(num, n - num) <= k;
}

void work() {
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    m = 1, a[1] = 1;
    for(int i = 2; i <= n; i ++) {
        if(s[i] == s[i - 1]) a[m] ++; else
            a[++m] = 1;
    }
    if(check1()) {
        printf("1\n");
        return;
    }
    int l = 2, r = n, ans;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check2(mid)) r = mid - 1, ans = mid; else l = mid + 1;
    }
    printf("%d\n", ans);
	return;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) work();
	return 0;
}
