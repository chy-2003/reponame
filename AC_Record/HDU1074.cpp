#include<bits/stdc++.h>
using namespace std;
int n, deadline[20], cost[20];
char name[20][110];
int dp_cost[1 << 20], dp_redu[1 << 20], dp_from[1 << 20], q[1 << 20], l, r;
void print(int x){
    if(x == 0) return;
    print(dp_from[x]);
    int t = dp_from[x];
    for(int i = 0; i < n; i++)
        if(((x >> i) & 1) != ((t >> i) & 1)){
            printf("%s\n", name[i]);
            break;
        }
    return;
}
void work(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", name[i]);
        scanf("%d%d", &deadline[i], &cost[i]);
    }
    memset(dp_cost, 255, sizeof(dp_cost));
    memset(dp_redu, 255, sizeof(dp_redu));
    dp_cost[0] = 0;
    dp_redu[0] = 0;
    l = 0; r = 0;
    r++;
    q[r] = 0;
    while(l < r){
        l++;
        int rec_cost = dp_cost[q[l]];
        int rec_redu = dp_redu[q[l]];
        int bit = q[l];
        for(int i = 0; i < n; i++){
            if((bit >> i) & 1) continue;
            int x = bit | (1 << i);
            if(dp_redu[x] == -1 || dp_redu[x] > dp_redu[bit] + max(0, dp_cost[bit] + cost[i] - deadline[i])){
                dp_redu[x] = dp_redu[bit] + max(0, dp_cost[bit] + cost[i] - deadline[i]);
                dp_cost[x] = dp_cost[bit] + cost[i];
                dp_from[x] = bit;
                r++;
                q[r] = x;
            }
        }
    }
    printf("%d\n", dp_redu[(1 << n) - 1]);
    print((1 << n) - 1);
    return;
} 
int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) work();
    return 0;
}

