//XJOI 1503
#include<bits/stdc++.h>
using namespace std;
int l, r, h, hight[10010];
int main(){
    memset(hight, 0, sizeof(hight));
    while(scanf("%d%d%d", &l, &h, &r) == 3){
        for(int i = l; i < r; i++) hight[i] = max(hight[i], h);
    }
    for(int i = 1; i <= 10000; i++)
     if(hight[i] != hight[i - 1]){
        printf("%d %d ", i, hight[i]);
     }
    return 0;
}