//XJOI 3387
#include<bits/stdc++.h>
using namespace std;
long long n, MO = 1000000007;
long long pow(long long x){
    if(x == 0) return 1;
    long long t = pow(x / 2);
    t = t * t % MO;
    if(x % 2 == 1) t = t * 2 % MO;
    return t;
}
int main(){
    cin >> n;
    n = pow(n);
    long long m = n + 1;
    if(n % 2 == 0) n /= 2;
    if(m % 2 == 0) m /= 2;
    cout << n *m % MO;
    return 0;
}