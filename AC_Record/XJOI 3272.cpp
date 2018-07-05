//XJOI 3272
#include<bits/stdc++.h>
using namespace std;
long long m, n, a[30], C[30][30];
int main(){
    cin >> m >> n;
    a[1] = 0;
    a[2] = 1;
    for(int i = 3; i <= n; i++)
     a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
    C[0][0] = 1;
    for(int i = 1; i <= m; i++){
        C[i][0] = 1;
        for(int j = 1; j <= i + 1; j++)
         C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    cout << a[n] * C[m][n];
    return 0;
}