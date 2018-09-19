#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

string pre = "pre", in = "in", post = "post";
string ch[ 6 ];
int n, a[ 60 ][ 3 ];

int tx1( int x, int y, int len, int t, string s ) {
	if( s == pre  && t == 1 ) return x + 1;
	if( s == pre  && t == 2 ) return x + len + 1;
	if( s == in   && t == 1 ) return x;
	if( s == in   && t == 2 ) return x + len + 1;
	if( s == post && t == 1 ) return x;
	if( s == post && t == 2 ) return x + len;
}

int tx2( int x, int y, int len, int t, string s ) {
	if( s == pre  && t == 1 ) return x + len;
	if( s == pre  && t == 2 ) return y;
	if( s == in   && t == 1 ) return x + len - 1;
	if( s == in   && t == 2 ) return y;
	if( s == post && t == 1 ) return x + len - 1;
	if( s == post && t == 2 ) return y - 1;
}

string ty( int t, string s ) {
	if( s == pre  && t == 1 ) return ch[ 0 ];
	if( s == pre  && t == 2 ) return ch[ 1 ];
	if( s == in   && t == 1 ) return ch[ 2 ];
	if( s == in   && t == 2 ) return ch[ 3 ];
	if( s == post && t == 1 ) return ch[ 4 ];
	if( s == post && t == 2 ) return ch[ 5 ];
}

bool check( int la, int ra, string sa, int lb, int rb, string sb, int lc, int rc, string sc ) {
//	cout << la << " " << ra << " " << sa << endl;
//	cout << lb << " " << rb << " " << sb << endl;
//	cout << lc << " " << rc << " " << sc << endl;
	int pr, im, po;
	int b[ 3 ][ 2 ];
	b[ 0 ][ 0 ] = la; b[ 0 ][ 1 ] = ra; 
	b[ 1 ][ 0 ] = lb; b[ 1 ][ 1 ] = rb; 
	b[ 2 ][ 0 ] = lc; b[ 2 ][ 1 ] = rc;
	if( sa == pre  ) pr = 0; if( sb == pre  ) pr = 1; if( sc == pre  ) pr = 2;
	if( sa == in   ) im = 0; if( sb == in   ) im = 1; if( sc == in   ) im = 2;
	if( sa == post ) po = 0; if( sb == post ) po = 1; if( sc == post ) po = 2;
//	cout << pr << " " << im << " " << po << endl;
	if( a[ b[ pr ][ 0 ] ][ pr ] != a[ b[ po ][ 1 ] ][ po ] ) return false;
//	printf( "*\n" );
	int t = 0, rec = 0;
	for( int i = b[ im ][ 0 ]; i <= b[ im ][ 1 ]; ++i ) 
		if( a[ i ][ im ] == a[ b[ pr ][ 0 ] ][ pr ] ) {
			t = 1; rec = i;
			break;
		}
	if( t == 0 ) return false;
//	printf( "*\n" );
	int len = rec - b[ im ][ 0 ];
//	printf( "len = %d\n", len );
	bool t1, t2;
	if( len > 0 )
		t1 = check( tx1( la, ra, len, 1, sa ), tx2( la, ra, len, 1, sa ), ty( 1, sa ), 
					tx1( lb, rb, len, 1, sb ), tx2( lb, rb, len, 1, sb ), ty( 1, sb ), 
					tx1( lc, rc, len, 1, sc ), tx2( lc, rc, len, 1, sc ), ty( 1, sc ) ); 
	else t1 = true;
	if( len < ra - la )
		t2 = check( tx1( la, ra, len, 2, sa ), tx2( la, ra, len, 2, sa ), ty( 2, sa ), 
					tx1( lb, rb, len, 2, sb ), tx2( lb, rb, len, 2, sb ), ty( 2, sb ), 
					tx1( lc, rc, len, 2, sc ), tx2( lc, rc, len, 2, sc ), ty( 2, sc ) );
	else t2 = true;
	if( t1 && t2 ) return true; else return false;
}

int main() {
	for( int i = 0; i < 6; ++i ) cin >> ch[ i ];
	scanf( "%d", &n );
	for( int t = 0; t < 3; ++t )
		for( int i = 1; i <= n; ++i ) scanf( "%d", &a[ i ][ t ] );
	if( check( 1, n, pre, 1, n, in, 1, n, post ) ) printf( "Possible\n" ); else printf( "Impossible\n" );
	return 0;
}
