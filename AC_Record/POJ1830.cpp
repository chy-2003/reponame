#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, Matrix[ 40 ][ 40 ], Vis[ 40 ];

void Debug() {
	printf( "==========Debug==========\n" );
	for( int i = 1; i <= n; ++i ) {
		for( int j = 1; j <= n + 1; ++j ) printf( "%4d ", Matrix[ i ][ j ] );
		printf( "\n" );
	}
	printf( "===========End===========\n" );
	return;
}

void Work() {
	scanf( "%d", &n );
	memset( Matrix, 0, sizeof( Matrix ) );
	for( int i = 1; i <= n; ++i ) scanf( "%d", &Matrix[ i ][ n + 1 ] );
	for( int i = 1; i <= n; ++i ) {
		int x; scanf( "%d", &x );
		Matrix[ i ][ n + 1 ] = ( x + Matrix[ i ][ n + 1 ] ) % 2;
	}
	for( int i = 1; i <= n; ++i ) Matrix[ i ][ i ] = 1;
	int x, y;
	scanf( "%d%d", &x, &y );
	while( !( x == 0 && y == 0 ) ) {
		Matrix[ y ][ x ] = ( Matrix[ y ][ x ] + 1 ) % 2;
		scanf( "%d%d", &x, &y );
	}
	//Debug();
	memset( Vis, 0, sizeof( Vis ) );
	for( int i = 1; i <= n; ++i ) {
		int id = 0;
		for( int j = 1; j <= n; ++j )
			if( !Vis[ j ] && Matrix[ j ][ i ] ) id = j;
		if( id == 0 ) continue;
		Vis[ id ] = 1;
		for( int j = 1; j <= n; ++j )
			if( j != id && Matrix[ j ][ i ] ) 
				for( int k = 1; k <= n + 1; ++k )
					Matrix[ j ][ k ] = ( Matrix[ j ][ k ] + Matrix[ id ][ k ] ) % 2;
	//Debug();
	}
	int t = 1, tCnt = 0;
	for( int i = 1; i <= n; ++i ) {
		int Cnt = 0;
		for( int j = 1; j <= n; ++j ) Cnt += Matrix[ i ][ j ];
	//	if( Cnt > 1 ) {
	//		t = 0;
	//		break;
	//	}
		if( Cnt == 0 && Matrix[ i ][ n + 1 ] ) {
			t = 0;
			break;
		}
		if( Cnt == 0 ) ++tCnt;
	}
	if( t == 0 ) {
		printf( "Oh,it's impossible~!!\n" );
		return;
	}
	int Ans = 1;
	for( int i = 1; i <= tCnt; ++i ) Ans *= 2;
	printf( "%d\n", Ans );
	return;
}

int main() {
	int t; scanf( "%d", &t );
	for( int i = 1; i <= t; ++i ) Work();
	return 0;
}
