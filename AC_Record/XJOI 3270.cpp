//XJOI 3270
#include<bits/stdc++.h>
using namespace std;
int C[50][50], n, m;
int main(){
    cin >> n >> m;
    C[0][0] = 1;
    for(int i = 1; i <= n + m - 1; i++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j++)
         C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    cout << C[n + m - 1][m - 1];
    return 0;
}