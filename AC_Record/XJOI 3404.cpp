//XJOI 3404
#include<bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y){
    long long m = x % y;
    while(m){
        x = y;
        y = m;
        m = x % y;
    }
    return y;
}
int main(){
    long long n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    cout << (n / a) * p + (n / b * q) - (n / (a * b / gcd(a, b)) * min(p, q));
    return 0;
}