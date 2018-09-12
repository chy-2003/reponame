#include <cstdio>
#include <cstring>
#include <algorithm>

int ReadInt() {
	char ch = getchar(); int t = 0, f = 1;
	while( ch < '0' || ch > '9' ) {
		if( ch == '-' ) f = -f;
		ch = getchar();
	}
	while( ch >= '0' && ch <= '9' ) {
		t = t * 10 - '0' + ch;
		ch = getchar();
	}
	return f * t;
}

int N, P, M;
int a[ 1010 ][ 1010 ], b[ 1010 ][ 1010 ], c[ 1010 ][ 1010 ];
int x, y, z;

bool Check() {
	for( int i = 1; i <= N; ++i )
		for( int j = 1; j <= M; ++j ) {
			int t = 0;
			for( int k = 1; k <= P; ++k )
				t += a[ i ][ k ] * b[ k ][ j ];
			if( t != c[ i ][ j ] ) {
				x = i; y = j; z = t;
				return false;
			}
		}
	return true;
}

int main() {
	N = ReadInt(); P = ReadInt(); M = ReadInt();
	for( int i = 1; i <= N; ++i )
		for( int j = 1; j <= P; ++j )
			a[ i ][ j ] = ReadInt();
	for( int i = 1; i <= P; ++i ) 
		for( int j = 1; j <= M; ++j ) 
			b[ i ][ j ] = ReadInt();
	for( int i = 1; i <= N; ++i )
		for( int j = 1; j <= M; ++j ) 
			c[ i ][ j ] = ReadInt();
	if( Check() ) printf( "Yes\n" );
	else {
		printf( "No\n" );
		printf( "%d %d\n%d\n", x, y, z );
	}
	return 0;
}
