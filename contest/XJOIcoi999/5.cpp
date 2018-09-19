#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")
#include <cmath>
#include <cstdio>
#define LL long long
using namespace std;

LL r, ans;
LL num, a[ 110 ];

LL Query( LL x, LL y ) {
	LL ans = 0;
	num = 0;
	for( LL i = 2; i * i <= y; ++i )
		if( !( y % i ) ) {
			a[ ++num ] = i;
			while( !( y % i ) ) y /= i;
		}
	if( y != 1 ) a[ ++num ] = y;
	for( LL i = 1; i < 1 << num; ++i ) {
		LL t = 1, k = -1;
		for( LL j = 1; j <= num; ++j ) 
			if( ( i >> (j - 1 ) ) & 1 ) t *= a[ j ], k = -k;
		ans += k * ( x / t );
	}
	return x - ans;
}

int main() {
	ans = 0;
	scanf( "%lld", &r );
	for( LL i = 1; i <= r; ++i ) {
		ans = ( ans + Query( sqrt( r * r - i * i ), i ) );
	}
	ans = ans * 4 + 4;
	printf( "%lld\n", ans );
	return 0;
}
