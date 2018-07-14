#include<bits/stdc++.h>
using namespace std;
const long long Mo =998244353;
long long a, b, c;
long long ans1, ans2, ans3;
long long f[5010][5010];
long long h(int x){
    long long ans = 1;
    for(int i = 2; i <= x; i++) ans = (ans * i) % Mo;
    return ans;
}
int main(){
    cin >> a >> b >> c;
    f[0][0] = 1;
    for(int i = 1; i <= 5000; i++){
        f[i][0] = 1;
        for(int j = 1; j <= 5000; j++) f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % Mo;
    }
//    printf("*\n");
    ans1 = 0;
    for(int i = 0; i <= min(a, b); i++)
        ans1 = (ans1 + (((f[a][i] * f[b][i]) % Mo) * h(i)) % Mo) % Mo;
    
//    printf("*\n");
    ans2 = 0;
    for(int i = 0; i <= min(a, c); i++)
        ans2 = (ans2 + (((f[a][i] * f[c][i]) % Mo) * h(i)) % Mo) % Mo;
    
//    printf("*\n");
    ans3 = 0;
    for(int i = 0; i <= min(c, b); i++)
        ans3 = (ans3 + (((f[c][i] * f[b][i]) % Mo) * h(i)) % Mo) % Mo;

//    printf("*\n");
    ans1 = ((ans1 * ans2) % Mo) * ans3 % Mo;
    cout << ans1 << endl;
    return 0;
}   

