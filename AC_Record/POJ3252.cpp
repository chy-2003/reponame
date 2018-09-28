#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int Start, Finish;
int a[ 35 ], b[ 35 ];
int dp[ 35 ][ 2 ][ 4 ][ 70 ][ 2 ]; // Pos, Number, UD, Delta, Has 1 appeard?

int f( int x, int y ) {
	if( x == 1 ) return ( y == 1 ) ? -1 : 1;
	if( x == 0 ) return ( y == 1 ) ? -1 : 0;
	return 0;
}

int g( int x, int y ) {
	if( x == 1 ) return 0;
	if( x == 0 && y == 1 ) return 1;
	return 0;
}

int main() {
	cin >> Start >> Finish;
	memset( a, 0, sizeof( a ) );
	memset( b, 0, sizeof( b ) );
	memset( dp, 0, sizeof( dp ) );
	for( int i = 1; i <= 32; ++i ) {
		a[ i ] = Start % 2;
		Start /= 2;
	}
	for( int i = 1; i <= 32; ++i ) {
		b[ i ] = Finish % 2;
		Finish /= 2;
	}
	dp[ 33 ][ 0 ][ 3 ][ 35 ][ 0 ] = 1;
	for( int i = 33; i > 1; --i ) 
		for( int j = 0; j <= 1; ++j ) 
			for( int k = 0; k <= 3; ++k ) 
				for( int l = 1; l < 69; ++l )
					for( int p = 0; p <= 1; ++p ) {
						if( !dp[ i ][ j ][ k ][ l ][ p ] ) continue;
						if( k == 3 ) {
							if( a[ i - 1 ] == b[ i - 1 ] ) 
								dp[ i - 1 ][ a[ i - 1 ] ][ 3 ][ l + f( p, a[ i - 1 ] ) ][ p + g( p, a[ i - 1 ] ) ] += dp[ i ][ j ][ k ][ l ][ p ];
							else {
								dp[ i - 1 ][ a[ i - 1 ] ][ 2 ][ l + f( p, a[ i - 1 ] ) ][ p + g( p, a[ i - 1 ] ) ] += dp[ i ][ j ][ k ][ l ][ p ];
								dp[ i - 1 ][ b[ i - 1 ] ][ 1 ][ l + f( p, b[ i - 1 ] ) ][ p + g( p, b[ i - 1 ] ) ] += dp[ i ][ j ][ k ][ l ][ p ];
							}
						}
						if( k == 2 ) {
							dp[ i - 1 ][ a[ i - 1 ] ][ 2 ][ l + f( p, a[ i - 1 ] ) ][ p + g( p, a[ i - 1 ] ) ] += dp[ i ][ j ][ k ][ l ][ p ];
							if( a[ i - 1 ] == 0 ) 
								dp[ i - 1 ][ 1 ][ 0 ][ l + f( p, 1 ) ][ p + g( p, 1 ) ] += dp[ i ][ j ][ k ][ l ][ p ];
						}
						if( k == 1 ) {
							dp[ i - 1 ][ b[ i - 1 ] ][ 1 ][ l + f( p, b[ i - 1 ] ) ][ p + g( p, b[ i - 1 ] ) ] += dp[ i ][ j ][ k ][ l ][ p ];
							if( b[ i - 1 ] == 1 )
								dp[ i - 1 ][ 0 ][ 0 ][ l + f( p, 0 ) ][ p + g( p, 0 ) ] += dp[ i ][ j ][ k ][ l ][ p ];
						}
						if( k == 0 ) {
							dp[ i - 1 ][ 0 ][ 0 ][ l + f( p, 0 ) ][ p + g( p, 0 ) ] += dp[ i ][ j ][ k ][ l ][ p ];
							dp[ i - 1 ][ 1 ][ 0 ][ l + f( p, 1 ) ][ p + g( p, 1 ) ] += dp[ i ][ j ][ k ][ l ][ p ];
						}
					}
	int ans = 0;
	for( int i = 0; i <= 1; ++i ) 
		for( int j = 0; j <= 3; ++j ) 
			for( int k = 35; k < 70; ++k )
				ans += dp[ 1 ][ i ][ j ][ k ][ 1 ];
	printf( "%d\n", ans );
	return 0;
}
