//XJOI 1011
#include<bits/stdc++.h>
using namespace std;
int a = 1, b = 2, c = 3, n, num = 0;
void work(int t, int x, int y, int z){
    if(t == 0) return;
    work(t - 1, x, z, y);
    printf("%d->%d\n", x, z);
    num++;
    work(t - 1, y, x, z);
    return;
}
int main(){
    scanf("%d", &n);
    work(n, a, b, c);
    printf("tot=%d", num);
    return 0;
}