//XJOI 3396
#include<bits/stdc++.h>
using namespace std;
long long ll, ans;
long long t(long long x){
    return (3 * x * x + x) / 2;
}
int main(){
    cin >> ll;
    ans = 0;
    for(long long i = 1; t(i) <= ll; i++)
     if((ll - t(i)) % 3 == 0) ans++;
    printf("%lld", ans);
    return 0;
}