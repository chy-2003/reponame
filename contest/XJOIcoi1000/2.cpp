#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char ch[ 1010 ];
int len, Cnt[ 26 ], ans;

int main() {
	scanf( "%s", ch ); len = strlen( ch );
	for( int i = 0; i < len; ++i ) ++Cnt[ ch[ i ] - 'a' ];
	ans = 0;
	for( int i = 0; i < 26; ++i ) if( Cnt[ i ] % 2 ) ++ans;
	printf( "%d\n", max( ans, 1 ) );
	if( ans == 0 ) {
		for( int i = 0; i < 26; ++i ) 
			for( int j = 1; j <= Cnt[ i ] / 2; ++j )
				printf( "%c", i + 'a' );
		for( int i = 25; i >= 0; --i ) 
			for( int j = 1; j <= Cnt[ i ] / 2; ++j )
				printf( "%c", i + 'a' );
		printf( "\n" );
	} else {
		for( int i = 0; i < 26; ++i ) 
			for( int j = 1; j <= Cnt[ i ] / 2; ++j )
				printf( "%c", i + 'a' );
		for( int i = 0; i < 26; ++i ) 
			if( Cnt[ i ] % 2 ) {
				printf( "%c", i + 'a' );
				Cnt[ i ]--;
				break;
			}
		for( int i = 25; i >= 0; --i ) 
			for( int j = 1; j <= Cnt[ i ] / 2; ++j )
				printf( "%c", i + 'a' );
		printf( "\n" );
		for( int i = 2; i <= ans; ++i ) 
			for( int j = 0; j < 26; ++j ) {
				if( Cnt[ j ] % 2 ) {
					printf( "%c\n", j + 'a' );
					Cnt[ j ]--;
					break;
				}
			}
	}
	return 0;
}
