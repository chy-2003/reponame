#include<bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator () (int x, int y){
        return x > y;
    }
};
priority_queue<int, vector<int>, cmp> pq;
int n, x, ans = 0;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) { scanf("%d", &x); pq.push(x); };
    while(pq.size() > 1){
        int t1 = pq.top(); pq.pop();
        int t2 = pq.top(); pq.pop();
        ans += t1 + t2; pq.push(t1 + t2);
    }
    printf("%d\n", ans);
    return 0;
}

