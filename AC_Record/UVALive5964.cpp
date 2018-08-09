#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#define ULL unsigned long long
using namespace std;
ULL sum[3000010], ans[3000010];
int main() {
    for(int i = 1; i <= 3000000; i++) sum[i] = sum[i - 1] + i - 1;
    for(int i = 2; i <= 3000000; i++) {
        for(int j = 2; j * i <= 3000000; j++)
            sum[i * j] -= sum[i] * j;
    }
    for(int i = 2; i <= 3000000; i++) {
        ans[i] += ans[i - 1];
        for(int j = 1; j * i <= 3000000; j++) 
            ans[i * j] += sum[i] * i * j;
    }
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        printf("Case %d: %llu\n", i, ans[t]);
    }
    return 0;
}

