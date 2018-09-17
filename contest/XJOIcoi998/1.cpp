#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("inline")
#include <cstdio>
#include <cmath>
#define LL long long
using namespace std;
 
LL l, r, t, ans1, ans2;
int Bool[ 1000010 ], num, Prime[ 1000010 ];
int rec[ 10000010 ];
 
int main() {
    scanf( "%lld%lld", &l, &r );
    t = sqrt( r );
    for( LL i = 2; i <= t; ++i ) {
        if( !Bool[ i ] ) Prime[ ++num ] = i;
        for( int j = 1; j <= num; ++j ) {
            if( Prime[ j ] * i > t ) break;
            Bool[ Prime[ j ] * i ] = 1;
            if( !( i % Prime[ j ] ) ) break;
        }
    }
    for( int i = 1; i <= num; ++i ) {
        LL t = l / Prime[ i ] * Prime[ i ];
        if( t < l ) t += Prime[ i ];
        for(;t <= r; t += Prime[ i ] ) {
            if( rec[ t - l ] ) continue;
            ++ans1; ans2 += Prime[ i ]; ans2 %= 998244353;
            rec[ t - l ] |= 1;
        }
    }
    printf( "%lld %lld\n", ans1, ans2 );
    return 0;
}
