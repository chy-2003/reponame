#include <cstdio>
#include <cstring>
#include <algorithm>

int c[ 6 ];
int t[ 1010 ];

int main() {
    memset( t, 0, sizeof( t ) );
    t[ 0 ] = 1;
    for( int i = 0; i < 6; ++i ) scanf( "%d", &c[i] );
    for( int i = 1; i <= c[ 0 ]; ++i ) 
        for( int j = 1000; j >= 1; --j )
            if( t[j-1] ) t[j] = 1;
    for( int i = 1; i <= c[ 1 ]; ++i ) 
        for( int j = 1000; j >= 2; --j )
            if( t[j-2] ) t[j] = 1;
    for( int i = 1; i <= c[ 2 ]; ++i ) 
        for( int j = 1000; j >= 3; --j )
            if( t[j-3] ) t[j] = 1;
    for( int i = 1; i <= c[ 3 ]; ++i ) 
        for( int j = 1000; j >= 5; --j )
            if( t[j-5] ) t[j] = 1;
    for( int i = 1; i <= c[ 4 ]; ++i ) 
        for( int j = 1000; j >= 10; --j )
            if( t[j-10] ) t[j] = 1;
    for( int i = 1; i <= c[ 5 ]; ++i ) 
        for( int j = 1000; j >= 20; --j )
            if( t[j-20] ) t[j] = 1;
    int ans = 0;
    for( int i = 1; i <= 1000; ++i ) if(t[i]) ans++;
    printf( "Total=%d\n", ans);
    return 0;
}

