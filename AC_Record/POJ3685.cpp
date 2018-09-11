#include <cstdio>
#include <cstring>
#include <algorithm>

const long long MaxN = 50010;
long long N, M;
long long L, R;

long long Calc( long long i, long long j ) {
    return i * i + 100000 * i + j * j - 100000 * j + i * j;
}

long long Count( long long x ) {
    long long ans = 0;
    for( long long j = 1; j <= N; ++j ) {
        long long l = 0, r = N;
        while( l < r ) {
            long long mid = l + r + 1 >> 1;
            if( Calc( mid, j ) >= x ) r = mid - 1; else l = mid;
        }
        ans += l;
    }
    return ans;
}

void work() {
    scanf( "%lld%lld", &N, &M );
    L = -1e18; R = 1e18;
    while( L < R ) {
        long long Mid = L + R + 1 >> 1;
        if( Count( Mid ) >= M ) R = Mid - 1; else L = Mid;
    }
    printf( "%lld\n", L );
    return;
}

int main() {
    long long t;
    scanf( "%lld", &t );
    for( long long i = 1; i <= t; ++i ) work();
    return 0;
}
