#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

const LL Mod = 1e9 + 7;
LL n, ans;
LL Rec[ 40010 ];
LL num, a[ 110 ];

LL gcd( LL x, LL y ) {
	LL m = x % y;
	while( m ) {
		x = y; y = m; m = x % y;
	}
	return y;
}

int main() {
	scanf( "%lld", &n );
	ans = n * n % Mod;
	ans = ( ans + n * ( n - 1 ) % Mod ) % Mod;
	for( int i = 2; i * i <= n; ++i ) {
		if( Rec[ i ] ) continue;
		num = 1; a[ 1 ] = i;
		Rec[ i ] = 1;
		while( a[ num ] * i <= n ) {
			a[ num + 1 ] = a[ num ] * i; ++num;
			if( a[ num ] * a[ num ] <= n ) 
				Rec[ a[ num ] ] = 1;
		}
		for( int j = 1; j <= num; ++j ) 
			for( int k = 1; k <= num; ++k ) {
				if( j == k ) continue;
				LL t = gcd( j, k );
				ans = ( ans + n / max( j / t, k / t ) ) % Mod;
			}
	}
	printf( "%lld\n", ans );
	return 0;
}
