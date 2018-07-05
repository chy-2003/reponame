//XJOI 3590
#include <bits/stdc++.h>
using namespace std;
int n;
struct Node{
    int x, y;
};
Node a[100010];
bool cmp(Node x, Node y){
    return x.x < y.x || (x.x == y.x && x.y < y.y);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++) printf("%d %d\n", a[i].x, a[i].y);
    return 0;
}