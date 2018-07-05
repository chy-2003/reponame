//XJOI 3266
#include<bits/stdc++.h>
using namespace std;
long long ans;
int n;
int main(){
    ans = 1;
    cin >> n;
    if(n == 1){
        printf("3");
        return 0;
    }
    if(n == 0){
        printf("0");
        return 0;
    }
    for(int i = 1; i <= n; i++) ans *= 2;
    if(n % 2 == 0) ans += 2; else ans -= 2;
    cout << ans;
    return 0;
}