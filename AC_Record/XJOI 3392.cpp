//XJOI 3392
#include<bits/stdc++.h>
using namespace std;
int n;
long long ans, num;
struct Node{
    long long k, a;
};
bool cmp(Node x, Node y){
    return x.k < y.k;
}
Node b[100010];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d", &b[i].k, &b[i].a);
    sort(b + 1, b + n + 1, cmp);
    num = b[1].a; ans = b[1].k;
    for(int i = 2; i <= n; i++){
        while(ans < b[i].k && num > 1){
            num = (num + 3) / 4;
            ans++;
        }
        if(ans == b[i].k) num = max(num, b[i].a);
        else{
            ans = b[i].k;
            num = b[i].a;
        }
    }
    while(num > 1){
        num = (num + 3) / 4;
        ans++;
    }
    printf("%d", ans);
    return 0;
}