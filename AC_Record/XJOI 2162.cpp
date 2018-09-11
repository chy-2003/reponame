#include <cstdio>
#include <cstring>
#include <algorithm>

const int INF = 2147483647;
const int Maxn = 20, Maxm = 30, MaxEdgeNum = 60010, MaxPointNum = 60010;
int n, m, k;

struct boat {
    int Hpi, r, a[ Maxn ];
};
boat Boat[ Maxm ];

void ReadBoat( int Num ) {
    Boat[ Num ].Hpi = 0;
    Boat[ Num ].r = 0;
    memset( Boat[ Num ].a, 0, sizeof( Boat[ Num ].a ) );
    scanf( "%d%d", &Boat[ Num ].Hpi, &Boat[ Num ].r );
    for( int i = 0; i < Boat[ Num ].r; ++i ) 
        scanf( "%d", &Boat[ Num ].a[ i ] );
    return;
}

int UsedEdgeNum;
struct edge {
    int Link, Value, Next;
    edge( int Link_ = 0, int Value_ = 0, int Next_ = 0 ) {
        Link = Link_; Value = Value_; Next = Next_;
        return;
    }
};
edge Edge[ MaxEdgeNum ];
int F[ MaxPointNum ];

int S, T, Deep[ MaxPointNum ], Cur[ MaxPointNum ];
int l, r, Queue[ MaxPointNum ];

inline void Clean() {
    UsedEdgeNum = 0;
    memset( Edge, 0, sizeof( Edge ) );
    S = T = 0;
    memset( Deep, 0, sizeof( Deep ) );
    memset( Cur, 0, sizeof( Cur ) );
    memset( F, 255, sizeof( F ) );
    return;
}

inline void AddEdge( int From, int To, int Val ) {
    Edge[ UsedEdgeNum ] = edge( To, Val, F[ From ] );
    F[ From ] = UsedEdgeNum;
    ++UsedEdgeNum;
    return;
}

inline void AddDoubleEdge( int From, int To, int Val ) {
    AddEdge( From, To, Val );
    AddEdge( To, From, 0 );
    return;
}

//Everyday, add n + 2 points. For The ith day, IP is from ( i - 1 ) * ( n + 2 ) + 2 ~ i * ( n + 2 ) + 1. 0 is for S, 1 is for T. Each day, 0 is for earth, n + 1 is for moon. 
void AddDayPoint( int Day ) {
    ++Day;
    int Start = ( Day - 1 ) * ( n + 2 ) + 2;
    AddDoubleEdge( S, Start + 0, INF );
    AddDoubleEdge( Start + n + 1, T, INF );
    if( Day == 1 ) return;
    for( int i = 1; i <= n; ++i ) 
        AddDoubleEdge( Start + i - ( n + 2 ), Start + i, INF );
    for( int i = 1; i <= m; ++i ) {
        int Yesterday = Boat[ i ].a[ ( Day - 2 ) % Boat[ i ].r ];
        int Today = Boat[ i ].a[ ( Day - 1 ) % Boat[ i ].r ];
        if( Yesterday == -1 ) Yesterday = n + 1;
        if( Today == -1) Today = n + 1;
        AddDoubleEdge( Start + Yesterday - ( n + 2 ), Start + Today, Boat[ i ].Hpi );
    }
    return;
}

bool Bfs() {
    l = 0; r = 1; Queue[1] = S;
    memset( Deep, 255, sizeof( Deep ) );
    Deep[ S ] = 1;
    while( l < r ) {
        ++l;
        for( int t = F[ Queue[ l ] ]; t != -1; t = Edge[ t ].Next ) {
            if( !Edge[ t ].Value ) continue;
            if( Deep[ Edge[ t ].Link ] != -1 ) continue;
            Deep[ Edge[ t ].Link ] = Deep[ Queue[ l ] ] + 1;
            Queue[ ++r ] = Edge[ t ].Link;
        }
    }
    if( Deep[ T ] == -1 ) return false; else return true;
}

int Dfs( int Point, int Flow ) {
    if( Point == T || Flow <= 0 ) return Flow;
    int Ans = 0;
    for( int & t = Cur[ Point ]; t != -1; t = Edge[ t ].Next ) {
        if( !Edge[ t ].Value ) continue;
        if( Deep[ Edge[ t ].Link ] != Deep[ Point ] + 1 ) continue;
        int d = Dfs( Edge[ t ].Link, std::min( Flow, Edge[ t ].Value ) );
        Flow -= d; Ans += d;
        Edge[ t ].Value -= d; Edge[ t ^ 1 ].Value += d;
        if( Flow <= 0 ) break;
    }
    return Ans;
}

int Dinic() {
    int Ans = 0;
    while( Bfs() ) {
        memcpy( Cur, F, sizeof( F ) );
        Ans += Dfs( S, INF );
    }
    return Ans;
}

int main() {
    scanf( "%d%d%d", &n, &m, &k );
    if( k == 0 ) {
        printf( "0\n" );
        return 0;
    }
    for( int i = 1; i <= m; ++i ) ReadBoat( i );
    Clean();
    S = 0; T = 1;
    AddDayPoint( 0 );

    int Sigma = 0;
    for( int Day = 1; Day <= 1000; ++Day ) {
        AddDayPoint( Day );
        Sigma += Dinic();
        if( Sigma >= k ) {
            printf( "%d\n", Day );
            return 0;
        }
    }
    printf( "0\n" );
    return 0;
}

