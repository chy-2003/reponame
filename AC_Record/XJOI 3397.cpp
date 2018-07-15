#include<bits/stdc++.h>
using namespace std;
int n, a[100010];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int ans = 0;
    for(int i = n; i >= 1; i--){
        if(a[i] / 2 <= ans) break;
        for(int j = i - 1; j >= 1; j--){
            if(a[j] <= ans) break;
            ans = max(ans, a[i] % a[j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}

