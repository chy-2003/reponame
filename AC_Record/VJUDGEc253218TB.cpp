#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map< long long, long long > Map[2];
vector< long long > Vc1;
vector< long long > Vc2;
long long n;
long long a[ 40 ];

long long Abs( long long x ) {
    return ( x < 0 ) ? -x : x;
}

void Dfs( long long from, long long to, long long s, long long id, long long count ) {
    if( from > to ) {
        if( count > 0 ) 
        if( Map[ id ].find( s ) == Map[ id ].end() ) Map[ id ][ s ] = count; else Map[ id ][ s ] = min( Map[ id ][ s ], count );
        return;
    }
    Dfs( from + 1, to, s + a[ from ], id, count + 1 );
    Dfs( from + 1, to, s, id, count );
    return;
}

long long ans;
long long num;

void Updata( long long t, long long first, long long second ) {
    if( Abs( Vc1[ t ] + first ) < ans ) {
        ans = Abs( Vc1[ t ] + first );
        num = Vc2[ t ] + second;
    } else 
        if( Abs( Vc1[ t ] + first ) == ans && Vc2[ t ] + second < num ) {
            num = Vc2[ t ] + second;
        }
    return;
}

void work() {
    Map[ 0 ].clear(); Map[ 1 ].clear();
    for( long long i = 1; i <= n; ++i ) scanf( "%lld", &a[ i ] );
    if( n == 1 ) {
        printf( "%lld %lld\n", Abs( a[ 1 ] ), 1LL );
        return;
    }
    Dfs( 1, n / 2, 0, 0, 0 );
    Dfs( n / 2 + 1, n, 0, 1, 0 );
    Vc1.clear(); Vc2.clear();
    for( map< long long, long long >::iterator it = Map[ 0 ].begin(); it != Map[ 0 ].end(); ++it ) {
        Vc1.push_back( ( *it ).first );
        Vc2.push_back( ( *it ).second );
    }
    ans = 1e18;
    for( map< long long, long long >::iterator it = Map[ 0 ].begin(); it != Map[ 0 ].end(); ++it ) 
        if( Abs( ( *it ).first ) < ans || Abs( ( *it ).first ) == ans && ( *it ).second < num ) {
            ans = Abs( ( *it ).first );
            num = ( *it ).second;
        }
    for( map< long long, long long >::iterator it = Map[ 1 ].begin(); it != Map[ 1 ].end(); ++it ) 
        if( Abs( ( *it ).first ) < ans || Abs( ( *it ).first ) == ans && ( *it ).second < num ) {
            ans = Abs( ( *it ).first );
            num = ( *it ).second;
        }
    long long l = Vc1.size();
    for( map< long long, long long >::iterator it = Map[ 1 ].begin(); it != Map[ 1 ].end(); ++it ) {
        long long t = lower_bound( Vc1.begin(), Vc1.end(), -( *it ).first ) - Vc1.begin();
        if( t == 0 ) Updata( t, ( *it ).first, ( *it ).second ); 
        if( t == l ) Updata( t - 1, ( *it ).first, ( *it ).second );
        if( t > 0 && t < l ) {
            Updata( t, ( *it ).first, ( *it ).second );
            Updata( t - 1, ( *it ).first, ( *it ).second );
        }
    }
    printf( "%lld %lld\n", ans, num );
    return;
}

int main() {
    scanf( "%lld", &n );
    while( n ) {
        work();
        scanf( "%lld", &n );
    }
    return 0;
}

