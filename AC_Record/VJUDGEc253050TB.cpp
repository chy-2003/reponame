#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long 

const LL INF = 1e18;
LL t, n, seed, Max1, Max2, Min1, Min2;

inline LL rand( LL l, LL r ) {
    static LL mo = 1e9 + 7, g = 78125;
    return 1 + ( ( seed *= g ) %= mo ) % ( r - l + 1 );
}

int main() {
    scanf( "%lld", &t );
    for( long long i = 1; i <= t; ++i ) {
        scanf( "%lld%lld", &n, &seed );
        Max1 = -INF; Max2 = -INF; Min1 = INF; Min2 = INF;
        for( long long j = 0; j < n; ++j ) {
            LL x = rand( -1000000000, 1000000000 );
            LL y = rand( -1000000000, 1000000000 );
            Max1 = std::max( x + y, Max1 );
            Max2 = std::max( x - y, Max2 );
            Min1 = std::min( x + y, Min1 );
            Min2 = std::min( x - y, Min2 );
        }
        printf( "%lld\n", std::max( Max1 - Min1, Max2 - Min2 ) );
    }
    return 0;
}

