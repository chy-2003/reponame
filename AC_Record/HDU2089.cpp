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

int n, m;
int a[ 10 ], b[ 10 ];
int dp[ 10 ][ 10 ][ 4 ];

int main() {
	while( scanf( "%d%d", &n, &m ) == 2 ) {
		if( n == 0 && m == 0 ) break; 
		memset( a, 0, sizeof( a ) );
		memset( b, 0, sizeof( b ) );
		memset( dp, 0, sizeof( dp ) );
		for( int i = 1; i <= 8; ++i ) {
			a[ i ] = n % 10;
			n /= 10;
		}
		for( int i = 1; i <= 8; ++i ) {
			b[ i ] = m % 10;
			m /= 10;
		}
		memset( dp, 0, sizeof( dp ) );
		dp[ 9 ][ 0 ][ 3 ] = 1;
		for( int i = 9; i >= 2; --i ) 
			for( int j = 0; j <= 9; ++j ) 
				for( int k = 0; k <= 3; ++k ) {
					if( !dp[ i ][ j ][ k ] ) continue;
					switch ( k ) {
						case 3 : {
							if( a[ i - 1 ] == b[ i - 1 ] ) {
								if( a[ i - 1 ] != 4 && !( j == 6 && a[ i - 1 ] == 2 ) )
									dp[ i - 1 ][ a[ i - 1 ] ][ 3 ] += dp[ i ][ j ][ k ];
							} else {
								if( a[ i - 1 ] != 4 && !( j == 6 && a[ i - 1 ] == 2 ) )
									dp[ i - 1 ][ a[ i - 1 ] ][ 1 ] += dp[ i ][ j ][ k ];
								if( b[ i - 1 ] != 4 && !( j == 6 && b[ i - 1 ] == 2 ) )
									dp[ i - 1 ][ b[ i - 1 ] ][ 2 ] += dp[ i ][ j ][ k ];
							}
							for( int l = a[ i - 1 ] + 1; l < b[ i - 1 ]; ++l )
								if( l != 4 && !( j == 6 && l == 2 ) )
									dp[ i - 1 ][ l ][ 0 ] += dp[ i ][ j ][ k ];
							continue;
						}
						case 2 : {
							if( b[ i - 1 ] != 4 && !( j == 6 && b[ i - 1 ] == 2 ) )
								dp[ i - 1 ][ b[ i - 1 ] ][ 2 ] += dp[ i ][ j ][ k ];
							for( int l = 0; l < b[ i - 1 ]; ++l ) 
								if( l != 4 && !( j == 6 && l == 2 ) )
									dp[ i - 1 ][ l ][ 0 ] += dp[ i ][ j ][ k ];
							continue;
						}
						case 1 : {
							if( a[ i - 1 ] != 4 && !( j == 6 && a[ i - 1 ] == 2 ) )
								dp[ i - 1 ][ a[ i - 1 ] ][ 1 ] += dp[ i ][ j ][ k ];
							for( int l = a[ i - 1 ] + 1; l <= 9; ++l ) 
								if( l != 4 && !( j == 6 && l == 2 ) )
									dp[ i - 1 ][ l ][ 0 ] += dp[ i ][ j ][ k ];
							continue;
						}
						case 0 : {
							for( int l = 0; l <= 9; ++l ) 
								if( l != 4 && !( j == 6 && l == 2 ) )
									dp[ i - 1 ][ l ][ 0 ] += dp[ i ][ j ][ k ];
							continue;
						}
					}
				}
		int ans = 0;
		for( int i = 0; i <= 9; ++i ) 
			for( int j = 0; j <= 3; ++j ) 
				ans += dp[ 1 ][ i ][ j ];
		printf( "%d\n", ans );
	}
	return 0;
}
