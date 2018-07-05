//XJOI 3268
#include<bits/stdc++.h>
using namespace std;
long long n, a, b, c, d;
int main(){
    cin >> n;
    a = 1;
    b = 3;
    for(long long i = 2; i <= n; i++){
        c = b;
        d = a * 3 + b * 3;
        a = c;
        b = d;
    }
    cout << a + b;
    return 0;
}