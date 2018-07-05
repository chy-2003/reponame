//XJOI 1124
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, t, b;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        if(i % 3 != 0) continue;
        b = 0;
        t = i;
        while(t){
            if(t % 10 == 5) b = 1;
            t /= 10;
        }
        if(b) printf("%d\n", i);
    }
    return 0;
}