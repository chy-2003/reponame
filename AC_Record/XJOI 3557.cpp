//XJOI 3557
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c, t = 0;
    while(scanf("%d%d%d", &a, &b, &c) == 3){
        if(t != 0) printf("\n");
        t++;
        printf("%d\n", a + b + c);
    }
    return 0;
}