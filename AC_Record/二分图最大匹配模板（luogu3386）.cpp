#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1010, Maxe = 1000010;
int n, m, e;
vector< int > X[ Maxn ], Y[ Maxn ];
bool Visy[ Maxn ];
int mx[ Maxn ], my[ Maxn ];

bool Dfs( int x ) {
    for( vector< int >::iterator it = X[ x ].begin(); it != X[ x ].end(); ++it ) {
        if( Visy[ ( *it ) ] ) continue;
        Visy[ ( *it ) ] = true;
        if( my[ ( *it ) ] == -1 || Dfs( my[ ( *it ) ] ) ) {
            mx[ x ] = ( *it );
            my[ ( *it ) ] = x;
            return true;
        }
    }
    return false;
}

int main() {
    scanf( "%d%d%d", &n, &m, &e );
    for( int i = 1; i <= e; ++i ) {
        int x, y; scanf( "%d%d", &x, &y );
        if( y > m ) continue;
        X[ x ].push_back( y ); 
        Y[ y ].push_back( x );
    }
    int Ans = 0;
    memset( mx, 255, sizeof( mx ) );
    memset( my, 255, sizeof( my ) );
    for( int i = 1; i <= n; ++i ) {
        memset( Visy, false, sizeof( Visy ) );
        if( Dfs( i ) ) 
            Ans++;
    }
    printf( "%d\n", Ans );
    return 0;
}
