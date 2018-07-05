//XJOI 3273
#include<bits/stdc++.h>
using namespace std;
int n, a1, a2;
int main(){
    scanf("%d", &n);
    if(n == 1){
        printf("2");
        return 0;
    }
    a1 = 2;
    for(int i = 2; i <= n; i++){
        a2 = a1 + 4 * i - 3;
        a1 = a2;
    }
    cout << a1;
    return 0;
}