#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <sstream>
using namespace std;
const int INF = 2000000000;
char ch[110];
int len;
int priority(char ch) {
    if(ch == '(' || ch == ')') return INF - 1;
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '^') return 3;
    return INF;
}
long double doit(long double x, long double y, char ch) {
    if(ch == '+') return x + y;
    if(ch == '-') return x - y;
    if(ch == '*') return x * y;
    if(ch == '/') return x / y;
    if(ch == '^') return pow(x, y);
    return 0;
}
long double get_num(int x, int y) {
    int b = 0;
    long double t = 0, k = 1;
    for(int i = x; i <= y; i++) {
        if(ch[i] == '.') b = 1; else
            if(b == 0) t = t * 10 + ch[i] - '0'; else {
                k /= 10; t += k * (ch[i] - '0');
            }
    }
    return t;
}
long double work(int l, int r) {
    int in = 0;
    int id = 0, rec = INF - 1;
    int t, bb = 0;
    for(int i = l; i <= r; i++) {
        if(ch[i] == '(') in++; else if(ch[i] == ')') in--;
        t = priority(ch[i]);
        if(t != INF) bb = 1;
        if(in == 0 && t <= rec) {
            rec = t;
            id = i;
        }
    }
    if(rec != INF - 1) return doit(work(l, id - 1), work(id + 1, r), ch[id]);
    if(rec == INF - 1 && bb == 1) return work(l + 1, r - 1);
    return get_num(l, r);
}
int main() {
    while(scanf("%s", ch + 1 + len) == 1) len = strlen(ch + 1);
    printf("%.2Lf\n", work(1, len));
    return 0;
}
