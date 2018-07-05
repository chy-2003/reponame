//XJOI 3289
#include<bits/stdc++.h>
using namespace std;
int n, m, a[110][110], t[50];
char ch;
int main(){
    scanf("%d%d", &n, &m);getchar();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%c", &ch);
            a[i][j] = ch - 'a' + 1;
        }getchar();
    }
    int ans = 0;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            t[1] = 0; t[3] = 0; t[5] = 0; t[6] = 0;
            t[a[i][j]] = 1; t[a[i][j + 1]] = 1;
            t[a[i + 1][j]] = 1; t[a[i + 1][j + 1]] = 1;
            if(t[1] && t[3] && t[5] && t[6]) ans++;
        }
    }
    printf("%d", ans);
    return 0;
}