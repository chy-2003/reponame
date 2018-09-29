#pragma GCC diagnostic error             "-std=c++11"
#pragma GCC optimize                              (3)
#pragma GCC optimize                        ("Ofast")
#pragma GCC optimize                       ("-fgcse")
#pragma GCC optimize                       ("inline")
#pragma GCC optimize                    ("-fipa-sra")
#pragma GCC optimize                    ("-fgcse-lm")
#pragma GCC optimize                   ("-ftree-vrp")
#pragma GCC optimize                   ("-ftree-pre")
#pragma GCC optimize                  ("-fpeephole2")
#pragma GCC optimize                  ("-ffast-math")
#pragma GCC optimize                 ("-fsched-spec")
#pragma GCC optimize                 ("unroll-loops")
#pragma GCC optimize                ("-falign-loops")
#pragma GCC optimize                ("-falign-jumps")
#pragma GCC optimize               ("-funroll-loops")
#pragma GCC optimize               ("-fthread-jumps")
#pragma GCC optimize               ("-fcrossjumping")
#pragma GCC optimize               ("-fcaller-saves")
#pragma GCC optimize               ("-fdevirtualize")
#pragma GCC optimize               ("-falign-labels")
#pragma GCC optimize              ("-fwhole-program")
#pragma GCC optimize             ("inline-functions")
#pragma GCC optimize             ("-fschedule-insns")
#pragma GCC optimize             ("-freorder-blocks")
#pragma GCC optimize            ("-fcse-skip-blocks")
#pragma GCC optimize            ("-falign-functions")
#pragma GCC optimize            ("-fstrict-overflow")
#pragma GCC optimize            ("-fstrict-aliasing")
#pragma GCC optimize            ("-fschedule-insns2")
#pragma GCC optimize            ("-ftree-tail-merge")
#pragma GCC optimize           ("no-stack-protector")
#pragma GCC optimize           ("-fpartial-inlining")
#pragma GCC optimize           ("-fsched-interblock")
#pragma GCC optimize           ("-fcse-follow-jumps")
#pragma GCC optimize          ("-findirect-inlining")
#pragma GCC optimize          ("-freorder-functions")
#pragma GCC optimize       ("inline-small-functions")
#pragma GCC optimize       ("-frerun-cse-after-loop")
#pragma GCC optimize       ("-fhoist-adjacent-loads")
#pragma GCC optimize     ("-foptimize-sibling-calls")
#pragma GCC optimize     ("-ftree-switch-conversion")
#pragma GCC optimize     ("-finline-small-functions")
#pragma GCC optimize    ("-fexpensive-optimizations")
#pragma GCC optimize  ("-funsafe-loop-optimizations")
#pragma GCC optimize ("-fdelete-null-pointer-checks")
#pragma GCC optimize ("inline-functions-called-once")
#pragma GCC target                     ("avx","sse2")
#include                                        <map>
#include                                        <set>
#include                                      <cmath>
#include                                      <queue>
#include                                     <cstdio>
#include                                     <vector>
#include                                    <cstring>
#include                                   <iostream>
#include                                  <algorithm>
using namespace std;

namespace FastIn {
	inline bool Read( int &t ) {
		t = 0; int isNegtive = 1; char ch = getchar();
		while( ( ch < '0' || ch > '9' ) && ch != EOF ) { if( ch == '-' ) isNegtive = -isNegtive; ch = getchar(); }
		if( ch == EOF ) return false;
		while( ch >= '0' && ch <= '9' ) { t = ( isNegtive == 1 ) ? t * 10 - '0' + ch : t * 10 + '0' - ch ; ch = getchar(); }
		return true;
	}
	inline bool Read( unsigned int &t ) {
		t = 0; int isNegtive = 1; char ch = getchar();
		while( ( ch < '0' || ch > '9' ) && ch != EOF  ) { if( ch == '-' ) isNegtive = -isNegtive; ch = getchar(); }
		if( ch == EOF ) return false;
		while( ch >= '0' && ch <= '9' ) { t = ( isNegtive == 1 ) ? t * 10 - '0' + ch : t * 10 + '0' - ch ; ch = getchar(); }
		return true;
	}
	inline bool Read( long long &t ) {
		t = 0; int isNegtive = 1; char ch = getchar();
		while( ( ch < '0' || ch > '9' ) && ch != EOF ) { if( ch == '-' ) isNegtive = -isNegtive; ch = getchar(); }
		if( ch == EOF ) return false;
		while( ch >= '0' && ch <= '9' ) { t = ( isNegtive == 1 ) ? t * 10 - '0' + ch : t * 10 + '0' - ch ; ch = getchar(); }
		return true;
	}
	inline bool Read( unsigned long long &t ) {
		t = 0; int isNegtive = 1; char ch = getchar();
		while( ( ch < '0' || ch > '9' ) && ch != EOF ) { if( ch == '-' ) isNegtive = -isNegtive; ch = getchar(); }
		if( ch == EOF ) return false;
		while( ch >= '0' && ch <= '9' ) { t = ( isNegtive == 1 ) ? t * 10 - '0' + ch : t * 10 + '0' - ch ; ch = getchar(); }
		return true;
	}
	inline bool Read( float &t ) {
		t = 0.0; int isNegtive = 1; char ch = getchar();
		while( ( ch < '0' || ch > '9' ) && ch != EOF ) { if( ch == '-' ) isNegtive = -isNegtive; ch = getchar(); }
		if( ch == EOF ) return false;
		while( ch >= '0' && ch <= '9' ) { t = ( isNegtive == 1 ) ? t * 10 - '0' + ch : t * 10 + '0' - ch; ch = getchar(); }
		if( ch == '.' ) {
			float k = 1.0; ch = getchar();
			while( ch >= '0' && ch <= '9' ) { k *= 0.1; t += ( isNegtive == 1 ) ? k * ( ch - '0' ) : k * ( '0' - ch ); ch = getchar(); }
		}
		return true;
	}
	inline bool Read( double &t ) {
		t = 0.0; int isNegtive = 1; char ch = getchar();
		while( ( ch < '0' || ch > '9' ) && ch != EOF ) { if( ch == '-' ) isNegtive = -isNegtive; ch = getchar(); }
		if( ch == EOF ) return false;
		while( ch >= '0' && ch <= '9' ) { t = ( isNegtive == 1 ) ? t * 10 - '0' + ch : t * 10 + '0' - ch; ch = getchar(); }
		if( ch == '.' ) {
			double k = 1.0; ch = getchar();
			while( ch >= '0' && ch <= '9' ) { k *= 0.1; t += ( isNegtive == 1 ) ? k * ( ch - '0' ) : k * ( '0' - ch ); ch = getchar(); }
		}
		return true;
	}
	inline bool Read( long double &t ) {
		t = 0.0; int isNegtive = 1; char ch = getchar();
		while( ( ch < '0' || ch > '9' ) && ch != EOF ) { if( ch == '-' ) isNegtive = -isNegtive; ch = getchar(); }
		if( ch == EOF ) return false;
		while( ch >= '0' && ch <= '9' ) { t = ( isNegtive == 1 ) ? t * 10 - '0' + ch : t * 10 + '0' - ch; ch = getchar(); }
		if( ch == '.' ) {
			long double k = 1.0; ch = getchar();
			while( ch >= '0' && ch <= '9' ) { k *= 0.1; t += ( isNegtive == 1 ) ? k * ( ch - '0' ) : k * ( '0' - ch ); ch = getchar(); }
		}
		return true;
	}
} // FastIn

/*<=========================================== Head Template =============================================>*/

const double eps = 1e-8;
int W, H, D;
const int bz[ 2 ][ 4 ] = { { -1, 1, 1, -1 }, { 1, 1, -1, -1 } };
double Matrix[ 110 ][ 110 ], Ans[ 110 ];
bool Visited[ 110 ];

int main() {
	FastIn::Read( W ); FastIn::Read( H ); FastIn::Read( D );
	while( !( W == 0 && H == 0 && D == 0 ) ) {
		memset( Matrix, 0, sizeof( Matrix ) );
		for( int i = 1; i <= H; ++i )
			for( int j = 1; j <= W; ++j )
				FastIn::Read( Matrix[ ( i - 1 ) * W + j ][ W * H + 1 ] ); 
		for( int i = 1; i <= H; ++i ) 
			for( int j = 1; j <= W; ++j ) {
				int Cnt = 1;
				for( int Distance = 1; Distance <= D; ++Distance ) 
					for( int t = 1; t <= Distance; ++t ) 
						for( int k = 0; k < 4; ++k ) {
							int x, y;
							if( k % 2 == 0 ) {
								x = i + bz[ 0 ][ k ] * t;
								y = j + bz[ 1 ][ k ] * ( Distance - t );
							} else {
								x = i + bz[ 0 ][ k ] * ( Distance - t );
								y = j + bz[ 1 ][ k ] * t;
							}
							if( x > 0 && x <= H && y > 0 && y <= W ) ++Cnt;
						}
				Matrix[ ( i - 1 ) * W + j ][ ( i - 1 ) * W + j ] += 1.0 / ( 1.0 * Cnt );
				for( int Distance = 1; Distance <= D; ++Distance ) 
					for( int t = 1; t <= Distance; ++t ) 
						for( int k = 0; k < 4; ++k ) {
							int x, y;
							if( k % 2 == 0 ) {
								x = i + bz[ 0 ][ k ] * t;
								y = j + bz[ 1 ][ k ] * ( Distance - t );
							} else {
								x = i + bz[ 0 ][ k ] * ( Distance - t );
								y = j + bz[ 1 ][ k ] * t;
							}
							if( x > 0 && x <= H && y > 0 && y <= W ) Matrix[ ( i - 1 ) * W + j ][ ( x - 1 ) * W + y ] += 1.0 / ( 1.0 * Cnt );
						}
			}
		memset( Visited, false, sizeof( Visited ) );
		for( int i = 1; i <= W * H; ++i ) {
			int Id = 0;
			for( int j = 1; j <= W * H; ++j ) 
				if( !Visited[ j ] && abs( Matrix[ j ][ i ] - 0.0 ) > eps ) 
					Id = j;
			Visited[ Id ] = true;
			for( int j = 1; j <= W * H; ++j ) 
				if( j != Id ) {
					double t = Matrix[ j ][ i ] / Matrix[ Id ][ i ];
					for( int k = 1; k <= W * H + 1; ++k ) 
						Matrix[ j ][ k ] -= Matrix[ Id ][ k ] * t;
				}
		}
		memset( Ans, 0, sizeof( Ans ) );
		for( int i = 1; i <= W * H; ++i )
			for( int j = 1; j <= W * H; ++j )
				if( abs( Matrix[ i ][ j ] - 0.0 ) > eps ) {
					Ans[ j ] = Matrix[ i ][ W * H + 1 ] / Matrix[ i ][ j ];
					break;
				}
		for( int i = 1; i <= H; ++i ) {
			for( int j = 1; j <= W; ++j ) printf( "%8.2lf", Ans[ ( i - 1 ) * W + j ] + eps );
			printf( "\n" );
		}
		FastIn::Read( W ); FastIn::Read( H ); FastIn::Read( D );
		if( !( W == 0 && H == 0 && D == 0 ) ) printf( "\n" );
	}
	return 0;
}
