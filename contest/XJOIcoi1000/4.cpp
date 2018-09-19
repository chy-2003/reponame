#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, Cnt;
char ch[30];

int main() {
    scanf( "%d%d", &n, &m );
    for( int i = 1; i <= n; ++i ) {
        scanf( "%s", ch );
        for( int j = 0; j < m; ++j )
            if( ch[ j ] == '#' ) ++Cnt;
    }
    if( ( n * m - n - m + 1 - Cnt ) % 2 ) printf( "wzz\n" ); else printf( "zzy\n" );
    return 0;
}
