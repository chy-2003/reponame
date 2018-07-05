//XJOI 1327
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int x, y;
};
int n;
Node a[110];
bool cmp(Node x, Node y){
    return x.x < y.x;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
     scanf("%d%d", &a[i].x, &a[i].y);
    sort(a + 1, a + n + 1, cmp);
    int l = 0, r = 0;
    l = a[1].x; r = a[1].y;
    for(int i = 2; i <= n; i++)
     if(a[i].x <= r){
        r = max(r, a[i].y);
     } else{
        printf("%d %d\n", l, r);
        l = a[i].x; r = a[i].y;
     }
    printf("%d %d\n", l, r);
    return 0;
}