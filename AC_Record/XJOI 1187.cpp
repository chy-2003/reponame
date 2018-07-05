//XJOI 1187
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    for(int i = sqrt(n); i >= 1; i++)
     if(n % i == 0){
        printf("%d %d", min(i, n / i), max(i, n / i));
        return 0;
     }
    return 0;
}