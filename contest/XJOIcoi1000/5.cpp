#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

struct node {
	LL x, y;
};
node T[ 60 ];
LL n, dp[ 60 ][ 1 << 16 ];

bool cmp( node x, node y ) {
	return x.x > y.x || x.x == y.x && x.y > y.y;
}

int main() {
	scanf( "%lld", &n );
	for( LL i = 1; i <= n; ++i ) scanf( "%lld", &T[ i ].x );
	for( LL i = 1; i <= n; ++i ) scanf( "%lld", &T[ i ].y );
	sort( T + 1, T + n + 1, cmp );
	memset( dp, 0, sizeof( dp ) );
	dp[ 0 ][ 0 ] = 1;
	for( LL i = 0; i < n; ++i ) 
		for( LL j = 0; j < 1 << 16; ++j ) {
			if( !dp[ i ][ j ] ) continue;
			dp[ i + 1 ][ j ] += dp[ i ][ j ];
			for( LL k = T[ i + 1 ].y; k >= T[ i + 1 ].x; --k ) 
				if( !( ( j >> k ) & 1) ) {
					dp[ i + 1 ][ j | ( 1 << k ) ] += dp[ i ][ j ];
					break;
				}
		}
	LL ans = 0;
	for( LL j = 0; j < 1 << 16; ++j )
		ans += dp[ n ][ j ];
	printf( "%lld\n", ans );
	return 0;
}
