#include <cstdio>
#include <cstring>
#include <algorithm>

const int MaxN = 310;
struct edge {
    int Link, Value, Next;
    edge( int Link_ = 0, int Value_ = 0, int Next_ = 0 ) {
        Link = Link_; Value = Value_; Next = Next_; return;
    }
};
edge Edge[ MaxN << 1 ];
int Used, F[ MaxN ];
int N, M, K;
int Dp[ MaxN ][ MaxN ][ 2 ];
int cpy[ MaxN ][ 2 ];

inline void AddEdge( int From, int To, int Val ) {
    Edge[ ++Used ] = edge( To, Val, F[ From ] );
    F[ From ] = Used;
    return;
}

void Clean() {
    memset( Edge, 0, sizeof( Edge ) );
    memset( F, 0, sizeof( F ) );
    memset( Dp, 255, sizeof( Dp ) );
    Used = 0;
    return;
}

void DP1( int Point, int Father ) {
    Dp[ Point ][ 0 ][ 0 ] = 0;
    Dp[ Point ][ 1 ][ 1 ] = 0;
    for( int t = F[ Point ]; t; t = Edge[ t ].Next ) {
        if( Edge[ t ].Link == Father ) continue;
        DP1( Edge[ t ].Link, Point );
        memset( cpy, 255, sizeof( cpy ) );
        for( int i = 0; i <= N; ++i ) 
            for( int j = 0; j <= N; ++j ) {
                if( i + j > N ) continue;

                if( Dp[ Point ][ i ][ 0 ] != -1 && Dp[ Edge[ t ].Link ][ j ][ 0 ] != -1 ) 
                    if( cpy[ i + j ][ 0 ] == -1 || cpy[ i + j ][ 0 ] > Dp[ Point ][ i ][ 0 ] + Dp[ Edge[ t ].Link ][ j ][ 0 ] + Edge[ t ].Value )
                        cpy[ i + j ][ 0 ] = Dp[ Point ][ i ][ 0 ] + Dp[ Edge[ t ].Link ][ j ][ 0 ] + Edge[ t ].Value;

                if( Dp[ Point ][ i ][ 0 ] != -1 && Dp[ Edge[ t ].Link ][ j ][ 1 ] != -1 ) 
                    if( cpy[ i + j ][ 0 ] == -1 || cpy[ i + j ][ 0 ] > Dp[ Point ][ i ][ 0 ] + Dp[ Edge[ t ].Link ][ j ][ 1 ] )
                        cpy[ i + j ][ 0 ] = Dp[ Point ][ i ][ 0 ] + Dp[ Edge[ t ].Link ][ j ][ 1 ];

                if( Dp[ Point ][ i ][ 1 ] != -1 && Dp[ Edge[ t ].Link ][ j ][ 0 ] != -1 )
                    if( cpy[ i + j ][ 1 ] == -1 || cpy[ i + j ][ 1 ] > Dp[ Point ][ i ][ 1 ] + Dp[ Edge[ t ].Link ][ j ][ 0 ] )
                        cpy[ i + j ][ 1 ] = Dp[ Point ][ i ][ 1 ] + Dp[ Edge[ t ].Link ][ j ][ 0 ];

                if( Dp[ Point ][ i ][ 1 ] != -1 && Dp[ Edge[ t ].Link ][ j ][ 1 ] != -1 )
                    if( cpy[ i + j ][ 1 ] == -1 || cpy[ i + j ][ 1 ] > Dp[ Point ][ i ][ 1 ] + Dp[ Edge[ t ].Link ][ j ][ 1 ] + Edge[ t ].Value )
                        cpy[ i + j ][ 1 ] = Dp[ Point ][ i ][ 1 ] + Dp[ Edge[ t ].Link ][ j ][ 1 ] + Edge[ t ].Value;
            }
        for( int i = 0; i <= N; ++i ) {
            Dp[ Point ][ i ][ 0 ] = cpy[ i ][ 0 ];
            Dp[ Point ][ i ][ 1 ] = cpy[ i ][ 1 ];
        }
    }
    return;
}

void DP2( int Point, int Father ) {
    Dp[ Point ][ 0 ][ 0 ] = 0;
    Dp[ Point ][ 1 ][ 1 ] = 0;
    for( int t = F[ Point ]; t; t = Edge[ t ].Next ) {
        if( Edge[ t ].Link == Father ) continue;
        DP2( Edge[ t ].Link, Point );
        memset( cpy, 255, sizeof( cpy ) );
        for( int i = 0; i <= N; ++i ) 
            for( int j = 0; j <= N; ++j ) {
                if( i + j > N ) continue;
                if( Dp[ Point ][ i ][ 0 ] != -1 && Dp[ Edge[ t ].Link ][ j ][ 0 ] != -1 ) 
                    if( cpy[ i + j ][ 0 ] == -1 || cpy[ i + j ][ 0 ] > Dp[ Point ][ i ][ 0 ] + Dp[ Edge[ t ].Link ][ j ][ 0 ] )
                        cpy[ i + j ][ 0 ] = Dp[ Point ][ i ][ 0 ] + Dp[ Edge[ t ].Link ][ j ][ 0 ];
                if( Dp[ Point ][ i ][ 0 ] != -1 && Dp[ Edge[ t ].Link ][ j ][ 1 ] != -1 ) 
                    if( cpy[ i + j ][ 0 ] == -1 || cpy[ i + j ][ 0 ] > Dp[ Point ][ i ][ 0 ] + Dp[ Edge[ t ].Link ][ j ][ 1 ] )
                        cpy[ i + j ][ 0 ] = Dp[ Point ][ i ][ 0 ] + Dp[ Edge[ t ].Link ][ j ][ 1 ];
                if( Dp[ Point ][ i ][ 1 ] != -1 && Dp[ Edge[ t ].Link ][ j ][ 0 ] != -1 )
                    if( cpy[ i + j ][ 1 ] == -1 || cpy[ i + j ][ 1 ] > Dp[ Point ][ i ][ 1 ] + Dp[ Edge[ t ].Link ][ j ][ 0 ] )
                        cpy[ i + j ][ 1 ] = Dp[ Point ][ i ][ 1 ] + Dp[ Edge[ t ].Link ][ j ][ 0 ];
                if( Dp[ Point ][ i ][ 1 ] != -1 && Dp[ Edge[ t ].Link ][ j ][ 1 ] != -1 )
                    if( cpy[ i + j ][ 1 ] == -1 || cpy[ i + j ][ 1 ] > Dp[ Point ][ i ][ 1 ] + Dp[ Edge[ t ].Link ][ j ][ 1 ] + Edge[ t ].Value )
                        cpy[ i + j ][ 1 ] = Dp[ Point ][ i ][ 1 ] + Dp[ Edge[ t ].Link ][ j ][ 1 ] + Edge[ t ].Value;
            }
        for( int i = 0; i <= N; ++i ) {
            Dp[ Point ][ i ][ 0 ] = cpy[ i ][ 0 ];
            Dp[ Point ][ i ][ 1 ] = cpy[ i ][ 1 ];
        }
    }
    return;
}

int main() {
    Clean();
    scanf( "%d%d%d", &N, &M, &K );
    if( N - K < M - 1 ) {
        printf( "-1\n" );
        return 0;
    }
    for( int i = 1; i < N; ++i ) {
        int a, b, c;
        scanf( "%d%d%d", &a, &b, &c );
        AddEdge( a, b, c );
        AddEdge( b, a, c );
    }
    if( M == 2 ) DP1( 1, 1 ); else DP2( 1, 1 );
    printf( "%d\n", Dp[ 1 ][ K ][ 1 ] );
    return 0;
}

