#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 60;
int n, m, a[ Maxn ];
double dp[ Maxn ][ Maxn ][ Maxn ], C[ 60 ][ 60 ];

double Power( double x, int y ) {
	if( y == 0 ) return 1.0;
	double t = Power( x, y / 2 );
	t = t * t;
	if( y % 2 == 1 ) t = t * x;
	return t;
}

void init() {
	memset( C, 0, sizeof( C ) );
	C[ 0 ][ 0 ] = 1.0;
	for( int i = 1; i <= 50; ++i ) {
		C[ i ][ 0 ] = 1.0;
		for( int j = 1; j <= i; ++j ) C[ i ][ j ] = C[ i - 1 ][ j - 1 ] + C[ i - 1 ][ j ];
	}
	return;
}

int main() {
	init();
	memset( dp, 0, sizeof( dp ) );
	scanf( "%d%d", &n, &m );
	dp[ 0 ][ n ][ 0 ] = 1.0;
	for( int i = 1; i <= m; ++i ) scanf( "%d", &a[ i ] );
	for( int i = 0; i < m - 1; ++i ) 
		for( int j = 0; j <= n; ++j ) 
			for( int k = 0; k <= n; ++k )
				for( int c = 0; c <= j; ++c ) 
					dp[ i + 1 ][ j - c ][ max( k, ( c + a[ i + 1 ] - 1 ) / a[ i + 1 ] ) ] += 
						dp[ i ][ j ][ k ] * C[ j ][ c ] / Power( m * 1.0, c );
	for( int j = 0; j <= n; ++j )
		for( int k = 0; k <= n; ++k ) 
			dp[ m ][ 0 ][ max( k, ( j + a[ m ] - 1 ) / a[ m ] ) ] += dp[ m - 1 ][ j ][ k ] * 1.0 / Power( m * 1.0, j );
	double ans;
	for( int i = 0; i <= n; ++i )
		ans += i * dp[ m ][ 0 ][ i ];
	printf( "%.10lf\n", ans );
	return 0;
}
