#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;
const int mod = 10000;
struct Matrix {
    int a[2][2];
};
Matrix one, zero;
Matrix multiply(Matrix x, Matrix y) {
    Matrix t;
    t.a[0][0] = (x.a[0][0] * y.a[0][0] % mod + x.a[0][1] * y.a[1][0] % mod) % mod;
    t.a[0][1] = (x.a[0][0] * y.a[0][1] % mod + x.a[0][1] * y.a[1][1] % mod) % mod;
    t.a[1][0] = (x.a[1][0] * y.a[0][0] % mod + x.a[1][1] * y.a[1][0] % mod) % mod;
    t.a[1][1] = (x.a[1][0] * y.a[0][1] % mod + x.a[1][1] * y.a[1][1] % mod) % mod;
    return t;
}
Matrix work(int x) {
    if(x == 0) return zero;
    Matrix t = work(x / 2);
    t = multiply(t, t);
    if(x % 2 == 1) t = multiply(one, t);
    return t;
}
int main() {
    int n;
    one.a[0][0] = 1; one.a[0][1] = 1; one.a[1][0] = 1; one.a[1][1] = 0;
    zero.a[0][0] = 1; zero.a[0][1] = 0; zero.a[1][0] = 0; zero.a[1][1] = 1;
    scanf("%d", &n);
    while(n != -1) {
        printf("%d\n", work(n).a[0][1]);
        scanf("%d", &n);
    }
    return 0;
}
