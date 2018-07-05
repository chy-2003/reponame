//XJOI 3308
#include<bits/stdc++.h>
using namespace std;
int n, m, sa[110], bb;
string s[110];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 1; i <= n; i++) s[i] = s[i];
    int ans = 0;
    memset(sa, 0, sizeof(sa));
    for(int i = 1; i <= m; i++){
        bb = 1;
        for(int j = 2; j <= n; j++){
            if(sa[j]) continue;
            if(s[j][i - 1] < s[j - 1][i - 1]){
                ans++;
                bb = 0;
                break;
            }
        }
        if(bb){
            for(int j = 2; j <= n; j++){
                if(sa[j]) continue;
                if(s[j][i - 1] != s[j - 1][i - 1]) sa[j] = 1;
            }
        }
    }
    printf("%d", ans);
    return 0;
}