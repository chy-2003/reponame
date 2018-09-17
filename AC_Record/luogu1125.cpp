#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char ch[ 110 ];
int C[ 26 ];

int main() {
	scanf( "%s", ch );
	int l = strlen( ch );
	for( int i = 0; i < l; ++i ) C[ ch[ i ] - 'a' ]++;
	int Max = 0, Min = 110;
	for( int i = 0; i < 26; ++i ) {
		Max = max( Max, C[ i ] );
		if( C[ i ] > 0 )
		Min = min( Min, C[ i ] );
	}
	int t = Max - Min;
	int b = 1;
	if( t < 2 ) b = 0;
	for( int i = 2; i * i <= t; ++i ) 
		if( t % i == 0 ) {
			b = 0;
			break;
		}
	if( b ) printf( "Lucky Word\n%d\n", t ); else printf( "No Answer\n0\n" );
	return 0;
}
