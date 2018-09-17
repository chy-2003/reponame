#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int Cost[ 2010 ], Cnt[ 110 ];

int f( int x ) {
	if( x == 0 ) return 6;
	if( x == 1 ) return 2;
	if( x == 2 ) return 5;
	if( x == 3 ) return 5;
	if( x == 4 ) return 4;
	if( x == 5 ) return 5;
	if( x == 6 ) return 6;
	if( x == 7 ) return 3;
	if( x == 8 ) return 7;
	if( x == 9 ) return 6;
}

int main() {
	int n; scanf( "%d", &n );
	n -= 4;
	Cost[ 0 ] = 6;
	for( int i = 1; i <= 2000; ++i ) {
		int t = i;
		while( t ) {
			Cost[ i ] += f( t % 10 );
			t /= 10;
		}
	}
	int ans = 0;
	for( int i = 0; i <= 2000; ++i )
		for( int j = 0; j <= i; ++j )
			if( Cost[ i ] + Cost[ j ] + Cost[ i - j ] == n ) ans++;
	printf( "%d\n", ans );
	return 0;
}
