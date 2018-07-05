//XJOI 3286
#include<bits/stdc++.h>
using namespace std;
long long a, b, c;
long long pow(long long x){
    if(x == 0) return 1 % c;
    long long t = pow(x / 2);
    t = (t * t) % c;
    if(x % 2 == 1) t = (t * a) % c;
//  cout << x << " " << t << endl;
    return t;
}
int main(){
    cin >> a >> b >> c;
    cout << pow(b);
    return 0;
}