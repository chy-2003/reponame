#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const long long Mod = 1000000007, MaxN = 100010;
long long n, Fact[ MaxN ], ans, INV[ MaxN ];

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

long long C( long long n, long long m ) {
	return Fact[ n ] * INV[ n - m ] % Mod * INV[ m ] % Mod;
}

int main() {
	Fact[ 0 ] = 1;
	scanf( "%lld", &n );
	for( long long i = 1; i <= n; ++i ) Fact[ i ] = Fact[ i - 1 ] * i % Mod;
	INV[ n ] = inv( Fact[ n ], Mod );
	for( long long i = n - 1; i >= 0; --i ) INV[ i ] = INV[ i + 1 ] * ( i + 1 ) % Mod;
	ans = 0;
	for( int i = 1; i <= n; ++i ) ans = (ans + C( n, i ) * C( n - 1, i - 1 ) % Mod ) % Mod;
	ans = ans * 2 % Mod;
	ans -= n;
	ans = ( ( ans % Mod ) + Mod ) % Mod;
	printf( "%lld\n", ans );
	return 0;
}
