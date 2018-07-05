#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long gcd(long long x, long long y){
    long long t = x % y;
    while(t){
        x = y; y = t; t = x % y;
    }
    return y;
}
int main(){
    cin >> n >> m;
    cout << gcd(n, m);
    return 0;
}