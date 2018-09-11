/*
 * 0 1 2 3 4 5 6 7  8  9  10 11
 * 0 1 1 2 3 5 8 13 21 34 55 89
 * 1 4
 * 2 12
 * 3 33
 * f( x ) = Feb( x * 2 + 3 ) - 1
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const long long Mod = 998244353;

long long one[ 2 ][ 2 ], a[ 2 ][ 2 ], t[ 2 ][ 2 ], tt[ 2 ][ 2 ];
long long k;

void Mu( long long n ) {
    memset( t, 0, sizeof( t ) );
    memcpy( t, one, sizeof( one ) );
    while( n ) {
        if( n % 2 == 1 ) {
            tt[ 0 ][ 0 ] = ( a[ 0 ][ 0 ] * t[ 0 ][ 0 ] % Mod + a[ 0 ][ 1 ] * t[ 1 ][ 0 ] % Mod ) % Mod;
            tt[ 0 ][ 1 ] = ( a[ 0 ][ 0 ] * t[ 0 ][ 1 ] % Mod + a[ 0 ][ 1 ] * t[ 1 ][ 1 ] % Mod ) % Mod;
            tt[ 1 ][ 0 ] = ( a[ 1 ][ 0 ] * t[ 0 ][ 0 ] % Mod + a[ 1 ][ 1 ] * t[ 1 ][ 0 ] % Mod ) % Mod;
            tt[ 1 ][ 1 ] = ( a[ 1 ][ 0 ] * t[ 0 ][ 1 ] % Mod + a[ 1 ][ 1 ] * t[ 1 ][ 1 ] % Mod ) % Mod;
            memcpy( t, tt, sizeof( tt ) );
        }
        tt[ 0 ][ 0 ] = ( a[ 0 ][ 0 ] * a[ 0 ][ 0 ] % Mod + a[ 0 ][ 1 ] * a[ 1 ][ 0 ] % Mod ) % Mod;
        tt[ 0 ][ 1 ] = ( a[ 0 ][ 0 ] * a[ 0 ][ 1 ] % Mod + a[ 0 ][ 1 ] * a[ 1 ][ 1 ] % Mod ) % Mod;
        tt[ 1 ][ 0 ] = ( a[ 1 ][ 0 ] * a[ 0 ][ 0 ] % Mod + a[ 1 ][ 1 ] * a[ 1 ][ 0 ] % Mod ) % Mod;
        tt[ 1 ][ 1 ] = ( a[ 1 ][ 0 ] * a[ 0 ][ 1 ] % Mod + a[ 1 ][ 1 ] * a[ 1 ][ 1 ] % Mod ) % Mod;
        memcpy( a, tt, sizeof( tt ) );
        n /= 2;
    }
    return;
}
        

void work() {
    one[ 0 ][ 0 ] = 1; one[ 0 ][ 1 ] = 0; one[ 1 ][ 0 ] = 0; one[ 1 ][ 1 ] = 1;
    a[ 0 ][ 0 ] = 0; a[ 0 ][ 1 ] = 1; a[ 1 ][ 0 ] = 1; a[ 1 ][ 1 ] = 1;
    Mu( k * 2 + 3 - 1 );
    printf( "%lld\n", ( t[ 1 ][ 1 ] - 1 + Mod ) % Mod);
} 

int main() {
    while( scanf( "%lld", &k ) == 1 ) work();
    return 0;
}
