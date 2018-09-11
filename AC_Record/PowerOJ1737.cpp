#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

const int INF = 2147483647;
const int Maxn = 100, Maxm = 100, MaxPointNum = Maxn + Maxm + 2, MaxEdgeNum = Maxn * Maxm + Maxn + Maxm;
int n, m, S, T, Total;
int UsedSpace, F[ MaxPointNum ], Link[ MaxEdgeNum ], Next[ MaxEdgeNum ], Value[ MaxEdgeNum ];
int Cur[ MaxPointNum ], Deep[ MaxPointNum ];
int Skip;
int mChosen[ Maxm ], nChosen[ Maxn ];
int nValues[ Maxn ], Operations[ Maxm ][ Maxn ], mValues[ Maxm ];
int ValueSwp[ MaxEdgeNum ];
int l, r, Queue[ MaxPointNum ];
char s[ 510 ];

void clean() {
    UsedSpace = 0;
    memset( F, 255, sizeof( F ) );
    memset( Link, 0, sizeof( Link ) );
    memset( Next, 0, sizeof( Next ) );
    memset( Value, 0, sizeof( Value ) );
    return;
}

inline void AddEdge( int From, int To, int Val ) {
    Link[ UsedSpace ] = To;
    Next[ UsedSpace ] = F[ From ];
    Value[ UsedSpace ] = Val;
    F[ From ] = UsedSpace;
    ++UsedSpace;
    return;
}

inline bool IsDigit( char ch ) {
    if( ch >= '0' && ch <= '9' ) return true;
    return false;
}

void init() {
    memset( nValues, 0, sizeof( nValues ) );
    memset( Operations, 0, sizeof( Operations ) );
    memset( mValues, 0, sizeof( mValues ) );
    scanf( "%d%d", &m, &n );
    S = 0; T = n + m + 1;
    for( int i = 1; i <= m; ++i ) {
        scanf( "%d", &mValues[i] );
        std::gets( s );
        int Len = strlen( s );
        for( int j = 0; j < Len; ) {
            while( j < Len && ! IsDigit( s[ j ] ) ) ++j;
            if( j >= Len ) break;
            int v = 0;
            while( j < Len && IsDigit( s[ j ] ) ) {
                v = v * 10 + s[ j ] - '0';
                ++j;
            }
            Operations[ i ][ ++Operations[ i ][ 0 ] ] = v;
        }
    }
    for( int i = 1; i <= n; ++i ) scanf( "%d", &nValues[ i ] );
    
    for( int i = 1; i <= m; ++i ) {
        AddEdge( S, i, mValues[ i ] );
        AddEdge( i, S, 0 );
    }
    for( int i = 1; i <= m; ++i ) 
        for(int j = 1; j <= Operations[ i ][ 0 ]; ++j) {
            AddEdge( i, m + Operations[ i ][ j ], INF );
            AddEdge( m + Operations[ i ][ j ], i, 0 );
        }
    for( int i = 1; i <= n; ++i ) {
        AddEdge( i + m, T, nValues[i] );
        AddEdge( T, i + m, 0 );
    }
    Total = 0;
    for( int i = 1; i <= m; i++ ) Total += mValues[i];
    memset( ValueSwp, 0, sizeof( ValueSwp ) );
    memcpy( ValueSwp, Value, sizeof( Value ) );
    return;
}

bool BFS() {
    l = r = 0; memset( Queue, 0, sizeof( Queue ) );
    memset( Deep, 255, sizeof( Deep ) );
    
    r = 1; Queue[ r ] = S;
    Deep[ S ] = 1;
    while( l < r ) {
        ++l;
        for( int t = F[ Queue[ l ] ]; t != -1; t = Next[ t ] ) {
            if( Queue[ l ] == Skip && Link[ t ] == T || Queue[ l ] == T && Link[ t ] == Skip ) continue;
            if( Value[ t ] == 0 ) continue;
            if( Deep[ Link[ t ] ] != -1 ) continue;
            Deep[ Link[ t ] ] = Deep[ Queue[ l ] ] + 1;
            Queue[ ++r ] = Link[ t ];
        }
    }
    if( Deep[ T ] == -1 ) return false; else return true;
}

int DFS( int Point, int Flow ) {
    if( Point == T || Flow == 0 ) return Flow;
    int Ans = 0;
    for( int & t = Cur[ Point ]; t != -1; t = Next[ t ] ) {
        if( Point == Skip && Link[ t ] == T || Point == T && Link[ t ] == Skip ) continue;
        if( !Value[ t ] ) continue;
        if( Deep[ Link[ t ] ] != Deep[ Point ] + 1 ) continue;
        int d = DFS( Link[ t ], std::min( Flow, Value[ t ] ) );
        Value[ t ] -= d;
        Value[ t ^ 1 ] += d;
        Flow -= d; Ans += d;
        if( Flow == 0 ) break;
    }
    return Ans;
}

int Dinic() {
    memset( Value, 0, sizeof( Value ) );
    memcpy( Value, ValueSwp, sizeof( ValueSwp ) );
    int Ans = 0;
    while( BFS() ) {
        memcpy( Cur, F, sizeof( F ) );
        Ans += DFS( S, INF );
    }
    return Ans;
}

void Work() {
    memset( nChosen, 0, sizeof( nChosen ) );
    memset( mChosen, 0, sizeof( mChosen ) );
    int Ans = Dinic();
    for( int i = 1; i <= n; ++i ) {
        Skip = i + m;
        int t = Dinic();
        if( Ans - t == nValues[ i ] ) nChosen[ i ] = 1;
    }
    for( int i = 1; i <= m; ++i ) {
        mChosen[ i ] = 1;
        for( int j = 1; j <= Operations[ i ][ 0 ]; ++j )
            if( !nChosen[ Operations[ i ][ j ] ] ) {
                mChosen[ i ] = 0;
                break;
            }
    }
    
    for( int i = 1; i <= m;++i ) 
        if( mChosen[ i ] )
            printf( "%d ", i );
    puts( "" );
    for( int i = 1; i <= n; ++i )
        if( nChosen[ i ] )
            printf( "%d ", i );
    printf( "\n%d", Total - Ans );
    return;
}

int main() {
    clean();
    init();
    Work();
    return 0;
}

