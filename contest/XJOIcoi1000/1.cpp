#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

LL n, a[ 60 ], b[ 60 ], c[ 60 ], d[ 60 ];

int main() {
	scanf( "%lld", &n );
	for( LL i = 0; i < n; ++i ) scanf( "%lld", &a[ i ] );
	for( LL i = 0; i < n; ++i ) scanf( "%lld", &b[ i ] );
	bool same = true;
	for( LL i = 0; i < n; ++i ) 
		if( a[ i ] != b[ i ] ) {
			same = false;
			break;
		}
	if( same ) {
		printf( "null\n" );
		return 0;
	}
	bool bigger;
	for( LL i = 0; i <= 100; ++i )
		for( LL j = 0; i + j <= 100; ++j ) {
			memcpy( c, a, sizeof( a ) );
			bigger = false;
			for( LL k = 1; k <= i; ++k ) {
				for( LL t = 0; t < n; ++t )
					d[ t ] = c[ t ] + c[ ( t + n - 1 ) % n ];
				memcpy( c, d, sizeof( d ) );
				for( LL t = 0; t < n; ++t )
					if( c[ t ] > b[ t ] ) {
						bigger = true;
						break;
					}
				if( bigger ) break;
			}
			if( bigger ) continue;
			for( LL k = 1; k <= j; ++k ) {
				for( LL t = 0; t < n; ++t )
					d[ t ] = c[ t ] + c[ ( t + 1 ) % n ];
				memcpy( c, d, sizeof( d ) );
				for( LL t = 0; t < n; ++t )
					if( c[ t ] > b[ t ] ) {
						bigger = true;
						break;
					}
				if( bigger ) break;
			}
			if( bigger ) continue;
			same = true;
			for( LL k = 0; k < n; ++k )
				if( c[ k ] != b[ k ] ) {
					same = false;
					break;
				}
			if( same ) {
				for( LL k = 1; k <= i; ++k ) printf( "L" );
				for( LL k = 1; k <= j; ++k ) printf( "R" );
				printf( "\n" );
				return 0;
			}
		}
	printf( "No solution\n" );
	return 0;
}
