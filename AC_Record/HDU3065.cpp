#include <cstdio>
#include <iostream>
#include <cstring>
int trie[50010][27], f[50010], used = 1;
int fail[50010];
//int lp = 1, lin[1010], nxt[1010];
//void add_(int x, int y) { lin[++lp] = y; nxt[lp] = f[x]; f[x] = lp; return; }
char ch[1010][60], st[2000010];
int lc;
int n, cnt[1010];
int getnum(char ch) {
    if(ch >= 'A' && ch <= 'Z') return ch - 'A';
    return 26;
}
void add(int x) {
    int c, t = 1;
    int len = strlen(ch[x]);
    for(int i = 0; i < len; ++i) {
        c = getnum(ch[x][i]);
        if(trie[t][c] == 0) trie[t][c] += ++used;
        t = trie[t][c];
    }
//    add_(t, x);
	f[t] = x;
    return;
}
int l, r, q[50010];
void Build() {
    l = 0; r = 1;
    q[1] = 1;
    for(int i = 0; i < 27; ++i) trie[0][i] = 1;
    int x, c;
    while(l < r) {
        x = q[++l];
        for(int i = 0; i < 27; ++i) {
            if(trie[x][i] == 0) {
                trie[x][i] = trie[fail[x]][i];
                continue;
            }
            fail[trie[x][i]] = trie[fail[x]][i];
            q[++r] = trie[x][i];
        }
    }
    return;
}
void Query() {
    int x = 1, c, k; 
    for(int i = 0; i < lc; ++i) {
        c = getnum(st[i]);
        k = trie[x][c];
        while(k > 1) {
//            for(int t = f[k]; t; t = nxt[k]) cnt[lin[t]]++;
			if(f[k] != 0) cnt[f[k]]++;
            k = fail[k];
        }
        x = trie[x][c];
    }
    return;
}
void Print() {
    for(int i = 1; i <= n; ++i) {
        if(cnt[i] == 0) continue;
        printf("%s: %d\n", ch[i], cnt[i]);
    }
    return;
}
int main() {
    while(scanf("%d", &n) == 1) {
//        lp = 1; 
        memset(f, 0, sizeof(f)); memset(trie, 0, sizeof(trie)); used = 1; memset(cnt, 0, sizeof(cnt));
        memset(fail, 0, sizeof(fail));
        for(int i = 1; i <= n; ++i) scanf("%s", ch[i]);
        for(int i = 1; i <= n; ++i) add(i);
        Build();
        getchar();gets(st); lc = strlen(st);
        Query();
        Print();
    }
    return 0;
}
