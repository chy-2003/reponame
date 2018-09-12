#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx","sse2")
#pragma GCC optimize ("Ofast")
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

int GetInt() {
	char ch; int t = 0;
	ch = getchar();
	while( ch < '0' || ch > '9' ) ch = getchar();
	while( ch >= '0' && ch <= '9' ) {
		t = t * 10 + ch - '0';
		ch = getchar();
	}
	return t;
}

const int MaxN = 100010, MaxBlock = 330;
int n, c, m, a[ MaxN ];
int Sum[ MaxBlock ][ MaxN ], Ans[ MaxBlock ][ MaxBlock ], Count[ MaxN ];
int Belong[ MaxN ], size;
int ans;

int main() {
	n = GetInt(); c = GetInt(); m = GetInt();
	size = sqrt( n ) + 1;
	for( int i = 1; i <= n; ++i ) a[ i ] = GetInt();
	for( int i = 1; i <= n; ++i ) Belong[ i ] = ( i - 1 ) / size + 1;
	for( int i = 1; i <= n; ++i ) 
		++Sum[ Belong[ i ] ][ a[ i ] ];
	for( int i = 1; i <= Belong[ n ]; ++i ) 
		for( int j = 1; j <= c; ++j )
			Sum[ i ][ j ] += Sum[ i - 1 ][ j ];
	for( int i = 1; i <= Belong[ n ]; ++i ) {
		int t = 0;
		memset( Count, 0, sizeof( Count ) );
		for( int j = ( i - 1 ) * size + 1; j <= n; ++j ) {
			++Count[ a[ j ] ];
			if( Count[ a[ j ] ] > 0 && Count[ a[ j ] ] % 2 == 0 ) ++t;
			if( Count[ a[ j ] ] > 1 && Count[ a[ j ] ] % 2 == 1 ) --t;
			Ans[ i ][ Belong[ j ] ] = t;
		}
	}
	ans = 0;
	for( int i = 1; i <= m; ++i ) {
		int l, r;
		scanf( "%d%d", &l, &r );
		l = ( l + ans ) % n + 1;
		r = ( r + ans ) % n + 1;
		if( l > r ) std::swap( l, r );
		int L = Belong[ l ], R = Belong[ r ];
		if( L + 1 >= R ) {
			memset( Count, 0, sizeof( Count ) );
			ans = 0;
			for( int j = l; j <= r; ++j ) {
				++Count[ a[ j ] ];
				if( Count[ a[ j ] ] > 0 && Count[ a[ j ] ] % 2 == 0 ) ++ans;
				if( Count[ a[ j ] ] > 1 && Count[ a[ j ] ] % 2 == 1 ) --ans;
			}
		} else {
			memset( Count, 0, sizeof( Count ) );
			ans = Ans[ L + 1 ][ R - 1 ];
			for( int j = l; j <= L * size; ++j ) {
				++Count[ a[ j ] ];
				int tt = Count[ a[ j ] ] + Sum[ R - 1 ][ a[ j ] ] - Sum[ L ][ a[ j ] ];
				if( tt > 0 && tt % 2 == 0 ) ++ans;
				if( tt > 1 && tt % 2 == 1 ) --ans;
			}
			for( int j = ( R - 1 ) * size + 1; j <= r; ++j ) {
				++Count[ a[ j ] ];
				int tt = Count[ a[ j ] ] + Sum[ R - 1 ][ a[ j ] ] - Sum[ L ][ a[ j ] ];
				if( tt > 0 && tt % 2 == 0 ) ++ans;
				if( tt > 1 && tt % 2 == 1 ) --ans;
			}
		}
		printf( "%d\n", ans );
	}
	return 0;
}
