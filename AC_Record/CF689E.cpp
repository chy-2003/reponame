#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const long long Mod = 1000000007;
const long long Maxn = 200010;
map< long long, long long > Map;
long long n, k, a[ Maxn ], b[ Maxn ];
long long cnt, Rec[ Maxn << 1 ];
long long Count[ Maxn << 1 ];


long long Fact[ Maxn ], INV[ Maxn ];

void exgcd( long long a, long long b, long long &x, long long &y ) {
	if( b == 0 ) {
		x = 1; y = 0; return;
	}
	exgcd( b, a % b, y, x );
	y -= x * ( a / b );
	return;
}

long long inv( long long a, long long b ) {
	long long x, y;
	exgcd( a, b, x, y );
	if( x < 0 ) x += b;
	return x;
}

void init() {
	Fact[ 0 ] = 1;
	for( long long i = 1; i <= n; ++i ) Fact[ i ] = Fact[ i - 1 ] * i % Mod;
	INV[ n ] = inv( Fact[ n ], Mod );
	for( long long i = n - 1; i >= 0; --i ) INV[ i ] = INV[ i + 1 ] * ( i + 1 ) % Mod;
	return;
}

long long C( long long n, long long m ) {
	if( n < m ) return 0LL;
	return Fact[ n ] * INV[ m ] % Mod * INV[ n - m ] % Mod;
}


int main() {
	scanf( "%I64d%I64d", &n, &k );
	init();
	for( long long i = 1; i <= n; ++i ) scanf( "%I64d%I64d", &a[ i ], &b[ i ] );
	Map.clear();
	for( long long i = 1; i <= n; ++i ) {
		Map[ a[ i ] ] = 1;
		Map[ b[ i ] + 1 ] = 1;
	}
	cnt = 0LL;
	for( map< long long, long long >::iterator it = Map.begin(); it != Map.end(); ++it ) {
		Map[ ( *it ).first ] = ++cnt;
		Rec[ cnt ] = ( *it ).first;
	}
	
	for( long long i = 1; i <= n; ++i ) {
		Count[ Map[ a[ i ] ] ]++;
		Count[ Map[ b[ i ] + 1 ] ]--;
	}
	for( long long i = 1; i <= cnt; ++i ) Count[ i ] += Count[ i - 1 ];
	
	long long ans = 0;
	for( long long i = 1; i < cnt; ++i )
		ans = ( ans + ( Rec[ i + 1 ] - Rec[ i ] ) * C( Count[ i ], k ) % Mod ) % Mod;
	printf( "%I64d\n", ans );
	return 0;
}
