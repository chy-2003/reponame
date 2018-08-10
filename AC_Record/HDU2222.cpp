#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;
int trie[500010][26], fail[500010], rec[500010], n, used;
char ch[1000010];
int lc;
void add() {
    int t = 1, x;
    for(int i = 0; i < lc; ++i) {
        x = ch[i] - 'a';
        if(trie[t][x] == 0) trie[t][x] = ++used;
        t = trie[t][x];
    }
    ++rec[t];
    return;
}
int l, r, q[500010];
void get_fail() {
    for(int i = 0; i < 26; ++i) trie[0][i] = 1;
    fail[1] = 0;
    l = 0; r = 1; q[1] = 1;
    int x;
    while(l < r) {
        x = q[++l];
        for(int i = 0; i < 26; ++i) {
            if(trie[x][i] == 0) {
                trie[x][i] = trie[fail[x]][i];
                continue;
            }
            q[++r] = trie[x][i];
            fail[trie[x][i]] = trie[fail[x]][i];
        }
    }
    return;
}
int ask() {
    int ans = 0, x = 1, t, k;
    for(int i = 0; i < lc; ++i) {
        t = ch[i] - 'a';
        k = trie[x][t];
        while(k > 1) {
            if(rec[k] == -1) break;
            ans += rec[k];
            rec[k] = -1;
            k = fail[k];
        }
        x = trie[x][t];
    }
    return ans;
}
void work() {
    used = 1;
    memset(trie, 0, sizeof(trie));
    memset(fail, 0, sizeof(fail));
    memset(rec, 0, sizeof(rec));
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%s", ch);
        lc = strlen(ch);
        add();
    }
    get_fail();
    scanf("%s", ch);
    lc = strlen(ch);
    printf("%d\n", ask());
    return;
}
int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) work();
    return 0;
}
