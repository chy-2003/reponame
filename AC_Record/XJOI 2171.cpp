#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, M, k[ 10 ], q[ 10 ];
vector<int> Map1, Map2;
int Power[ 200 ][ 40 ];

int Pow( int x, int y ) {
    if( Power[ x ][ y ] != -1 ) return Power[ x ][ y ];
    int t = 1;
    for( int i = 1; i <= y; ++i ) t *= x;
    Power[ x ][ y ] = t;
    return t;
}

void Dfs1( int x, int s ) {
    if( x > n / 2 ) {
        Map1.push_back( s );
        return;
    }
    for( int i = 1; i <= M; ++i ) 
        Dfs1( x + 1, s + k[ x ] * Pow( i, q[ x ] ) );
    return;
}

void Dfs2( int x, int s ) {
    if( x <= n / 2 ) {
        Map2.push_back( s );
        return;
    }
    for( int i = 1; i <= M; ++i )
        Dfs2( x - 1, s + k[ x ] * Pow( i, q[ x ] ) );
    return;
}

int main() {
    memset( Power, 255, sizeof( Power ) );
    scanf( "%d%d", &n, &M );
    for(int i = 1; i <= n; ++i ) scanf( "%d%d", &k[ i ], &q[ i ] );
    Map1.clear();
    Dfs1( 1, 0 );
    Map2.clear();
    Dfs2( n, 0 );
    sort( Map1.begin(), Map1.end() );
    sort( Map2.begin(), Map2.end() );
    int ans = 0;
    int l = Map1.size();
    for( int i = 0; i < l; ++i ) {
        if( i > 0 && Map1[ i ] == Map1[ i - 1 ] ) continue;
        int a = upper_bound( Map1.begin(), Map1.end(), Map1[ i ] ) - lower_bound( Map1.begin(), Map1.end(), Map1[ i ] );
        int b = upper_bound( Map2.begin(), Map2.end(), -Map1[ i ] ) - lower_bound( Map2.begin(), Map2.end(), -Map1[ i ] );
        ans += a * b;
    }
    printf( "%d\n", ans );
    return 0;
}

