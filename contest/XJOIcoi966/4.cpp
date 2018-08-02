#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 50010;
const long double INF = 1000000000000000000;
struct Point {
    long double x, y;
    Point(long double x_ = 0.0, long double y_ = 0.0) {x = x_; y = y_; return; }
};
Point a[MAXN], b[MAXN];
int n;
long double x, y;
bool cmp(Point x, Point y) {
    return x.x < y.x;
}
long double sqr(long double x) { return x * x; }
int lq, rq, q[MAXN];
long double msort(int l, int r) {
    if(l == r) return INF;
    if(l + 1 == r) return sqrt(sqr(a[l].x - a[r].x) + sqr(a[l].y - a[r].y));
    int mid = (l + r) >> 1;
    long double t1 = msort(l, mid - 1), t2 = msort(mid + 1, r);
    t1 = min(t1, t2);
    long double rec = a[mid].x;
    int l1 = l, l2 = mid, l3 = l;
    while(l1 < mid && l2 <= r) {
        if(a[l1].y < a[l2].y) {
            b[l3] = a[l1];
            l3++; l1++;
        } else {
            b[l3] = a[l2];
            l3++; l2++;
        }
    }
    while(l1 < mid) {
        b[l3] = a[l1];
        l1++; l3++;
    }
    while(l2 <= r) {
        b[l3] = a[l2];
        l2++; l3++;
    }
    lq = 1; rq = 0;
    for(int i = l; i <= r; i++) a[i] = b[i];
    for(int i = l; i <= r; i++) {
        if(abs(rec - a[i].x) > t1) continue;
        rq++; q[rq] = i;
        while(lq <= rq && abs(a[i].y - a[q[lq]].y) > t1) lq++;
        for(int j = lq; j < rq; j++)
            for(int k = j + 1; k <= rq; k++)
                t1 = min(t1, sqrt(sqr(a[q[j]].x - a[q[k]].x) + sqr(a[q[j]].y - a[q[k]].y)));
    }
    return t1;
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%Lf%Lf", &x, &y);
        a[i] = Point(x, y);
    }
    sort(a + 1, a + n + 1, cmp);
    printf("%.2Lf\n", msort(1, n));
    return 0;
}
