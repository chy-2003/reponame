#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-18;
int cmp(double x, double y) {
    if(abs(x - y) <= eps) return 0;
    if(x - y < -eps) return -1;
    if(x - y > eps) return 1;
}
double sqr(double x) { return x * x; }
struct Vector {
    double x, y;
    Vector(double x_ = 0.0, double y_ = 0.0) { x = x_; y = y_; return; }
    Vector operator + (Vector Other) { return Vector(x + Other.x, y + Other.y); }
    Vector operator - (Vector Other) { return Vector(x - Other.x, y - Other.y); }
    double operator * (Vector Other) { return x * Other.y - y * Other.x; }
    double operator / (Vector Other) { return sqrt(sqr(x - Other.x) + sqr(y - Other.y)); }
};
Vector a[1010];
int n;
bool comperation(Vector x, Vector y) {
    double ans = (x - a[1]) * (y - a[1]);
    return cmp(ans, 0.0) == 1 || cmp(ans, 0.0) == 0 && cmp(x / a[1], y / a[1]) == 1;
}
int stack_size, stack[1010];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lf%lf", &a[i].x, &a[i].y);
    for(int i = 2; i <= n; i++)
        if(cmp(a[i].x, a[1].x) == -1 || cmp(a[i].x, a[1].x) == 0 && cmp(a[i].y, a[1].y) == -1)
            swap(a[1], a[i]);
    sort(a + 2, a + n + 1, comperation);
    a[n + 1] = a[1];
    stack_size = 0;
    memset(stack, 0, sizeof(stack));
    stack_size = 2;
    stack[1] = 1; stack[2] = 2;
    for(int i = 3; i <= n + 1; i++) {
        while(stack_size > 1 && cmp((a[i] - a[stack[stack_size - 1]]) * (a[i] - a[stack[stack_size]]), 0.0) == -1) stack_size--;
        stack[++stack_size] = i;
    }
    double ans = 0.0;
    for(int i = 1; i < stack_size; i++) ans += (a[stack[i]] - Vector(0.0, 0.0)) * (a[stack[i + 1]] - Vector(0.0, 0.0)) / 2;
    printf("%.2lf\n", ans);
    return 0;
}
