//XJOI 1110
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
    int y, m;
    scanf("%d%d", &y, &m);
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
        printf("31");
        return 0;
    }
    if(m == 4 || m == 6 || m == 9 || m == 11){
        printf("30");
        return 0;
    }
    if((y % 400 == 0) || (y % 4 == 0) && (y % 100 != 0)) printf("29"); else printf("28");
    return 0;
}