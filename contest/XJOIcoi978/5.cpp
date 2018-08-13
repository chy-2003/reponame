#include <bits/stdc++.h>
using namespace std;
struct Point{
    long long x, y;
    Point(long long x_ = 0, long long y_ = 0) { x = x_; y = y_; return; }
};
Point a[20];
long long vis[20], rec[20];
long long n, x, y;
long long ans = 0;
long long cross(Point a, Point b, Point c)
{
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
bool segcross(Point p1, Point p2, Point q1, Point q2) {
    return (
            min(p1.x, p2.x) <= max(q1.x, q2.x) &&
            min(q1.x, q2.x) <= max(p1.x, p2.x) &&
            min(p1.y, p2.y) <= max(q1.y, q2.y) &&
            min(q1.y, q2.y) <= max(p1.y, p2.y) &&
            cross(p1, q2, q1) * cross(p2, q2, q1) <= 0 &&
            cross(q1, p2, p1) * cross(q2, p2, p1) <= 0 
           );
}
bool check(long long x, long long y) {
    for(long long i = 1; i < x - 2; i++)
        if(segcross(a[rec[i]], a[rec[i + 1]], a[rec[x - 1]], a[y])) {
//          printf("fail : (%lld, %lld)-(%lld,%lld), (%lld, %lld)-(%lld, %lld)\n", a[rec[i]].x, a[rec[i]].y, a[rec[i + 1]].x, a[rec[i + 1]].y, a[rec[x - 1]].x, a[rec[x - 1]].y, a[y].x, a[y].y);
            return false;
        }
    return true;
}
bool check2(long long x, long long y) {
    for(long long i = 2; i < x - 2; i++)
        if(segcross(a[rec[i]], a[rec[i + 1]], a[rec[x - 1]], a[y])) {
//          printf("fail : (%lld, %lld)-(%lld,%lld), (%lld, %lld)-(%lld, %lld)\n", a[rec[i]].x, a[rec[i]].y, a[rec[i + 1]].x, a[rec[i + 1]].y, a[rec[x - 1]].x, a[rec[x - 1]].y, a[y].x, a[y].y);
            return false;
        }
    return true;
}
void dfs(long long x) {
//  printf("Possition %lld\n", x);
    if(x > n) {
        if(check2(x, 1)) ans++;
//      printf("return\n");
        return;
    }
    for(long long i = 1; i <= n; i++) {
//      printf("try %lld\n", i);
        if(vis[i]) continue;
//      printf("*\n");
        if(!check(x, i)) continue;
//      printf("Number %lld Choose %lld\n", x, i);
        vis[i] = 1;
        rec[x] = i;
        dfs(x + 1);
        vis[i] = 0;
    }
//  printf("return\n");
    return;
}
int main() {
    scanf("%lld%lld", &x, &y);
    while(!(x == 0 && y == 0)) {
        a[++n] = Point(x, y);
        scanf("%lld%lld", &x, &y);
    }
    a[++n] = Point(x, y);
    memset(vis, 0, sizeof(vis));
    memset(rec, 0, sizeof(rec));
    rec[1] = 1;
    vis[1] = 1;
    dfs(2);
    printf("%lld\n", ans / 2);
    return 0;
}
