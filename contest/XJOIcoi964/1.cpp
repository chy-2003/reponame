#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
const int MAXN = 110;
int n, x, y, ll;
struct Node {
    int x, y, z;
    Node (int x_ = 0, int y_ = 0, int z_ = 0) { x = x_; y = y_; z = z_; return; }
};
Node a[MAXN * MAXN];
int father[MAXN];
bool cmp (Node x, Node y) { return x.z < y.z; }
int ans, ansnum;
int get_father(int x) {
    if(father[x] == x) return x;
    father[x] = get_father(father[x]);
    return father[x];
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            scanf("%d", &x);
            a[(i - 1) * n + j] = Node(i, j, x);
        }
    sort(a + 1, a + n * n + 1, cmp);
    ll = 1;
    ans = 0; ansnum = 0;
    for(int i = 1; i <= n; i++) father[i] = i;
    for(int i = 1; i < n; i++) {
        x = get_father(a[ll].x); y = get_father(a[ll].y);
        while(x == y) {
            x = get_father(a[++ll].x);
            y = get_father(a[ll].y);
        }
        father[y] = x;
        ans += a[ll].z;
        if(a[ll].z != 0) ansnum++;
        ll++;
    }
    printf("%d\n%d\n", ansnum, ans);
    return 0;
}

