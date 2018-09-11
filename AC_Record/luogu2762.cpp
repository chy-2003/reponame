#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>

const int INF = 2147483647;
const int Maxn = 1000, Maxm = 1000, MaxPointNum = Maxn + Maxm + 2, MaxEdgeNum = Maxn * Maxm + Maxn + Maxm;
int n, m, S, T, Total;
int UsedSpace, F[ MaxPointNum ], Link[ MaxEdgeNum ], Next[ MaxEdgeNum ], Value[ MaxEdgeNum ];
int Cur[ MaxPointNum ], Deep[ MaxPointNum ];
int Skip[ MaxPointNum ];
int mChosen[ Maxm ], nChosen[ Maxn ];
int nValues[ Maxn ], Operations[ Maxm ][ Maxn ], mValues[ Maxm ];
int ValueSwp[ MaxEdgeNum ];
int l, r, Queue[ MaxPointNum ];
std::string s;
std::stringstream StringStream;

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

void init() {
    memset( nValues, 0, sizeof( nValues ) );
    memset( Operations, 0, sizeof( Operations ) );
    memset( mValues, 0, sizeof( mValues ) );
    StringStream.clear();
    std::getline( std::cin, s );
    StringStream << s;
    StringStream >> m >> n;
    S = 0; T = n + m + 1;
    for( int i = 1; i <= m; ++i ) {
        StringStream.clear();
        std::getline( std::cin, s);
        StringStream << s;
        int x;
        StringStream >> x;
        mValues[ i ] = x;
        while(StringStream >> x) Operations[ i ][ ++Operations[ i ][ 0 ] ] = x;
    }
    StringStream.clear();
    std::getline( std::cin, s);
    StringStream << s;
    for( int i = 1; i <= n; ++i ) StringStream >> nValues[ i ];
    
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
            if( Skip[ Queue[ l ] ] && Link[ t ] == T || Queue[ l ] == T && Skip[ Link[ t ] ] ) continue;
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
        if( Skip[ Point ] && Link[ t ] == T || Point == T && Skip[ Link[ t ] ] ) continue;
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
    memset( Skip, 0, sizeof( Skip ) );
    memset( nChosen, 0, sizeof( nChosen ) );
    memset( mChosen, 0, sizeof( mChosen ) );
    int Ans = Dinic();
    for( int i = 1; i <= n; ++i ) {
        Skip[ i + m ] = 1;
        int t = Dinic();
        if( Ans - t == nValues[ i ] ) nChosen[ i ] = 1;
        Skip[ i + m ] = 0;
    }
    for( int i = 1; i <= m; ++i ) {
        int t = 1;
        for( int j = 1; j <= Operations[ i ][ 0 ]; ++j )
            if( !nChosen[ Operations[ i ][ j ] ] ) {
                t = 0;
                break;
            }
        if( t ) mChosen[ i ] = 1;
    }
    
    for( int i = 1; i <= m; ++i ) 
        if( mChosen[ i ] )
            printf( "%d ", i );
    printf( "\n" );
    for( int i = 1; i <= n; ++i )
        if( nChosen[ i ] )
            printf( "%d ", i );
    printf( "\n" );
    printf( "%d\n", Total - Ans );
    return;
}

int main() {
    clean();
    init();
    Work();
    return 0;
}

