#include<bits/stdc++.h>
using namespace std;
int n, t[110], l, ans, cnt, minnum, id;
struct Node{
    int x, y;
};
Node a[110];
bool cmp(Node x, Node y){
    return (x.x < y.x) || (x.x == y.x && x.y > y.y);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i].x);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i].y);
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++){
        cnt = 0;
        for(int j = 1; j <= l; j++)
            if(a[t[j]].x <= a[i].x) cnt++;
        if(cnt < a[i].x){
            l++;
            t[l] = i;
        } else{
            minnum = 2147483647;
            for(int j = 1; j <= l; j++)
                if(a[t[j]].x <= a[i].x && minnum > a[t[j]].y){
                    minnum = a[t[j]].y;
                    id = j;
                }
            if(minnum < a[i].y){
                t[id] = i;
            }
        }
    }
    ans = 0;
    for(int i = 1; i <= l; i++) ans += a[t[i]].y;
    printf("%d", ans);
    return 0;
}