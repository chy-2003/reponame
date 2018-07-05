//XJOI 3385
#include<bits/stdc++.h>
using namespace std;
int n, x, y;
int main(){
    scanf("%d%d%d", &n, &x, &y);
    if((x == n / 2 || x == n / 2 + 1) && (y == n / 2 || y == n / 2 + 1))
     printf("NO"); else printf("YES");
    return 0;
}