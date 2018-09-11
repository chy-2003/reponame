#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int Mod = 1000007;
struct Node { 
    int Val, Count, Next;
    Node( int Val_ = 0, int Count_ = 0, int Next_ = 0 ) {
        Val = Val_; Count = Count_; Next = Next_; return;
    }
} Hash[ 5000010 ];
int f[ 1000010 ], n, x, Used, co;
struct Co {
    int x, y;
    Co( int x_ = 0, int y_ = 0 ) { x = x_; y = y_; return; }
} ff[ 5000010 ];
bool cmp( Co x, Co y ) { return x.x < y.x; }
int main() {
    scanf( "%d", &n );
    for( int i = 1; i <= n; ++i ) {
        scanf( "%d", &x );
        int b = 0;
        for( int t = f[ x % Mod ]; t; t = Hash[ t ].Next )
            if( Hash[ t ].Val == x ) {
                Hash[ t ].Count ++;
                b = 1;
                break;
            }
        if( b == 0 ) {            
            Hash[ ++Used ] = Node( x, 1, f[ x % Mod ] );
            f[ x % Mod ] = Used;
        }
    }
    for( int i = 0; i < Mod; ++i ) 
        for( int t = f[ i ]; t; t = Hash[ t ].Next ) {
            ff[ ++co ] = Co( Hash[ t ].Val, Hash[ t ].Count );
        }
    sort( ff + 1, ff + co + 1, cmp );
    for( int i = 1; i <= co; ++i ) printf( "%d %d\n", ff[ i ].x, ff[ i ].y );
    return 0;
}

