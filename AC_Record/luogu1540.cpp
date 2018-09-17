#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int m, n;
int l, r, q[ 1010 ], inq[ 1010 ];

int main() {
	scanf( "%d%d", &m, &n );
	int ans = 0;
	for( int i = 1; i <= n; ++i ) {
		int t; scanf( "%d", &t );
		if( !inq[ t ] ) {
			if( r - l < m ) {
				q[ ++r ] = t;
				inq[ t ] = 1;
			} else {
				inq[ q[ ++l ] ] = 0;
				q[ ++r ] = t;
				inq[ t ] = 1;
			}
			++ans;
		}
	}
	printf( "%d\n", ans );
	return 0;
}
