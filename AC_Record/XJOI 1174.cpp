//XJOI 1174
#include<bits/stdc++.h>
using namespace std;
bool is_prime(int x){
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++)
     if(x % i == 0) return false;
    return true;
}
int main(){
    int n, t;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &t);
        if(is_prime(t)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}