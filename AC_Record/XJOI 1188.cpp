//XJOI 1188
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int aa[10010];
    memset(aa, 0, sizeof(aa));
    aa[0] = 1;
    for(int i = a; i <= c; i++)
     if(aa[i - a]) aa[i] = 1;
    for(int i = b; i <= c; i++)
     if(aa[i - b]) aa[i] = 1;
    if(aa[c]) printf("Yes"); else printf("No");
    return 0;
}