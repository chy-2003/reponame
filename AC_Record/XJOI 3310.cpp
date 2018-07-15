#include<bits/stdc++.h>
using namespace std;
int n, a[60], ans;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    ans = 0;
    ans = max(ans, abs(a[1] - a[2]));
    ans = max(ans, abs(a[n] - a[n - 1]));
    for(int i = 3; i <= n; i++) ans = max(ans, abs(a[i] - a[i - 2]));
    printf("%d\n", ans);
    return 0;
}

