#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxN = 100010;
const int INF = 2147483647;
int N;
struct Node {
	int x, y;
	Node( int x_ = 0, int y_ = 0 ) { x = x_; y = y_; return; }
};
Node a[ MaxN ];
bool cmp( Node x, Node y ) {
	return x.x < y.x || x.x == y.x && x.y > y.y;
}

int work() {
	int ans = INF, Maxnum = -INF;
	memset( a, 0, sizeof( a ) );
	scanf( "%d", &N );
	for( int i = 1; i <= N; ++i ) scanf( "%d%d", &a[ i ].x, &a[ i ].y );
	sort( a + 1, a + N + 1, cmp );
	ans = min(ans, a[ N ].x );
	for( int i = N; i > 1; --i ) {
		Maxnum = max( Maxnum, a[ i ].y );
		ans = min( ans, a[ i - 1 ].x + Maxnum );
	}
	Maxnum = max( Maxnum, a[ 1 ].y );
	ans = min( ans, Maxnum );
	return ans;
}

int main() {
	int t; scanf( "%d", &t );
	for( int i = 1; i <= t; ++i ) printf( "Case %d: %d\n", i, work() );
	return 0;
}
