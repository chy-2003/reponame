//XJOI 3290
#include<bits/stdc++.h>
using namespace std;
int n, m, a[110][110], num[110];
char ch;
int main(){
    memset(num, 0, sizeof(num));
    scanf("%d%d", &n, &m); getchar();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%c", &ch);
            a[i][j] = ch - '0';
            num[j] = max(num[j], a[i][j]);
        } getchar();
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == num[j]){
                ans++;
                break;
            }
        }
    }
    printf("%d", ans);
    return 0;
}