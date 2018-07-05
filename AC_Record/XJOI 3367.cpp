//XJOI 3367
#include <bits/stdc++.h>
using namespace std;
long long ans;
int n, m;
int main(){
    cin >> n >> m;
    ans = 1;
    for(int i = 1; i <= n; i++) ans = (ans * m) % 1000000007;
    cout << ans;
    return 0;
}