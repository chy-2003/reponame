#include <bits/stdc++.h>
using namespace std;
long long n, m, ans;
long long ask(long long l, long long r) {
    l--;
    long long mod = m * 30;
    l %= mod; r %= mod;
    long long a = l * (l + 1) % mod * (2 * l % mod + 1) % mod;
    long long t = (3 * l % mod * (l + 1) % mod + mod - 1) % mod;
    a = a * t % mod;
    a /= 30;
    long long b = r * (r + 1) % mod * (2 * r % mod + 1) % mod;
    t = (3 * r % mod * (r + 1) % mod + mod - 1) % mod;
    b = b * t % mod;
    b /= 30;
    return ((b - a) % mod + mod) % mod;
}
void work() {
    scanf("%lld%lld", &n, &m);
    ans = 0;
    for(long long i = 1; i <= n; i = n / (n / i) + 1) {
        ans = (ans + ask(i, n / (n / i)) * (n / i) % m) % m;
    }
    printf("%lld\n", ans);
    return;
}
int main() {
    long long t;
    scanf("%lld\n", &t);
    for(long long i = 1; i <= t; i++) work();
	return 0;
}
