//XJOI 3383
#include<bits/stdc++.h>
using namespace std;
int x;
int main(){
    scanf("%d", &x);
    if(x < 0) x = -x;
    for(int i = sqrt(x * 2); ; i++){
        if((i + 1) * i / 2 < x) continue;
        if(((i + 1) * i / 2 - x) % 2 == 0){
            printf("%d", i);
            break;
        }
    }
    return 0;
}