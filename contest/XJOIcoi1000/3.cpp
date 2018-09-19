#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ab, bc, ca;
int a[ 2 ], b[ 2 ], c[ 2 ], Max, Min, rec[ 3 ], used[ 3 ];

int main() {
	scanf( "%d%d%d", &ab, &bc, &ca );
	Max = max( ab, max( bc, ca ) );
	Min = min( ab, min( bc, ca ) );
	rec[ 0 ] = ab; rec[ 1 ] = bc; rec[ 2 ] = ca;
	for( int i = 0; i < 3; ++i ) {
		if( used[ i ] ) continue;
		if( rec[ i ] != Min ) continue;
		used[ i ] = 1;
		if( i == 0 ) { a[ 0 ] = Min; b[ 0 ] = Min; }
		if( i == 1 ) { b[ 0 ] = Min; c[ 0 ] = Min; }
		if( i == 2 ) { c[ 0 ] = Min; a[ 0 ] = Min; }
		break;
	}
	for( int i = 0; i < 3; ++i ) {
		if( used[ i ] ) continue;
		if( rec[ i ] != Max ) continue;
		used[ i ] = 1;
		if( i == 0 ) { a[ 0 ] = Max; b[ 0 ] = Max; }
		if( i == 1 ) { b[ 0 ] = Max; c[ 0 ] = Max; }
		if( i == 2 ) { c[ 0 ] = Max; a[ 0 ] = Max; }
		break;
	}
	for( int i = 0; i < 3; ++i ) {
		if( used[ i ] ) continue;
		int res = rec[ i ] - Min;
		if( i == 0 ) { a[ 1 ] = res; b[ 1 ] = res; }
		if( i == 1 ) { b[ 1 ] = res; c[ 1 ] = res; }
		if( i == 2 ) { c[ 1 ] = res; a[ 1 ] = res; }
		break;
	}
	for( int i = 1; i <= a[ 0 ]; ++i ) printf( "1" );
	for( int i = 1; i <= a[ 1 ]; ++i ) printf( "0" );
	printf( "\n" );
	for( int i = 1; i <= b[ 0 ]; ++i ) printf( "1" );
	for( int i = 1; i <= b[ 1 ]; ++i ) printf( "0" );
	printf( "\n" );
	for( int i = 1; i <= c[ 0 ]; ++i ) printf( "1" );
	for( int i = 1; i <= c[ 1 ]; ++i ) printf( "0" );
	printf( "\n" );
	return 0;
}
