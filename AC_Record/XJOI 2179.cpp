#include <cstdio>
#include <cstring>
int n, a[ 1010 ];
void Work() {
	memset( a, 0, sizeof( a ) );
	scanf( "%d", &n );
	for( int i = 1; i <= n; ++i ) scanf( "%d", &a[ i ] );
	for( int i = n; i > 1; --i ) a[ i ] = a[ i ] - a[ i - 1 ];
	int t = 0;
	for( int i = n; i > 0; i -= 2 ) t ^= a[ i ];
	if( t ) printf( "TAK\n" ); else printf( "NIE\n" );
}
int main() {
	int t; scanf( "%d", &t );
	for( int i = 1; i <= t; ++i ) Work();
	return 0;
}
