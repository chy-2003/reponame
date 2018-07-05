#include<bits/stdc++.h>
#define LL long long
using namespace std;

const LL MAXN = 200010;
const LL MAXM = 200010;

LL n, m, l[MAXN], r[MAXN], ans[MAXN];
struct Node{
    LL left_link, right_link, location;
};
Node line[MAXN];
struct node{
    LL x, location;
};
node a[MAXN];
struct cmp{
    bool operator () (int x, int y){
        return line[x].right_link > line[y].right_link;
    }
};
priority_queue<int, vector<int>, cmp> pq;


bool cmp1(Node x, Node y){
    return x.left_link < y.left_link;
}
bool cmp2(node x, node y){
    return x.x < y.x;
}

LL tt, t;

int main(){
    scanf("%I64d%I64d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%I64d%I64d", &l[i], &r[i]);
    for(int i = 1; i < n; i++) line[i].left_link = l[i + 1] - r[i], line[i].right_link = r[i + 1] - l[i], line[i].location = i;
    sort(line + 1, line + n, cmp1);
    for(int i = 1; i <= m; i++){
        scanf("%I64d", &t);
        a[i].x = t, a[i].location = i;
    }
    sort(a + 1, a + m + 1, cmp2);
    tt = 1;
    memset(ans, 255, sizeof(ans));
    for(int i = 1; i <= m; i++){
        while(tt < n && line[tt].left_link <= a[i].x){
            pq.push(tt); tt++;
        }
        if(pq.empty()) continue;
        t = pq.top();
        pq.pop();
        if(line[t].right_link < a[i].x){
            printf("No\n");
            return 0;
        } else{
            ans[line[t].location] = a[i].location;
        }
    }
    for(int i = 1; i < n; i++)
        if(ans[i] == -1){
            printf("No\n");
            return 0;
        }
    printf("Yes\n");
    for(int i = 1; i < n; i++)
        if(i == 1) printf("%I64d", ans[i]); 
        else printf(" %I64d", ans[i]);
    printf("\n");
    return 0;
}
