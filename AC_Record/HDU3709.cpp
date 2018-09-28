#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize                             (3)
#pragma GCC optimize                       ("Ofast")
#pragma GCC optimize                      ("-fgcse")
#pragma GCC optimize                      ("inline")
#pragma GCC optimize                   ("-fipa-sra")
#pragma GCC optimize                   ("-fgcse-lm")
#pragma GCC optimize                  ("-ftree-vrp")
#pragma GCC optimize                  ("-ftree-pre")
#pragma GCC optimize                 ("-fpeephole2")
#pragma GCC optimize                 ("-ffast-math")
#pragma GCC optimize                ("-fsched-spec")
#pragma GCC optimize                ("unroll-loops")
#pragma GCC optimize               ("-falign-loops")
#pragma GCC optimize               ("-falign-jumps")
#pragma GCC optimize              ("-funroll-loops")
#pragma GCC optimize              ("-fthread-jumps")
#pragma GCC optimize              ("-fcrossjumping")
#pragma GCC optimize              ("-fcaller-saves")
#pragma GCC optimize              ("-fdevirtualize")
#pragma GCC optimize              ("-falign-labels")
#pragma GCC optimize             ("-fwhole-program")
#pragma GCC optimize            ("inline-functions")
#pragma GCC optimize            ("-fschedule-insns")
#pragma GCC optimize            ("-freorder-blocks")
#pragma GCC optimize           ("-fcse-skip-blocks")
#pragma GCC optimize           ("-falign-functions")
#pragma GCC optimize           ("-fstrict-overflow")
#pragma GCC optimize           ("-fstrict-aliasing")
#pragma GCC optimize           ("-fschedule-insns2")
#pragma GCC optimize           ("-ftree-tail-merge")
#pragma GCC optimize          ("no-stack-protector")
#pragma GCC optimize          ("-fpartial-inlining")
#pragma GCC optimize          ("-fsched-interblock")
#pragma GCC optimize          ("-fcse-follow-jumps")
#pragma GCC optimize         ("-findirect-inlining")
#pragma GCC optimize         ("-freorder-functions")
#pragma GCC optimize      ("inline-small-functions")
#pragma GCC optimize      ("-frerun-cse-after-loop")
#pragma GCC optimize      ("-fhoist-adjacent-loads")
#pragma GCC optimize    ("-foptimize-sibling-calls")
#pragma GCC optimize    ("-ftree-switch-conversion")
#pragma GCC optimize    ("-finline-small-functions")
#pragma GCC optimize   ("-fexpensive-optimizations")
#pragma GCC optimize ("-funsafe-loop-optimizations")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC target("avx","sse2")
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long 
using namespace std;

LL x, y;
LL a[ 20 ], b[ 20 ];
LL dp[ 20 ][ 10 ][ 4 ][ 1600 ];

int main() {
	LL TestCase;
	scanf( "%lld", &TestCase );
	while( TestCase-- ) {
		LL ans = 0;
		memset( a, 0, sizeof( a ) );
		memset( b, 0, sizeof( b ) );
		scanf( "%lld%lld", &x, &y );
		if( x == 0 ) ans -= 18;
		for( LL i = 0; i < 19; ++i ) {
			a[ i ] = x % 10;
			x /= 10;
		}
		for( LL i = 0; i < 19; ++i ) {
			b[ i ] = y % 10;
			y /= 10;
		}
		for( LL Pivot = 0; Pivot <= 18; ++Pivot ) {
			memset( dp, 0, sizeof( dp ) );
			dp[ 19 ][ 0 ][ 3 ][ 0 ] = 1;
			for( LL i = 19; i > 0; --i ) 
				for( LL j = 0; j <= 9; ++j ) 
					for( LL k = 0; k <= 3; ++k )
						for( LL l = 0; l < 1600; ++l ) {
							if( !dp[ i ][ j ][ k ][ l ] ) continue;
							if( k == 3 ) {
								if( a[ i - 1 ] == b[ i - 1 ] ) {
									if( l + a[ i - 1 ] * ( i - 1 - Pivot ) >= 0 )
										dp[ i - 1 ][ a[ i - 1 ] ][ 3 ][ l + a[ i - 1 ] * ( i - 1 - Pivot ) ] += dp[ i ][ j ][ k ][ l ];
								} else {
									if( l + a[ i - 1 ] * ( i - 1 - Pivot ) >= 0 )
										dp[ i - 1 ][ a[ i - 1 ] ][ 2 ][ l + a[ i - 1 ] * ( i - 1 - Pivot ) ] += dp[ i ][ j ][ k ][ l ];
									if( l + b[ i - 1 ] * ( i - 1 - Pivot ) >= 0 ) 
										dp[ i - 1 ][ b[ i - 1 ] ][ 1 ][ l + b[ i - 1 ] * ( i - 1 - Pivot ) ] += dp[ i ][ j ][ k ][ l ];
									for( LL _ = a[ i - 1 ] + 1; _ < b[ i - 1 ]; ++_ ) 
										if( l + _ * ( i - 1 - Pivot ) >= 0 )
											dp[ i - 1 ][ _ ][ 0 ][ l + _ * ( i - 1 - Pivot ) ] += dp[ i ][ j ][ k ][ l ];
								}
							}
							if( k == 2 ) {
								if( l + a[ i - 1 ] * ( i - 1 - Pivot ) >= 0 )
									dp[ i - 1 ][ a[ i - 1 ] ][ 2 ][ l + a[ i - 1 ] * ( i - 1 - Pivot ) ] += dp[ i ][ j ][ k ][ l ];
								for( LL _ = a[ i - 1 ] + 1; _ <= 9; ++_ )
									if( l + _ * ( i - 1 - Pivot ) >= 0 ) 
										dp[ i - 1 ][ _ ][ 0 ][ l + _ * ( i - 1 - Pivot ) ] += dp[ i ][ j ][ k ][ l ]; 
							}
							if( k == 1 ) {
								if( l + b[ i - 1 ] * ( i - 1 - Pivot ) >= 0 )
									dp[ i - 1 ][ b[ i - 1 ] ][ 1 ][ l + b[ i - 1 ] * ( i - 1 - Pivot ) ] += dp[ i ][ j ][ k ][ l ];
								for( LL _ = 0; _ < b[ i - 1 ]; ++_ )
									if( l + _ * ( i - 1 - Pivot ) >= 0 ) 
										dp[ i - 1 ][ _ ][ 0 ][ l + _ * ( i - 1 - Pivot ) ] += dp[ i ][ j ][ k ][ l ];
							}
							if( k == 0 ) {
								for( LL _ = 0; _ <= 9; ++_ ) 
									if( l + _ * ( i - 1 - Pivot ) >= 0 ) 
										dp[ i - 1 ][ _ ][ 0 ][ l + _ * ( i - 1 - Pivot ) ] += dp[ i ][ j ][ k ][ l ];
							}
						}
			for( LL i = 0; i <= 9; ++i ) 
				for( LL j = 0; j <= 3; ++j ) 
					ans += dp[ 0 ][ i ][ j ][ 0 ];
		}
		printf( "%lld\n", ans );
	}
	return 0;
}
