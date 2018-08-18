#include <bits/stdc++.h>
using namespace std;
int n, k, x, y;
struct Node{
    int x, y, dir;
    Node(int x_ = 0, int y_ = 0, int dir_ = 0) { x = x_; y = y_; dir = dir_; return; }
};
int l = 0;
Node a[350010];
void work(int len, int x, int y, int xx, int yy) {
    if(len == 1) return;
    int mid = len >> 1;
    if(x <= mid && y <= mid) {
        a[++l] = Node(xx + mid, yy + mid, 1);
        work(mid, x, y, xx, yy);
        work(mid, mid, 1, xx, yy + mid);
        work(mid, 1, mid, xx + mid, yy);
        work(mid, 1, 1, xx + mid, yy + mid);
        return;
    }
    if(x <= mid && y > mid) {
        a[++l] = Node(xx + mid, yy + mid - 1, 2);
        work(mid, mid, mid, xx, yy);
        work(mid, x, y - mid, xx, yy + mid);
        work(mid, 1, mid, xx + mid, yy);
        work(mid, 1, 1, xx + mid, yy + mid);
        return;
    }
    if(x > mid && y <= mid) {
        a[++l] = Node(xx + mid - 1, yy + mid, 3);
        work(mid, mid, mid, xx, yy);
        work(mid, mid, 1, xx, yy + mid);
        work(mid, x - mid, y, xx + mid, yy);
        work(mid, 1, 1, xx + mid, yy + mid);
        return;
    }
    if(x > mid && y > mid) {
        a[++l] = Node(xx + mid - 1, yy + mid - 1, 4);
        work(mid, mid, mid, xx, yy);
        work(mid, mid, 1, xx, yy + mid);
        work(mid, 1, mid, xx + mid, yy);
        work(mid, x - mid, y - mid, xx + mid, yy + mid);
        return;
    }
    return;
}
bool cmp(Node x, Node y) {
    return x.x < y.x || x.x == y.x && x.y < y.y;
}
int main() {
    scanf("%d%d%d", &k, &x, &y);
    n = 1;
    for(int i = 1; i <= k; i++) n *= 2;
    work(n, x, y, 1, 1);
    for(int i = 1; i <= l; i++) printf("%d %d %d\n", a[i].x, a[i].y, a[i].dir);
    return 0;
}
