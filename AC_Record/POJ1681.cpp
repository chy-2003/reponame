#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 2147483647;
const int bz[ 2 ][ 5 ] = { { -1, 0, 1, 0, 0 }, { 0, 1, 0, -1, 0 } };
int n;
char ch[ 20 ][ 20 ];
int Matrix[ 250 ][ 250 ];
int Vis[ 250 ];
int Index[ 250 ], Sort[ 250 ];
int Free[ 250 ];

int f( int x, int y ) { return x * n + y + 1; }

void Debug() {
	printf( "==========Debug==========\n" );
	for( int i = 1; i <= n * n; ++i ) {
		for( int j = 1; j <= n * n + 1; ++j ) printf( "%3d", Matrix[ i ][ j ] );
		printf( "\n" );
	}
	printf( "===========End===========\n" );
	return;
}

bool cmp( int x, int y ) {
	return Index[ x ] < Index[ y ];
}

void Work() {
	memset( Matrix, 0, sizeof( Matrix ) );
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i ) scanf( "%s", ch[ i ] );
	for( int i = 0; i < n; ++i ) 
		for( int j = 0; j < n; ++j )
			if( ch[ i ][ j ] == 'w' ) 
				Matrix[ f( i, j ) ][ n * n + 1 ] = 1;
	for( int i = 0; i < n; ++i ) 
		for( int j = 0; j < n; ++j ) 
			for( int k = 0; k < 5; ++k ) {
				int x = i + bz[ 0 ][ k ], y = j + bz[ 1 ][ k ];
				if( x >= 0 && x < n && y >= 0 && y < n ) {
					int u = f( x, y ), v = f( i, j );
					Matrix[ v ][ u ] = ( Matrix[ v ][ u ] + 1 ) % 2;
				}
			}
	memset( Vis, 0, sizeof( Vis ) );
	for( int i = 1; i <= n * n; ++i ) {
		int id = 0;
		for( int j = 1; j <= n * n; ++j )
			if( !Vis[ j ] && Matrix[ j ][ i ] ) 
				id = j;
		if( !id ) continue;
		Vis[ id ] = 1;
		for( int j = 1; j <= n * n; ++j )
			if( Matrix[ j ][ i ] && j != id )
				for( int k = 1; k <= n * n + 1; ++k )
					Matrix[ j ][ k ] = ( Matrix[ j ][ k ] + Matrix[ id ][ k ] ) % 2;
	}
	//Debug();
	//No Answer
	for( int i = 1; i <= n * n; ++i ) {
		int Cnt = 0;
		for( int j = 1; j <= n * n; ++j ) 
			Cnt += Matrix[ i ][ j ];
		if( Cnt == 0 && Matrix[ i ][ n * n + 1 ] ) {
			printf( "inf\n" );
			return;
		}
	}
	//Get Num
	memset( Index, 0, sizeof( Index ) );
	for( int i = 1; i <= n * n; ++i ) {
		for( int j = 1; j <= n * n; ++j )
			if( Matrix[ i ][ j ] ) {
				Index[ i ] = j;
				break;
			}
		if( !Index[ i ] ) Index[ i ] = n * n + 1;
	}
	int Num = 0;
	memset( Vis, 0, sizeof( Vis ) );
	for( int i = 1; i <= n * n; ++i ) Vis[ Index[ i ] ] = 1;
	for( int i = 1; i <= n * n; ++i ) 
		if( !Vis[ i ] )
			Free[ ++Num ] = i;
	//One Answer Only
	if( Num == 0 ) {
		int ans = 0;
		for( int i = 1; i <= n * n; ++i )
			if( Matrix[ i ][ n * n + 1 ] ) ++ans;
		printf( "%d\n", ans );
		return;
	}
	//Multi Answers
	for( int i = 1; i <= n * n; ++i ) Sort[ i ] = i;
	sort( Sort + 1, Sort + n * n + 1, cmp );
	int Ans = INF;
	for( int i = 0; i < 1 << Num; ++i ) {
		int Cnt = 0;
		memset( Vis, 0, sizeof( Vis ) );
		for( int j = 1; j <= Num; ++j ) 
			if( ( i >> ( j - 1 ) ) & 1 ) 
				Vis[ Free[ j ] ] = 1, ++Cnt;
		for( int j = n * n - Num; j >= 1; --j ) {
			int u = Sort[ j ];
			for( int k = Index[ u ] + 1; k <= n * n; ++k ) 
				Matrix[ u ][ n * n + 1 ] = ( Matrix[ u ][ n * n + 1 ] + Matrix[ u ][ k ] * Vis[ k ] ) % 2;
			if( Matrix[ u ][ n * n + 1 ] ) 
				Vis[ Index[ u ] ] = 1, ++Cnt;
			for( int k = Index[ u ] + 1; k <= n * n; ++k ) 
				Matrix[ u ][ n * n + 1 ] = ( Matrix[ u ][ n * n + 1 ] + Matrix[ u ][ k ] * Vis[ k ] ) % 2;
		}
		Ans = min( Ans, Cnt );
	}
	printf( "%d\n", Ans );
	return;
}

int main() {
	int t; scanf( "%d", &t );
	for( int i = 1; i <= t; ++i ) Work();
	return 0;
}
