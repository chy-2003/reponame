#include <cstdio>
#include <cstring>
#include <algorithm>
int Father[ 50010 ], Race[ 50010 ], n, m, ans, x, y, t;

int GetFather( int x ) {
    if( Father[ x ] == x ) return x;
    int t = Father[ x ];
    Father[ x ] = GetFather( Father[ x ] );
    Race[ x ] = ( Race[ x ] + Race[ t ] ) % 3;
    return Father[ x ];
}

bool Judge() {
    int a = GetFather( x );
    int b = GetFather( y );
    int aa = Race[ x ];
    int bb = Race[ y ];
    if( a != b ) {
        Father[ a ] = b;
        if( t == 1 ) Race[ a ] = ( bb - aa + 3 ) % 3;
        if( t == 2 ) Race[ a ] = ( bb - aa + 2 ) % 3;
    } else {
        if( t == 1 ) 
            if( aa != bb ) return false;
        if( t == 2 )
            if( aa == bb || aa == ( bb + 1 ) % 3 ) return false;
    } 
    return true;
}

int main() {
    scanf( "%d%d", &n, &m );
    for( int i = 1; i <= n; ++i ) Father[ i ] = i;
    for( int i = 1; i <= m; ++i ) {
        scanf( "%d%d%d", &t, &x, &y );
        if( x > n || y > n ) ++ans; else
            if( t == 2 && x == y ) ++ans; else
                if( !Judge() ) ++ans;
    }
    printf( "%d\n", ans );
}

