#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
void read( int & t ) {
    char ch = getchar(); t = 0;
    while( ch < '0' || ch > '9' ) ch = getchar();
    while( ch >= '0' && ch <= '9' ) {
        t = t * 10 - '0' + ch;
        ch = getchar();
    }
    return;
}
 
const int Maxq = 1100010;
int q, a, b;
int Tree[ Maxq << 1 ][ 2 ], Used = 1;
 
void Add1( int x ) {
    int pos = 1;
    for( int i = 21; i >= 0; --i ) {
        int t = ( x >> i ) & 1;
        if( !Tree[ pos ][ t ] ) Tree[ pos ][ t ] = ++Used;
        pos = Tree[ pos ][ t ];
    }
    return;
}
 
int Query1( int x ) {
    int pos = 1, ans = 0;
    for( int i = 21; i >= 0; --i ) {
        int t = ( x >> i ) & 1;
        if( t == 1 ) {
            if( Tree[ pos ][ 0 ] ) {
                ans |= 1 << i;
                pos = Tree[ pos ][ 0 ];
            } else pos = Tree[ pos ][ 1 ];
        } else {
            if( Tree[ pos ][ 1 ] ) {
                ans |= 1 << i;
                pos = Tree[ pos ][ 1 ];
            } else pos = Tree[ pos ][ 0 ];
        }
        if( !pos ) break;
    }
    return ans;
}
 
int Rec[ Maxq << 2 ];
 
int lowbit( int x ) { return x & ( -x ); }
 
void Add2( int x ) {
    if( Rec[ x ] ) return;
    Rec[ x ] = 1;
    int t = x;
    while( t ) {
        int k = lowbit( t );
        t ^= k;
        Add2( x ^ k );
    }
    return;
}
 
int Query2( int x ) {
    int t = 0;
    for( int i = 21; i >= 0; --i ) {
        int k = ( x >> i ) & 1;
        if( k == 1 ) {
            t ^= 1 << i;
            if( !Rec[ t ] ) t ^= 1 << i;
        }
    }
    return x & t;
}
 
int Query3( int x ) {
    int t = 0;
    for( int i = 21; i >= 0; --i ) {
        int k = ( x >> i ) & 1;
        if( k == 0 ) {
            t ^= 1 << i;
            if( !Rec[ t ] ) t ^= 1 << i;
        }
    }
    return x | t;
}
 
int main() {
    read( q );
    for( int i = 1; i <= q; ++i ) {
        read( a ); read( b );
        if( a == 1 ) {
            Add1( b );
            Add2( b );
        }
        if( a == 2 ) printf( "%d %d %d\n", Query1( b ), Query2( b ) ,Query3( b ) );
        if( a == 3 ) printf( "%d\n", Query1( b ) );
    }
    return 0;
}
