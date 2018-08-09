#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#define LL int
using namespace std;

namespace FastIO {
	template <typename T>
	void read(T & x) {
		x = 0; register char ch = getchar(); register bool f = false;
		for (; ch < '0' || ch > '9'; f |= (ch == '-'), ch = getchar());
		for (; ch >= '0' && ch <= '9'; x = (x << 3) + (x << 1) + (ch ^ '0'), ch = getchar());
		if (f) x = -x;
	}

	template <typename T>
	void write(T x) {
		if (!x) return (void)(putchar('0'));
		if (x < 0) x = -x, putchar('-');
		register int arr[20], len = 0;
		for (; x; arr[len++] = x % 10, x /= 10);
		while (len) putchar(arr[--len] ^ '0');
	}

	template <typename T>
	inline void writeln(T & x) {
		write(x), putchar('\n');
	}
}

LL l, q[6000010];
LL b[3400010];
unsigned LL mdzz[6000010];
void init() {
    for(LL i = 2; i <= 100000000; ++i) {
       if(((b[i >> 5] >> (i & ((1 << 5) - 1))) & 1) == 0) {
           q[++l] = i;
       } 
       for(LL j = 1; j <= l; ++j) {
           if(1LL * i * q[j] > 100000000) break;
           b[i * q[j] >> 5] |= 1 << (i * q[j] & ((1 << 5) - 1));
           if(i % q[j] == 0) break;
       }
    }
    mdzz[0] = 1;
    for(LL i = 1; i <= l; ++i) mdzz[i] = q[i] * mdzz[i - 1];
    return;
}
LL n;
unsigned LL work() {
    FastIO::read(n);
    LL p = upper_bound(q + 1, q + l + 1, n) - q - 1;
    unsigned LL ans = mdzz[p];
    for(LL i = 1; i <= l && 1LL * q[i] * q[i] <= 1LL * n; ++i) {
        LL t1 = q[i], t2 = q[i] * q[i];
        while(t2 / t1 == q[i] && t2 <= n) t1 *= q[i], t2 *= q[i];
        ans *= (t1 / q[i]);
    }
    return ans;
}
int main() {
    init();
    LL t;
    FastIO::read(t);
    for(LL i = 1; i <= t; i++) printf("Case %d: %u\n", i, work());
    return 0;
}

