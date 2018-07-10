#include<bits/stdc++.h>
using namespace std;
int n, k, len, id, l, trie[2600010], rec[2600010];
bool win[100010], lose[100010];
char ch[100010];
int B(char ch){ return ch - 'a' - 25;}
void dfs(int x){
    win[x] = false;
    lose[x] = false;
    int leaf = true;
    for(int i = 1; i <= 26; i++){
        if(rec[x * 26 + i - 26] == 0) continue;
        leaf = false;
        dfs(rec[x * 26 + i - 26]);
        win[x] |= !win[rec[x * 26 + i - 26]];
        lose[x] |= !lose[rec[x * 26 + i - 26]];
    }
    if(leaf) lose[x] = true;
//    printf("x = %d     win = %d    lose = %d\n", x, win[x], lose[x]);
    return;
}
int main(){
    scanf("%d%d", &n, &k);
    l = 1;
    for(int i = 1; i <= n; i++){
        scanf("%s", ch + 1);
        len = strlen(ch + 1);
        id = 1;
        for(int j = 1; j <= len; j++){
            if(rec[id * 26 + B(ch[j])] == 0){
                l++;
                rec[id * 26 + B(ch[j])] = l;
            }
            id = rec[id * 26 + B(ch[j])];
        }
    }
    dfs(1);
    if(!win[1]) printf("Second\n"); else
    if(win[1] && lose[1]) printf("First\n"); else
    if(win[1] && !lose[1]) 
        if(k % 2 == 1) printf("First\n"); else printf("Second\n");
    return 0;
}
