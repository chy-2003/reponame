//XJOI 3265
#include<bits/stdc++.h>
using namespace std;
long long n, a1, a2, a3;
int main(){
    cin >> n;
    if(n == 1){
        printf("1");
        return 0;
    }
    if(n == 2){
        printf("2");
        return 0;
    }
    a1 = 1;
    a2 = 2;
    for(int i = 3; i <= n; i++){
        a3 = a1 + a2;
        a1 = a2;
        a2 = a3;
    }
    cout << a2;
    return 0;
}