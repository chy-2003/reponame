//XJOI 1064
#include<bits/stdc++.h>
using namespace std;
int n, m, x, y, degree[1010];
int ll = 0, first[1010], next[10010], val[10010];
void add(int x, int y){
    ll++;
    next[ll] = first[x];
    val[ll] = y;
    first[x] = ll;
    return;
}
struct cmd
{
    bool operator () (int x, int y){
        return x > y;
    }
};
int t;
priority_queue<int, vector<int>, cmd> pq;
int main(){
    memset(first, 0, sizeof(first));
    scanf("%d%d", &n, &m);
    memset(degree, 0, sizeof(degree));
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        add(x, y);
        degree[y]++;
    }
    for(int i = 1; i <= n; i++) if(degree[i] == 0) pq.push(i);
    while(!pq.empty()){
        printf("%d ", pq.top());
        t = pq.top();
        pq.pop();
        for(int i = first[t]; i; i = next[i]){
            degree[val[i]]--;
            if(degree[val[i]] == 0){
                pq.push(val[i]);
            }
        }
    }
    return 0;
}