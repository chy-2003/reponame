//XJOI 3390
#include<bits/stdc++.h>
using namespace std;
int n, i;
int t(int x){
    int y = (x - 1) / 2;
    int num = 4 * ((y * y + 1) / 2);
    num += 4 * (y / 2);
//  if(y % 2 == 0)
    num++;
//  printf("%d %d\n", x, num);
    return num;
}
int main(){
    scanf("%d", &n);
    if(n == 3){
        printf("5");
        return 0;
    }
    i = 1;
    while(t(i) < n) i += 2;
//  if(n % 4 == 3) printf("%d", i + 2); else
    printf("%d", i);
    return 0;
}