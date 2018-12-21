#include <bits/stdc++.h>
#define LL long long
using namespace std;

const LL Maxn = 100010;
struct node {
	LL Val, Father, Child[ 2 ], Size, Tag;
};
node Tree[ Maxn ];
LL n, m, Root = 0, Used;

void Update( LL Index ) {
	Tree[ Index ].Size = Tree[ Tree[ Index ].Child[ 0 ] ].Size + Tree[ Tree[ Index ].Child[ 1 ] ].Size + 1;
	return;
}

void TagDown( LL Index ) {
	if( Tree[ Index ].Tag ) {
		Tree[ Tree[ Index ].Child[ 0 ] ].Tag ^= 1;
		Tree[ Tree[ Index ].Child[ 1 ] ].Tag ^= 1;
		Tree[ Index ].Tag = 0;
		swap( Tree[ Index ].Child[ 0 ], Tree[ Index ].Child[ 1 ] );
	}
	return;
}

void Rotate( LL Index ) {
	LL x = Index;
	LL y = Tree[ x ].Father;
	LL z = Tree[ y ].Father;
	LL Tag = Tree[ y ].Child[ 1 ] == x;
	Tree[ z ].Child[ Tree[ z ].Child[ 1 ] == y ] = x;
	Tree[ x ].Father = z;
	Tree[ y ].Child[ Tag ] = Tree[ x ].Child[ Tag ^ 1 ];
	Tree[ Tree[ x ].Child[ Tag ^ 1 ] ].Father = y;
	Tree[ x ].Child[ Tag ^ 1 ] = y;
	Tree[ y ].Father = x;
	Update( x ); Update( y );
	return;
}

void Splay( LL Index, LL Goal ) {
	LL x = Index;
	while( Tree[ x ].Father != Goal ) {
		LL y = Tree[ x ].Father; LL z = Tree[ y ].Father;
		if( z != Goal ) 
			if( ( Tree[ z ].Child[ 0 ] == y ) ^ ( Tree[ y ].Child[ 0 ] == x ) )
				Rotate( x );
			else 
				Rotate( y );
		Rotate( x );
	}
	if( Goal == 0 ) Root = x;
}

void Insert( LL x ) {
	LL root = Root, t = 0;
	while( root ) {
		t = root;
		root = Tree[ root ].Child[ x > Tree[ root ].Val ];
	}
	root = ++Used;	
	if( t ) Tree[ t ].Child[ x > Tree[ t ].Val ] = root;
	Tree[ root ].Val = x;
	Tree[ root ].Child[ 0 ] = Tree[ root ].Child[ 1 ] = 0;
	Tree[ root ].Size = 1;
	Tree[ root ].Father = t;
	Splay( root, 0 );
	return;
}

LL Kth( LL k ) {
	LL root = Root;
	while( 1 ) {
		TagDown( root );
		if( Tree[ Tree[ root ].Child[ 0 ] ].Size >= k ) 
			root = Tree[ root ].Child[ 0 ];
		else 
			if( Tree[ Tree[ root ].Child[ 0 ] ].Size + 1 == k ) 
				return root;
			else {
				k -= Tree[ Tree[ root ].Child[ 0 ] ].Size + 1;
				root = Tree[ root ].Child[ 1 ];
			}
	}
	return root;
}

void Work( LL L, LL R ) {
	LL l = Kth( L ), r = Kth( R + 2 );
	Splay( l, 0 );
	Splay( r, l );
	Tree[ Tree[ Tree[ Root ].Child[ 1 ] ].Child[ 0 ] ].Tag ^= 1;
	return;
}

void Print( LL Index ) {
	TagDown( Index );
	if( Tree[ Index ].Child[ 0 ] ) Print( Tree[ Index ].Child[ 0 ] );
	if( Tree[ Index ].Val > 1 && Tree[ Index ].Val < n + 2 ) printf( "%lld ", Tree[ Index ].Val - 1 );
	if( Tree[ Index ].Child[ 1 ] ) Print( Tree[ Index ].Child[ 1 ] );
	return;
}

int main() {
	scanf( "%lld%lld", &n, &m );
	for( LL i = 1; i <= n + 2; ++i ) Insert( i );
	for( LL i = 1; i <= m; ++i ) {
		LL L, R;
		scanf( "%lld%lld", &L, &R );
		Work( L, R );
	}
	Print( Root );
	printf( "\n" );
	return 0;
}
