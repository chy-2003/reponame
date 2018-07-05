//XJOI 1243
#include<bits/stdc++.h>
using namespace std;
int n, k, a[100010];
char ch;
char getch(){
    char ch = getchar();
    while(ch < 'A' || ch > 'Z') ch = getchar();
    return ch;
}
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        ch = getch();
        a[i] = ch - 'A';
    }
    if(k > 2){
        int ans = 0;
        for(int i = 2; i <= n; i++)
         if(a[i] == a[i - 1]){
            ans++;
            a[i] = a[i + 1] - 1;
         }
        printf("%d", ans);
    } else{
        int ans = 0;
        for(int i = 1; i <= n; i++)
         if(a[i] % 2 != i % 2) ans++;
        int t = 0;
        for(int i = 1; i <= n; i++)
         if(a[i] % 2 == i % 2) t++;
        ans = min(ans, t);
        printf("%d", ans);
    }
    return 0;
}