#include<bits/stdc++.h>
using namespace std;
struct Node{
    int maxnum, lazy;
};
int C, S, R, O, D, N, t;
Node tree[240010];
int ask(int i, int l, int r){
    if(O <= l && r <= D) return tree[i].maxnum + tree[i].lazy;
    int t1 = 0, t2 = 0;
    if(O <= (l + r) >> 1) t1 = ask(i << 1, l, (l + r) >> 1);
    if(D > (l + r) >> 1) t2 = ask((i << 1) + 1, ((l + r) >> 1) + 1, r);
    return max(t1, t2) + tree[i].lazy;
}
void add(int i, int l, int r){
    if(O <= l && r <= D){
        tree[i].lazy += N;
        return;
    }
    if(O <= (l + r) >> 1) add(i << 1, l, (l + r) >> 1);
    if(D > (l + r) >> 1) add((i << 1) + 1, ((l + r) >> 1) + 1, r);
    tree[i].maxnum = max(tree[i << 1].maxnum + tree[i << 1].lazy, tree[(i << 1) + 1].maxnum + tree[(i << 1) + 1].lazy);
    return;
}
int main(){
    scanf("%d%d%d", &C, &S, &R);
    for(int i = 1; i <= R; i++){
        scanf("%d%d%d", &O, &D, &N);
        D--;
        t = ask(1, 1, C);
        if(t + N > S){
            printf("N\n");
        } else{
            printf("T\n");
            add(1, 1, C);
        }
    }
    return 0;
}