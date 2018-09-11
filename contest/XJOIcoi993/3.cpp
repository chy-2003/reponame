#include <bits/stdc++.h>
using namespace std;
int n, a[100010];
int main() {
    scanf("%d", &n);
    if(n == 2) {
        printf("Impossible\n");
        return 0;
    }
    memset(a, 0, sizeof(a));
    for(int i = 1; i < n; i++)
        a[1LL * i * i % n] = 1;
    for(int i = 1; i < n; i++) printf("%d", 1 - a[i]);
    printf("\n");
    return 0;
}
