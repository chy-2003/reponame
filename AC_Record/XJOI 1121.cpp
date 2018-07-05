//XJOI 1121
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a = 0, b = 0, c = 0, t;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &t);
        if(t == 0) b++; else
        if(t < 0) c++; else a++;
    }
    printf("%d\n%d\n%d\n", a, b, c);
    return 0;
}