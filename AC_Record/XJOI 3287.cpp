#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int ans[MAXN], n, t;
struct Node{
    int value, pos;
    Node(int value_ = 0, int pos_ = 0){value = value_; pos = pos_; }
};
Node a[MAXN];
bool cmp(Node x, Node y){return x.value < y.value;}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &t);
        a[i] = Node(t, i);
    }
    sort(a + 1, a + n + 1, cmp);
    a[0].value = -1;
    for(int i = 1; i <= n; i++)
        if(a[i].value == a[i - 1].value) ans[a[i].pos] = ans[a[i - 1].pos];
        else ans[a[i].pos] = i;
    for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}
