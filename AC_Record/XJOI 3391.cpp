//XJOI 3391
#include<bits/stdc++.h>
using namespace std;
int a, b, c;
int main(){
    cin >> a >> b >> c;
    cout << b * c + (a - 1) * ( c - 1) + (a - 1) * b;
    return 0;
}