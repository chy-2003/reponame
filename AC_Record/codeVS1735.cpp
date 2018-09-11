#include <bits/stdc++.h>
using namespace std;

int n, M, k[ 10 ], q[ 10 ];
vector<int> Map1, Map2;

int Pow( int x, int y ) {
    int t = 1;
    for( int i = 1; i <= y; ++i ) t *= x;
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
        if( i > 0 && Map1[ i ] == Map1[ i - 1] ) continue;
        int a = upper_bound( Map1.begin(), Map1.end(), Map1[ i ] ) - lower_bound( Map1.begin(), Map1.end(), Map1[ i ] );
        int b = upper_bound( Map2.begin(), Map2.end(), -Map1[ i ] ) - lower_bound( Map2.begin(), Map2.end(), -Map1[ i ] );
        ans += a * b;
    }
    printf( "%d\n", ans );
    return 0;
}

