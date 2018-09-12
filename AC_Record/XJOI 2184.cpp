#include <cstdio>
#include <cstring>
#include <algorithm>

const int Maxn = 510;
int n, m;
int Father[ Maxn ];
int InDegree[ Maxn ], OutDegree[ Maxn ];

int GetFather( int x ) {
	if( Father[ x ] == x ) return x;
	Father[ x ] = GetFather( Father[ x ] );
	return Father[ x ];
}

int main() {
	scanf( "%d%d", &n, &m );
	for( int i = 1; i <= n; ++i ) Father[ i ] = i;
	for( int i = 1; i <= m; ++i ) {
		int x, y;
		scanf( "%d%d", &x, &y );
		OutDegree[ x ]++;
		InDegree[ y ]++;
		int a = GetFather( x ), b = GetFather( y );
		if( a != b ) Father[ b ] = a;
	}
	int count = 0;
	for( int i = 1; i <= n; i++ ) 
		if( Father[ i ] == i ) count++;
	if( count > 1 ) {
		printf( "No\n" );
		return 0;
	}
	for( int i = 1; i <= n; i++ ) 
		if( InDegree[ i ] != OutDegree[ i ] ) {
			printf( "No\n" );
			return 0;
		}
	printf( "Yes\n" );
	return 0;
}
