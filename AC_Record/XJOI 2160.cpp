#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 155, M = N * N, Inf = 1 << 25;
int n, m;
struct Edge {
    int x, y, cap, flow, nxt;
};
struct Gragh {
    int cnt, fst[ N ], dist[ N ], s, t, num[ N ], cur[ N ], p[ N ], q[ N ], head, tail;
    Edge e[ M ];
    void set( int S, int T ) {
        s = S, t = T, cnt = 1;
        memset( fst, 0, sizeof fst), memset(e, 0, sizeof e);
    }
    void add( int a, int b, int c ) {
        e[ ++cnt ].x = a, e[ cnt ].y = b, e[ cnt ].cap = c, e[ cnt ].flow = 0;
        e[ cnt ].nxt = fst[ a ], fst[ a ] = cnt;
        e[ ++cnt ].x = b, e[ cnt ].y = a, e[ cnt ].cap = 0, e[ cnt ].flow = 0;
        e[ cnt ].nxt = fst[ b ], fst[ b ] = cnt;
    }
    void re_bfs() {
        memset( dist, -1, sizeof dist);
        head = tail = 0, dist[ t ] = 0, q[ ++tail ] = t;
        while( head < tail )
            for( int x = q[ ++head ], i = fst[ x ]; i; i = e[ i ].nxt)
                if( e[ i ].cap == 0 && dist[ e[ i ].y ] == -1)
                    dist[ q[ ++tail ] = e[ i ].y] = dist[ x ] + 1;
        for( int i = 1; i <= n; i++ )
            if(dist[ i ] == -1)
                dist[ i ] = n;
    }
    int Augment( int & point ) {
        int ex_Flow = Inf;
        for( int i = t; i != s; i = e[ p[ i ] ].x )
            if( e[ p[ i ] ].cap - e[ p[ i ] ].flow < ex_Flow )
                ex_Flow = e[ p[ i ] ].cap - e[ p[ i ] ].flow, point = e[ p[ i ] ].x;
        for( int i = t; i != s; i = e[ p[ i ] ].x )
            e[ p[ i ]].flow += ex_Flow, e[ p[ i ] ^ 1 ].flow -= ex_Flow;
        return ex_Flow;
    }
    int SAP() {
        int x = s, y, MaxFlow = 0;
        memset( num, 0, sizeof num);
        for( int i = 1; i <= n; i++ )
            cur[ i ] = fst[ i ], num[ dist[ i ] ]++;
        while( dist[ s ] < n ) {
            if( x == t ) {
                MaxFlow += Augment( x );
                continue;
            }
            bool found = 0;
            for( int i = cur[ x ]; i != 0 && !found; i = e[ i ].nxt )
                if( dist[ e[ i ].y ] + 1 == dist[ x ] && e[ i ].cap > e[ i ].flow )
                    p[ e[ i ].y ] = cur[ x ] = i, x = e[ i ].y, found = 1;
            if( found )
                continue;
            int d = n + 1;
            for( int i = fst[ x ]; i; i = e[ i ].nxt )
                if( e[ i ].cap > e[ i ].flow )
                    d = min( d, dist[ e[ i ].y ] + 1 );
            if( !( --num[ dist[ x ] ] ) )
                return MaxFlow;
            num[ dist[ x ] = d ]++, cur[ x ] = fst[ x ];
            if( x != s )
                x = e[ p[ x ] ].x;
        }
        return MaxFlow;
    }
};
Gragh g;
int a, b, v;
bool vis[ N ];
char ch[ 500 ];
bool isd( char ch ) {
    return '0' <= ch && ch <= '9';
}
void dfs( int x ) {
    vis[ x ] = 1;
    for( int i = g.fst[ x ]; i; i = g.e[ i ].nxt)
        if( !vis[ g.e[ i ].y ] && g.e[ i ].cap > g.e[ i ].flow )
            dfs(g.e[ i ].y);
}
int main() {
    scanf( "%d%d", &a, &b );
    n = a + b + 2;
    g.set( n - 1, n );
    int sum = 0;
    for( int ii = 1; ii <= a; ii++ ) {
        scanf( "%d", &v );
        sum += v;
        g.add( g.s, ii, v );
        gets( ch );
        int len = strlen( ch );
        for( int i = 0; i < len; ) {
            while( i < len && !isd( ch[ i ] ) )
                i++;
            if( i >= len )
                break;
            v = 0;
            while( i < len && isd( ch[ i ] ) )
                v = v * 10 + ch[ i ] - 48, i++;
            g.add( ii, a + v, Inf );
        }
    }
    for( int i = 1, v; i <= b; i++ ) {
        scanf( "%d", &v );
        g.add( i + a, g.t, v );
    }
    g.re_bfs();
    int ans = g.SAP();
    memset( vis, 0, sizeof vis );
    dfs( g.s );
    for( int i = 1; i <= a; i++ )
        if( vis[ i ] )
            printf( "%d ", i );
    puts( "" );
    for( int i = 1; i <= b; i++)
        if( vis[ i + a ] )
            printf( "%d ", i );
    printf( "\n%d", sum - ans );
    return 0;
}

