//XJOI 1541
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int x, y, val;
};
int n, f[110], t, x, y;
int l = 0;
Node a[20010];
int get(int x){
    if(f[x] == x) return x;
    f[x] = get(f[x]);
    return f[x];
}
bool cmp(Node x, Node y){
    return x.val < y.val;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) f[i] = i;
    for(int i = 1; i <= n; i++)
     for(int j = 1; j <= n; j++){
        scanf("%d", &t);
        if(t == 0){
            x = get(i);
            y = get(j);
            if(x != y) f[y] = x;
        } else {
            l++;
            a[l].x = i; a[l].y = j; a[l].val = t;
        }
     }
    int num = 0;
    for(int i = 1; i <= n; i++)
     if(f[i] == i) num++;
    printf("%d\n", num - 1);
    sort(a + 1, a + l + 1, cmp);
    int ans = 0;
    int i = 1;
    while(num > 1){
        x = get(a[i].x);
        y = get(a[i].y);
        while(x == y){
            i++;
            x = get(a[i].x);
            y = get(a[i].y);
        }
        ans += a[i].val;
        f[y] = x;
        i++;
        num--;
    }
    printf("%d", ans);
    return 0;
}