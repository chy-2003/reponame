//XJOI 1493
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int No, So;
};
int n, m;
Node a[5010];
bool cmp(Node x, Node y){
    return x.So > y.So || (x.So == y.So && x.No < y.No);
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
     scanf("%d%d", &a[i].No, &a[i].So);
    sort(a + 1, a + n + 1, cmp);
    m = floor(m * 1.5);
    while(a[m].So == a[m + 1].So) m++;
    printf("%d %d\n", a[m].So, m);
    for(int i = 1; i <= m; i++)
     printf("%d %d\n", a[i].No, a[i].So);
    return 0;
}