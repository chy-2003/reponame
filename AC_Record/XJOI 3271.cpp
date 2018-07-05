//XJOI 3271
#include<bits/stdc++.h>
using namespace std;
long long n, a[30];
int main(){
    cin >> n;
    a[1] = 0;
    a[2] = 1;
    for(int i = 3; i <= n; i++)
     a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
    cout << a[n];
    return 0;
}