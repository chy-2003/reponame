#include <cstdio>
#include <cstring>
#include <algorithm>

const int INF = 2147483647;
const int MaxN = 1010, MaxB = 30;
const int MaxPointNum = MaxN + MaxB + 2, MaxEdge = ( MaxN * MaxB + MaxN + MaxB ) << 1;
int N, B, Ans;
int Map[ MaxN ][ MaxB ], Space[ MaxB ];
int UsedSpace, F[ MaxPointNum ], Link[ MaxEdge ], Next[ MaxEdge ], Value[ MaxEdge ];
int S, T;
int Cur[ MaxPointNum ], Deep[ MaxPointNum ];
int l, r, Queue[ MaxPointNum ];

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

bool BFS() {
    l = r = 0; memset( Deep, 255, sizeof( Deep ) );
    r = 1; Queue[ r ] = S; Deep[ S ] = 1;
    while( l < r ) {
        ++l;
        for( int t = F[ Queue[ l ] ]; t != -1; t = Next[ t ] ) {
            if( !Value[ t ] ) continue;
            if( Deep[ Link [ t ] ] != -1 ) continue;
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
        if( !Value[ t ] ) continue;
        if( Deep[ Link[ t ] ] != Deep[ Point ] + 1 ) continue;
        int d = DFS( Link[ t ], std::min( Flow, Value[ t ] ) );
        Ans += d; Flow -= d;
        Value[ t ] -= d; Value[ t ^ 1 ] += d;
        if( Flow == 0) break;
    }
    return Ans;
}

int Dinic() {
    int Ans = 0;
    while( BFS() ) {
        memcpy( Cur, F, sizeof( F ) );
        Ans += DFS(S, INF);
    }
    return Ans;
}

int main() {
    memset( Map, 0, sizeof( Map ) );
    memset( Space, 0, sizeof( Space ) );
    scanf( "%d%d", &N, &B);
    S = 0, T = N + B + 1;
    for( int i = 1; i <= N; ++i )
        for( int j = 1; j <= B; ++j ) 
            scanf( "%d", &Map[ i ][ j ] );
    for( int i = 1; i <= B; ++i )
        scanf( "%d", &Space[ i ] );
    Ans = INF;
    for( int L = 1; L <= B; ++L )
        for( int R = L; R <= B; ++R ) {
            clean();
            for( int i = 1; i <= N; ++i ) {
                AddEdge( S, i, 1 );
                AddEdge( i, S, 0 );
            }
            for( int i = 1; i <= B; ++i ) {
                AddEdge( i + N, T, Space[ i ] );
                AddEdge( T, i + N, 0 );
            }
            for( int i = 1; i <= N; ++i )
                for( int j = L; j <= R; ++j ) {
                    AddEdge( i, Map[ i ][ j ] + N, 1 );
                    AddEdge( Map[ i ][ j ] + N, i, 0 );
                }
            if( Dinic() == N ) Ans = std::min( Ans, R - L + 1 );
        }
    printf( "%d\n", Ans );
    return 0;
}


