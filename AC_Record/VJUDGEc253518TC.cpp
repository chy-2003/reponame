#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 30;
const int INF = 2147483647;
struct Node {
	int x, y;
	Node ( int x_ = 0, int y_ = 0 ) { x = x_; y = y_; return; }
};
Node a[ Maxn ];
int n, b, Used[ Maxn ];

bool cmp( Node x, Node y ) { return x.x > y.x; }

int main() {
	scanf( "%d%d", &n, &b );
	for( int i = 1; i <= n; ++i ) scanf( "%d%d", &a[ i ].x, &a[ i ].y );
	sort( a + 1, a + n + 1, cmp );
	int ans = 0;
	for( int i = 1; i <= n; ++i ) 
		if( a[ i ].x >= b ) {
			ans += a[ i ].y;
			a[ i ].y = 0;
		}
	for(;;) {
		int t = b;
		memset( Used, 0, sizeof( Used ) );
		for( int i = 1; i <= n; ++i ) {
			if( t <= 0 ) break;
			if( a[ i ].y == 0 ) continue;
			int k = min( a[ i ].y, t / a[ i ].x );
			Used[ i ] = k;
			t -= a[ i ].x * k;
		}
		for( int i = n; i >= 1; --i ) {
			if( t <= 0 ) break;
			if( a[ i ].y <= Used[ i ] ) continue;
			int left = a[ i ].y - Used[ i ];
			int k = t / a[ i ].x;
			if( t % a[ i ].x != 0 ) ++k;
			k = min( k, left );
			Used[ i ] += k;
			t-= a[ i ].x * k;
		}
		if( t > 0 ) break;
		int count = INF;
		for( int i = 1; i <= n; ++i ) {
			if( Used[ i ] == 0 ) continue;
			count = min( count, a[ i ].y / Used[ i ] );
		}
		ans += count;
		for( int i= 1; i <= n; ++i ) a[ i ].y -= Used[ i ] * count;
	}
	printf( "%d\n", ans );
	return 0;
}
