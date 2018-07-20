#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10010, MAXM = 100010;

int n, m, num, val1[MAXN], val2[MAXN];

int degree[MAXN];

int lp1 = 0, f1[MAXN], nxt1[MAXM << 1], lin1[MAXM << 1];
void add1(int x, int y){nxt1[++lp1] = f1[x]; f1[x] = lp1; lin1[lp1] = y; return; }

int lp2 = 0, f2[MAXN], nxt2[MAXM << 1], lin2[MAXM << 1];
void add2(int x, int y){nxt2[++lp2] = f2[x]; f2[x] = lp2; lin2[lp2] = y; degree[y]++; return; }

int get_int(){
    int t = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9'){
        t = t * 10 + ch - '0';
        ch = getchar();
    }
    return t;
}



int vis[MAXN], rec[MAXN], top[MAXN], inst[MAXN], rec2[MAXN];
int ls = 0, st[MAXN];


void tarjan(int x){
    st[++ls] = x;
    rec[x] = ls;
    top[x] = ls;
    vis[x] = 1;
    inst[x] = 1;
    for(int t = f1[x]; t; t = nxt1[t]){
        if(vis[lin1[t]] == 1){
            if(inst[lin1[t]] == 0){
                continue;
            } else
            top[x] = min(top[x], top[lin1[t]]);
        } else {
            tarjan(lin1[t]);
            top[x] = min(top[x], top[lin1[t]]);
        }
    }
    if(top[x] == rec[x]){
        int sum = 0;
        num++;
        while(st[ls] != x){
            sum += val1[st[ls]];
            rec2[st[ls]] = num;
            inst[st[ls]] = 0;
            ls--;
        }
        sum += val1[st[ls]];
        rec2[st[ls]] = num;
        inst[st[ls]] = 0;
        ls--;
        val2[num] = sum;
    }
    return;
}


void dfs(int x){
    vis[x] = 1;
    for(int t = f1[x]; t; t = nxt1[t]){
        if(rec2[x] != rec2[lin1[t]]){
            add2(rec2[x], rec2[lin1[t]]);
        }
        if(!vis[lin1[t]]) dfs(lin1[t]);
    }
    return;
}


int lq = 0, rq = 0, q[MAXN];
void addq(int x) {q[++rq] = x; return;}
int dp[MAXN];
int ans = 0;


int main(){
    n = get_int(); m = get_int();
    for(int i = 1; i <= n; i++) val1[i] = get_int();
    for(int i = 1; i <= m; i++){
        int x = get_int(), y = get_int();
        add1(x, y);
    }
    memset(vis, 0, sizeof(vis));
    num = 0;
    for(int i = 1; i <= n; i++)
        if(vis[i] == 0) ls = 0, tarjan(i);
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++)
        if(vis[i] == 0) dfs(i);
    for(int i = 1; i <= num; i++) dp[i] = val2[i];
    for(int i = 1; i <= num; i++)
        if(degree[i] == 0) addq(i);
    while(lq < rq){
        lq++;
        for(int t = f2[q[lq]]; t; t = nxt2[t]){
            dp[lin2[t]] = max(dp[lin2[t]], dp[q[lq]] + val2[lin2[t]]);
            degree[lin2[t]]--;
            if(degree[lin2[t]] == 0) addq(lin2[t]);
        }
    }
    for(int i = 1; i <= num; i++) ans = max(ans, dp[i]);
    printf("%d\n", ans);
    return 0;
}


