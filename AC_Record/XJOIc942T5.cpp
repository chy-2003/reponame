#include<bits/stdc++.h>
using namespace std;
int n, ans = 0;
void move(int x, int a, int b, int c){
    if(x == 0) return;
    move(x - 1, a, c, b);
    printf("%d->%d\n", a, c);
    ans++;
    move(x - 1, b, a, c);
    return;
}
int main(){
    scanf("%d", &n);
    move(n, 1, 2, 3);
    printf("tot=%d", ans);
    return 0;
}