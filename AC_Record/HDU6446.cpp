#include <cstdio>
#include <cstring>
#include <algorithm>

const long long Mod = 1000000007;
const long long Maxn = 100010;
struct edge {
    long long To, Length, Next;
    edge( long long To_ = 0, long long Length_ = 0, long long Next_ = 0 ) {
        To = To_; Length = Length_; Next = Next_;
        return;
    }
};
edge Edge[ Maxn << 1 ];
long long Used = 0, F[ Maxn ];
long long n, Ans, Size[ Maxn ];

inline void AddEdge( long long From, long long To, long long Value ) {
    ++Used;
    Edge[ Used ] = edge( To, Value, F[ From ] );
    F[ From ] = Used;
    return;
}

void Dfs( long long Point, long long Father, long long Val ) {
    Size[ Point ] = 1;
    for( long long t = F[ Point ]; t; t = Edge[ t ].Next ) {
        if( Edge[ t ].To == Father ) continue;
        Dfs( Edge[ t ].To, Point, Edge[ t ].Length );
        Size[ Point ] += Size[ Edge[ t ].To ];
    }
    Ans = ( 1LL * Ans + 1LL * Size[ Point ] * ( n - Size[ Point ] ) % Mod * 1LL * Val % Mod ) % Mod;
    return;
}

long long FastPow( long long x, long long y ) {
    if( y == 0 ) return 1;
    long long t = x;
    for( long long i = 1; i <= y; ++i )
        t = ( 1LL * t * i ) % Mod;
    return t;
}

inline void Clean() {
    memset( Edge, 0, sizeof( Edge ) );
    memset( F, 0, sizeof( F ) );
    memset( Size, 0, sizeof( Size ) );
    Used = 0;
    Ans = 0;
    return;
}

int main() {
    while( scanf( "%lld", &n ) == 1 ) {
        Clean();
        for( long long i = 1; i < n; ++i ) {
            long long x, y, z;
            scanf( "%lld%lld%lld", &x, &y, &z );
            AddEdge( x, y, z );
            AddEdge( y, x, z );
        }
        Dfs( 1, 1, 0 );
        Ans = 1LL * Ans * FastPow( 2, n - 1 ) % Mod;
        printf( "%lld\n", Ans );
    }
    return 0;
}

