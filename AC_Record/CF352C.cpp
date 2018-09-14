#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 2010;
double a[ Maxn << 1 ];
int n, t;
double sum, ans;

int main() {
	scanf( "%d", &n );
	for( int i = 1; i <= n * 2; ++i ) scanf( "%lf", &a[ i ] );
	for( int i = 1; i <= n * 2; ++i ) 
		if( a[ i ] - floor( a[ i ] ) <= 1e-18 ) t++;
	for( int i = 1; i <= n * 2; ++i ) sum += a[ i ] - floor( a[ i ] );
	ans = 1e9;
	for( int i = max( 0, t - n ); i <= min( n, t ); ++i ) 
		ans = min( ans, abs( sum - n + i ) );
	printf( "%.3lf\n", ans );
	return 0;
}
