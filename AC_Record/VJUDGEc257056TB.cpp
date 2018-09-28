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

LL n;
LL a[ 22 ];
LL dp[ 22 ][ 10 ][ 2 ][ 2 ];

int main() {
	LL t;
	scanf( "%lld", &t );
	while( t-- ) {
		scanf( "%lld", &n );
		memset( dp, 0, sizeof( dp ) );
		memset( a, 0, sizeof( a ) );
		for( LL i = 1; i <= 20; ++i ) {
			a[ i ] = n % 10;
			n /= 10;
		}
		dp[ 21 ][ 0 ][ 1 ][ 0 ] = 1;
		for( LL i = 21; i >= 2; --i ) 
			for( LL j = 0; j <= 9; ++j ) 
				for( LL k = 0; k <= 1; ++k ) 
					for( LL l = 0; l <= 1; ++l ) {
						if( !dp[ i ][ j ][ k ][ l ] ) continue;
						if( k == 0 ) {
							for( LL _ = 0; _ <= 9; ++_ ) {
								if( l == 1 ) dp[ i - 1 ][ _ ][ 0 ][ 1 ] += dp[ i ][ j ][ k ][ l ];
								if( l == 0 ) {
									if( j == 4 && _ == 9 ) 
										dp[ i - 1 ][ _ ][ 0 ][ 1 ] += dp[ i ][ j ][ k ][ l ];
									else 
										dp[ i - 1 ][ _ ][ 0 ][ 0 ] += dp[ i ][ j ][ k ][ l ];
								}
							}
						} else {
							if( l == 1 ) dp[ i - 1 ][ a[ i - 1 ] ][ 1 ][ 1 ] += dp[ i ][ j ][ k ][ l ];
							if( l == 0 ) {
								if( j == 4 && a[ i - 1 ] == 9 )
									dp[ i - 1 ][ a[ i - 1 ] ][ 1 ][ 1 ] += dp[ i ][ j ][ k ][ l ];
								else 
									dp[ i - 1 ][ a[ i - 1 ] ][ 1 ][ 0 ] += dp[ i ][ j ][ k ][ l ];
							}
							for( LL _ = 0; _ < a[ i - 1 ]; ++_ ) {
								if( l == 1 ) dp[ i - 1 ][ _ ][ 0 ][ 1 ] += dp[ i ][ j ][ k ][ l ];
								if( l == 0 ) {
									if( j == 4 && _ == 9 ) 
										dp[ i - 1 ][ _ ][ 0 ][ 1 ] += dp[ i ][ j ][ k ][ l ];
									else 
										dp[ i - 1 ][ _ ][ 0 ][ 0 ] += dp[ i ][ j ][ k ][ l ];
								}
							}
						}
					}
		LL ans = 0;
		for( LL i = 0; i <= 9; ++i ) 
			for( LL j = 0; j <= 1; ++j )
					ans += dp[ 1 ][ i ][ j ][ 1 ];
		printf( "%lld\n", ans );
	}
	return 0;
}
