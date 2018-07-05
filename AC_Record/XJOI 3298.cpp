//XJOI 3298
#include<bits/stdc++.h>
using namespace std;
int a, b, ans = 0;
int main(){
    cin >> a >> b;
    if(a == b){
        printf("infinity");
        return 0;
    }
    if(a < b){
        printf("0");
        return 0;
    }
    a -= b;
    for(int i = 1; i * i <= a; i++){
        if(a % i != 0) continue;
        if(i > b)ans++;
        if(a / i != i && a / i > b) ans++;
    }
    printf("%d", ans);
    return 0;
}