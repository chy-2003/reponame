#include <cstdio>
#include <cstring>
#include <algorithm>

int N, Q;
long long Bitset[ 10010 ][ 30 ];

void Add( int x, int k ) {
    Bitset[ x ][ k / 50 ] |= 1LL << ( k % 50 );
    return;
}

bool Query( int x, int y ) {
    for( int j = 0; j <= 20; ++j )
        if( Bitset[ x ][ j ] & Bitset[ y ][ j ] ) return true;
    return false;
}

int main() {
    memset( Bitset, 0, sizeof( Bitset ) );
    scanf( "%d", &N );
    for( int i = 1; i <= N; ++i ) {
        int C; scanf( "%d", &C );
        for( int j = 1; j <= C; ++j ) {
            int x; scanf( "%d", &x );
            Add( x, i );
        }
    }
    scanf( "%d", &Q );
    for( int i = 1; i <= Q; ++i ) {
        int x, y;
        scanf( "%d%d", &x, &y );
        if( Query( x, y ) ) printf( "Yes\n" ); else printf( "No\n"  );
    }
    return 0;
}


