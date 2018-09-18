#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int Maxn = 200010, Maxm = 500010, Maxq = 200010;
int n, m, kk, q;
int Used = 0, Link[ Maxm << 1 ], Next[ Maxm << 1 ];
int Ans[ Maxn ];
int Reflection[ Maxn ];

struct node {
	int Power, Value, id, F;
	map< int, int > mp;
	int Ans, Siz;
public :
	void A( int x ) {
		if( mp.find( x ) == mp.end() ) {
			mp[ x ] = 1;
			if( !( mp[ x ] % kk ) ) ++Ans;
		} else {
			if( !( mp[ x ] % kk ) ) --Ans;
			++mp[ x ];
			if( !( mp[ x ] % kk ) ) ++Ans;
		}
		return;
	}
	void D( int x ) {
		if( !( mp[ x ] % kk ) ) --Ans;
		--mp[ x ];
		if( !( mp[ x ] % kk ) ) ++Ans;
		if( mp[ x ] == 0 ) mp.erase( x );
		return;
	}
};
struct query {
	int Power, id, Num;
	vector< int > Rec;
};
node P[ Maxn ];
query Q[ Maxq ];

inline void AddEdge( int x, int y ) {
	++Used;
	Link[ Used ] = y;
	Next[ Used ] = P[ x ].F;
	P[ x ].F = Used;
	return;
}

bool cmp1( node x, node y ) { return x.Power < y.Power; }

bool cmp2( query x, query y ) { return x.Power < y.Power; }

void init() {
	scanf( "%d%d%d", &n, &m, &kk );
	for( int i = 1; i <= n; ++i ) scanf( "%d", &P[ i ].Power );
	for( int i = 1; i <= n; ++i ) scanf( "%d", &P[ i ].Value );
	for( int i = 1; i <= n; ++i ) {
		P[ i ].id = i; P[ i ].F = 0; P[ i ].mp.clear(); P[ i ].Ans = 0; P[ i ].Siz = 1;
	}
	for( int i = 1; i <= m; ++i ) {
		int x, y;
		scanf( "%d%d", &x, &y );
		AddEdge( x, y );
		AddEdge( y, x );
	}
	sort( P + 1, P + n + 1, cmp1 );
	for( int i = 1; i <= n; ++i ) Reflection[ P[ i ].id ] = i;
	scanf( "%d", &q );
	for( int i = 1; i <= q; ++i ) {
		Q[ i ].id = i;
		scanf( "%d%d", &Q[ i ].Power, &Q[ i ].Num );
		Q[ i ].Rec.clear();
		for( int j = 1; j <= Q[ i ].Num; ++j ) {
			int x;
			scanf( "%d", &x ); Q[ i ].Rec.push_back( x );
		}
	}
	sort( Q + 1, Q + q + 1, cmp2 );
	return;
}

int Father[ Maxn ], Deleted[ Maxn ], Vis[ Maxn ];
map< int, int > Bigmp;

inline int GetFather( int x ) {
	if( Father[ x ] == x ) return x;
	Father[ x ] = GetFather( Father[ x ] );
	return Father[ x ];
}

inline void BigmpA( int t ) {
	if( Bigmp.find( t ) == Bigmp.end() ) Bigmp[ t ] = 1; else ++Bigmp[ t ];
	return;
}

inline void BigmpD( int t ) {
	--Bigmp[ t ];
	if( Bigmp[ t ] == 0 ) Bigmp.erase( t );
	return;
}

void Unite( int x, int y ) {
	int a = GetFather( x ), b = GetFather( y );
	if( a == b ) return;
	if( P[ a ].Siz < P[ b ].Siz ) {
		Unite( b, a );
		return;
	}
	BigmpD( P[ a ].Ans );
	BigmpD( P[ b ].Ans );
	Father[ b ] = a;
	P[ a ].Siz += P[ b ].Siz;
	for( map< int, int >::iterator it = P[ b ].mp.begin(); it != P[ b ].mp.end(); ++it ) {
		if( P[ a ].mp.find( ( *it ).first ) == P[ a ].mp.end() ) {
			P[ a ].mp[ ( *it ).first ] = ( *it ).second;
			if( !( P[ a ].mp[ ( *it ).first ] % kk ) ) ++P[ a ].Ans;
		} else {
			if( !( P[ a ].mp[ ( *it ).first ] % kk ) ) --P[ a ].Ans;
			P[ a ].mp[ ( *it ).first ] += ( *it ).second;
			if( !( P[ a ].mp[ ( *it ).first ] % kk ) ) ++P[ a ].Ans;
		}
	}
	BigmpA( P[ a ].Ans );
	return;
}

void Add( int x ) {
	Vis[ x ] = 1;
	P[ x ].A( P[ x ].Value );
	BigmpA( P[ x ].Ans );
	for( int t = P[ x ].F; t; t = Next[ t ] ) {
		int u = Reflection[ Link[ t ] ];
		if( !Vis[ u ] ) continue;
		Unite( u, x );
	}
	return;
}

void work() {
	memset( Vis, 0, sizeof( Vis ) );
	memset( Deleted, 0, sizeof( Deleted ) );
	Bigmp.clear();
	for( int i = 1; i <= n; ++i ) Father[ i ] = i;
	int j = 0;
	for( int i = 1; i <= q; ++i ) {
		while( j < n && P[ j + 1 ].Power <= Q[ i ].Power ) Add( ++j );
		for( int _ = 0; _ < Q[ i ].Num; ++_ ) {
			int t = GetFather( Reflection[ Q[ i ].Rec[ _ ] ] );
			if( Deleted[ t ] ) continue;
			BigmpD( P[ t ].Ans );
			Deleted[ t ] = 1;
		}
		if( Bigmp.empty() ) {
			Ans[ Q[ i ].id ] = 0;
		} else {
			map< int, int >::iterator it = Bigmp.end();
			it--;
			Ans[ Q[ i ].id ] = ( *it ).first;
		}
		for( int _ = 0; _ < Q[ i ].Num; ++_ ) {
			int t = GetFather( Reflection[ Q[ i ].Rec[ _ ] ] );
			if( !Deleted[ t ] ) continue;
			BigmpA( P[ t ].Ans );
			Deleted[ t ] = 0;
		}
	}
	return;
}

inline void print() {
	for( int i = 1; i <= q; ++i ) printf( "%d\n", Ans[ i ] );
	return;
}

int main() {
	init();
	work();
	print();
	return 0;
}
