//XJOI 3428
#include<bits/stdc++.h>
using namespace std;
double a, b, t, ans;
int main(){
    cin >> a >> b;
    if(a > b) swap(a, b);
    t = (a + b - sqrt(a * a + b * b - a * b)) / 6;
    ans = 4 * t * t * t - 2 * t * t * (a + b) + a * b * t;
    printf("%.5f", ans);
    return 0;
}