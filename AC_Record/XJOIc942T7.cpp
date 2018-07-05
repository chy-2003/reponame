#include<bits/stdc++.h>
using namespace std;
struct Node{
    int x, y;
};
int n, ans, la;
Node a[10010];
bool cmp(Node x, Node y){
    return (x.y < y.y);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
    sort(a + 1, a + n + 1, cmp);
    la = 0;
    ans = 0;
    for(int i = 1; i <= n; i++)
        if(a[i].x >= la){
            ans++; la = a[i].y;
        }
    printf("%d", ans);
    return 0;
}