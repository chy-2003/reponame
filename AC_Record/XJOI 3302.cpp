//XJOI 3302
#include<cstdio>
#include<algorithm>
using namespace std;
long long m, b;
long long x, y, ans;
int main(){
    scanf("%lld%lld", &m, &b);
    x = 0; y = b;
    ans = b * (b + 1) / 2;
    y--;
    x += m;
    while(y >= 0){
        ans = max(ans, (x + 1) * y * (y + 1) / 2 + (x + 1) * x / 2 * (y + 1));
        y--;
        x += m;
    }
    printf("%lld", ans);
    return 0;
}