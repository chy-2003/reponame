#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 5010;
int n, a[ Maxn ];

struct node {
	int Min, Id;
	node( int Min_ = 0, int Id_ = 0 ) { Min = Min_; Id = Id_; return; }
};
node Seg[ Maxn << 2 ];

void Build( int Pos, int L, int R ) {
	if( L == R ) {
		Seg[ Pos ] = node( a[ L ], L );
		return;
	}
	int Mid = L + R >> 1;
	Build( Pos << 1, L, Mid );
	Build( Pos << 1 | 1, Mid + 1, R );
	if( Seg[ Pos << 1 ].Min < Seg[ Pos << 1 | 1 ].Min ) Seg[ Pos ] = Seg[ Pos << 1 ]; else Seg[ Pos ] = Seg[ Pos << 1 | 1 ];
	return;
}

int Query( int l, int r, int Pos, int L, int R ) {
	if( l <= L && R <= r ) return Seg[ Pos ].Id;
	int t1 = 0, t2 = 0, Mid = L + R >> 1;
	if( l <= Mid ) t1 = Query( l, r, Pos << 1, L, Mid );
	if( r > Mid ) t2 = Query( l, r, Pos << 1 | 1, Mid + 1, R );
	if( a[ t1 ] < a[ t2 ] ) return t1; else return t2;
}

int work( int l, int r, int h ) {
	if( l > r ) return 0;
	int t = Query( l, r, 1, 1, n );
	int k = a[ t ] - h + work( l, t - 1, a[ t ] ) + work( t + 1, r, a[ t ] );
	return min( k, r - l  + 1 );
}

int main() {
	scanf( "%d", &n );
	for( int i = 1; i <= n; ++i ) scanf( "%d", &a[ i ] );
	a[ 0 ] = 2147483647;
	Build( 1, 1, n );
	printf( "%d\n", work( 1, n, 0 ) );
	return 0;
}
