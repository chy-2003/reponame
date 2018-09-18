/* number	up 		donw 	delta total
 * 0		a 		0 				a
 * 1		k 		k 				a
 * 2		a+k		k 				2a
 * 3		a+2k	a+k				2a+k
 * 4		2a+3k	a+2k			3a+2k
 * 5		3a+5k	2a+3k			4a+4k
 * 6		5a+8k	3a+5k			6a+7k
 * 7		8a+13k	5a+8k			9a+12k
 *
 * n		fn		fn+a-k+fn-1=m	0
 * f0=(1,0) f1=(0,1) f2=(1,1) f3=(1,2) f4=(2,3) fn=fn-2+fn-1
 */
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a, n, m, x, f[ 30 ][ 2 ];

int main() {
	scanf( "%d%d%d%d", &a, &n, &m, &x ); --n; --x;
	f[ 0 ][ 0 ] = 1;
	f[ 0 ][ 1 ] = 0;
	f[ 1 ][ 0 ] = 0;
	f[ 1 ][ 1 ] = 1;
	for( int i = 2; i <= n + 1; ++i ) {
		f[ i ][ 0 ] = f[ i - 1 ][ 0 ] + f[ i - 2 ][ 0 ];
		f[ i ][ 1 ] = f[ i - 1 ][ 1 ] + f[ i - 2 ][ 1 ];
	}
//	for( int i = 1; i <= n; ++i ) printf( "%d %d\n", f[ i ][ 0 ], f[ i ][ 1 ] );
	int ta = f[ n - 1 ][ 0 ] + 1, tk = f[ n - 1 ][ 1 ] - 1;
//	printf( "ta = %d       tk = %d\n", ta, tk );
	int k = ( m - ta * a ) / tk;
//	printf( "k = %d\n", k );
	printf( "%d\n", f[ x ][ 0 ] * a + f[ x ][ 1 ] * k + a - k );
	return 0;
}
