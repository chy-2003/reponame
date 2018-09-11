#include <cstdio>
#include <cstring>
#include <algorithm>
int cnt[300];
int n;
inline bool cmp(int x, int y) { return x > y; }
bool isalpha(char ch) {
    if(ch >= '0' && ch <= '9') return true;
    if(ch >= 'A' && ch <= 'Z') return true;
    if(ch == '`' || ch == '-' || ch == '=' || ch == '[' || ch == ']' || ch == '\\' || ch == ';' || ch == '\'' || ch == ',' || ch == '.' || ch == '/' || ch == ' ') return true;
    return false;
}
char read() {
    char ch = getchar();
    while(!isalpha(ch)) ch = getchar();
    return ch;
}
struct Node {
    int x, y;
};
Node a[10];
bool cmp2(Node x, Node y) { return x.x < y.x; }
int main() {
    scanf("%d%d%d%d%d", &a[1].x, &a[2].x, &a[3].x, &a[4].x, &a[5].x);
    a[1].y = 1; a[2].y = 16; a[3].y = 8; a[4].y = 8; a[5].y = 15;
    std::sort(a + 1, a + 6, cmp2);
    for(int i = 1; i <= 5; i++) a[i].y += a[i - 1].y;
    scanf("%d", &n);
    std::memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; i++) cnt[read()]++;
    std::sort(cnt + 1, cnt + 260, cmp);
    int ans = 0;
    for(int i = 1; i <= 5; i++)
        for(int j = a[i - 1].y + 1; j <= a[i].y; j++)
            ans += cnt[j] * a[i].x;
    printf("%d\n", ans);
    return 0;
}
