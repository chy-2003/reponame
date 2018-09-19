#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 310;
int n, pos[ Maxn ], delta[ Maxn ];
int dp[ Maxn ][ Maxn ];
int Sum1[ Maxn ] , Sum2[ Maxn ];

int main() {
	memset( dp, 255, sizeof( dp ) );
	scanf( "%d", &n );
	for( int i = 1; i <= n; ++i ) scanf( "%d", &pos[ i ] ); pos[ 0 ] = 0;
	for( int i = 1; i <= n; ++i ) scanf( "%d", &delta[ i ] );
	for( int i = 1; i <= n; ++i ) Sum1[ i ] = Sum1[ i - 1 ] + delta[ i ];
	for( int i = 1; i <= n; ++i ) Sum2[ i ] = Sum2[ i - 1 ] + max( 0, delta[ i ] );
	dp[ 0 ][ 0 ] = 0;
	for( int i = 1; i <= n; ++i ) {
		for( int j = 0; j <= n; ++j ) {
			if( dp[ i - 1 ][ j ] == -1 ) continue;
			if( dp[ i ][ j ] == -1 || dp[ i ][ j ] > dp[ i - 1 ][ j ] + pos[ i ] - pos[ i - 1 ] )
				dp[ i ][ j ] = dp[ i - 1 ][ j ] + pos[ i ] - pos[ i - 1 ];
		}
		for( int j = 0; j < i; ++j )
			for( int k = j; k <= i; ++k ) {
				if( Sum1[ k ] + Sum2[ i ] - Sum2[ k ] < 0 ) continue;
				if( dp[ i ][ k ] == -1 || dp[ i ][ k ] > dp[ i ][ j ] + 2 * ( pos[ i ] - pos[ j + 1 ] ) )
					dp[ i ][ k ] = dp[ i ][ j ] + 2 * ( pos[ i ] - pos[ j + 1 ] );
			}
	}
//	for( int i = 0; i <= n; ++i ) {
//		for( int j = 0; j <= n; ++j ) printf( "%4d", dp[ i ][ j ] );
//		printf( "\n" );
//	}
	printf( "%d\n", dp[ n ][ n ] );
	return 0;
}
