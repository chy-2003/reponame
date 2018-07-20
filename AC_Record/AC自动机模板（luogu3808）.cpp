#include<cstdio>
#include<cstring>
#include<cctype>
int n;
int lc; char ch[1000010];
int trie[1000010][26], tag[1000010], lt = 1, nxt[1000010];
int lq, rq, q[1000010];
int ans;
int x, k, t;
int recc[1000010];
int get_int(){
    int t = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9'){
        t = t * 10 + ch - '0';
        ch = getchar();
    }
    return t;
}
void get_st(){
    lc = 0;
    char chh = getchar();
    while(chh < 'a' || chh > 'z') chh = getchar();
    while(chh >= 'a' && chh <= 'z'){
        ch[lc++] = chh;
        chh = getchar();
    }
    return;
}
int c;
int main(){
    n = get_int();
    for(int i = 1; i <= n; ++i){
        get_st();
        x = 1;
        for(int j = 0; j < lc; ++j){
            c = ch[j] - 'a';
            if(trie[x][c] == 0) {
                trie[x][c] = ++lt;
            }
            x = trie[x][c];
        }
        ++tag[x];
    }
    for(int i = 0; i < 26; ++i) trie[0][i] = 1;
    nxt[1] = 0;
    lq = 0; rq = 1; q[1] = 1;
    while(lq < rq){
        ++lq;
        x = q[lq];
        for(int i = 0; i < 26; ++i){
            if(trie[x][i] == 0) {
                trie[x][i] = trie[nxt[x]][i];
                continue;
            }
            q[++rq] = trie[x][i];
            t = nxt[x];
            nxt[trie[x][i]] = trie[t][i];
        }
    }
    scanf("%s", ch);
    ans = 0;
    x = 1;
    lc = strlen(ch);
    memset(recc, 0, sizeof(recc));
    for(int i = 0; i < lc; ++i){
        c = ch[i] - 'a';
        k = trie[x][c];
        while(k > 1){
            if(recc[k] == 1) break;
            ans += tag[k];
            tag[k] = -1;
            recc[k] = 1;
            k = nxt[k];
        }
        x = trie[x][c];
    }
    printf("%d\n", ans);
    return 0;
}


