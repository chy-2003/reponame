#include <bits/stdc++.h>
#define LL long long
using namespace std;

const LL Maxn = 100010;
const LL Maxk = 200010;
LL n, k;
struct tree {
	private :
		LL Tree[ Maxk ];
		LL lowbit( LL x ) { return x & -x; }
	public :
		void Clear() { memset( Tree, 0, sizeof( Tree ) ); return; }
		void Add( LL Index, LL Val ) {
			for( LL i = Index; i <= k; i += lowbit( i ) ) 
				Tree[ i ] += Val;
			return;
		}
		LL Query( LL Index ) {
			LL Ans = 0;
			for( LL i = Index; i; i -= lowbit( i ) ) 
				Ans += Tree[ i ];
			return Ans;
		}
};
tree Tree;
struct node {
	LL x, y, z, Index;
	node() { x = y = z = Index = 0; return; }
	bool operator != ( const node Other ) const {
		return x != Other.x || y != Other.y || z != Other.z;
	}
};
node A[ Maxn ], Temp[ Maxn ];
LL Ans[ Maxn ], ans[ Maxn ], Size[ Maxn ], Num;

bool Cmp1( node x, node y ) {
	return x.x < y.x || x.x == y.x && x.y < y.y || x.x == y.x && x.y == y.y && x.z < y.z;
}

void Cdq( LL L, LL R ) {
	if( L == R ) return;
	LL Mid = L + R >> 1;
	Cdq( L, Mid ); Cdq( Mid + 1, R );
	LL l = L, r = Mid + 1, Index = l;
	while( l <= Mid && r <= R ) {
		if( A[ l ].y <= A[ r ].y ) {
			Temp[ Index++ ] = A[ l ]; 
			Tree.Add( A[ l ].z, Size[ A[ l ].Index ] );
			++l;
		} else {
			Temp[ Index++ ] = A[ r ];
			ans[ A[ r ].Index ] += Tree.Query( A[ r ].z );
			++r;
		}
	}
	while( l <= Mid ) {
		Temp[ Index++ ] = A[ l ];
		Tree.Add( A[ l ].z, Size[ A[ l ].Index ] );
		++l;
	}
	while( r <= R ) {
		Temp[ Index++ ] = A[ r ];
		ans[ A[ r ].Index ] += Tree.Query( A[ r ].z );
		++r;
	}
	for( LL i = L; i <= Mid; ++i ) Tree.Add( A[ i ].z, -Size[ A[ i ].Index ] );
	for( LL i = L; i <= R; ++i ) A[ i ] = Temp[ i ];
	return;
}

int main() {
	scanf( "%lld%lld", &n, &k );
	for( LL i = 1; i <= n; ++i ) 
		scanf( "%lld%lld%lld", &A[ i ].x, &A[ i ].y, &A[ i ].z );
	sort( A + 1, A + n + 1, Cmp1 );
	for( LL i = 1; i <= n; ++i )
		if( A[ i ] != A[ i - 1 ] ) {
			Temp[ ++Num ] = A[ i ];
			Size[ Num ] = 1;
		} else ++Size[ Num ];
	for( LL i = 1; i <= Num; ++i ) 
		A[ i ] = Temp[ i ];
	for( LL i = 1; i <= Num; ++i ) A[ i ].Index = i;
	Cdq( 1, Num );
	for( LL i = 1; i <= Num; ++i ) 
		Ans[ ans[ A[ i ].Index ] + Size[ A[ i ].Index ] - 1 ] += Size[ A[ i ].Index ];
	for( LL i = 0; i < n; ++i )
		printf( "%lld\n", Ans[ i ] );
	return 0;
}
