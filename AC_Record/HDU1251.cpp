#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>
using namespace std;
string s;
int stat;
int tree[1000010][26], usedspace = 1, cnt[1000010];
void add(string s) {
    int t = 1; cnt[t]++;
    for(int i = 0; i < s.size(); i++) {
        if(tree[t][s[i] - '0'] == 0) tree[t][s[i] - '0'] = ++usedspace;
        t = tree[t][s[i] - '0']; cnt[t]++;
    }
    return;
}
int ask(string s) {
    int t = 1;
    for(int i = 0; i < s.size(); i++) {
        if(tree[t][s[i] - '0'] == 0) return 0;
        t = tree[t][s[i] - '0'];
    }
    return cnt[t];
}
int main() {
    stat = 0;
    while(getline(cin, s)) {
        if(s == "") {
            stat = 1;
            continue;
        }
        if(stat == 0) add(s);
        if(stat == 1) printf("%d\n", ask(s));
    }
    return 0;
}

