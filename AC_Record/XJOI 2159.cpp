#include <cstdio>
#include <cstring>
#include <algorithm>

const int INF = 2147483647;
const int MaxN = 5010, MaxM = 50010, MaxEdge = MaxM * 6 + MaxN * 2;
int N, M, P[ MaxN + MaxM ];
int UsedSpace, F[ MaxN + MaxM ], Link[ MaxEdge ], Next[ MaxEdge ], Value[ MaxEdge ];
int S, T;
int Deep[ MaxN + MaxM ], Cur[ MaxN + MaxM ];
int ans = 0;

void clean() {
    UsedSpace = 0;
    memset( F, 255, sizeof( F ));
    memset( Link, 0, sizeof( Link ));
    memset( Next, 0, sizeof( Next ));
    memset( Value, 0, sizeof( Value ));
    memset( P, 0, sizeof( P ));
    return;
}

inline void AddEdge( int x, int y, int v ) {
    Link[ UsedSpace ] = y;
    Next[ UsedSpace ] = F[ x ];
    Value[ UsedSpace ] = v;
    F[ x ] = UsedSpace;
    UsedSpace++;
    return;
}

int l, r, q[ MaxN + MaxM ];
bool bfs() {
    memset( Deep, 255, sizeof( Deep ));
    l = r = 0;
    r = 1;
    q[ 1 ] = S;
    Deep[ S ] = 1;
    while(l < r) {
        l++;
        for(int t = F[ q[ l ]]; t != -1; t = Next[ t ]) 
            if(Value[ t ] && Deep[ Link[ t ] ] == -1) {
                q[ ++r ] = Link[ t ];
                Deep[ Link[ t ] ] = Deep[ q[ l ] ] + 1;
                if(Link[ t ] == T) return true;
            }
    }
    if(Deep[ T ] == -1) return false; else return true;
}

int dfs(int Point, int Flow) {
    if(Point == T || Flow == 0) return Flow;
    int ans = 0;
    for(int & t = Cur[ Point ]; t != -1; t = Next[ t ]) {
        if(!Value[ t ]) continue;
        if(Deep[ Link[ t ] ] != Deep[ Point ] + 1) continue;
        int d = dfs( Link[ t ], std::min( Flow, Value[ t ] ));
        ans += d; Flow -= d;
        Value[ t ] -= d; Value[ t ^ 1 ] += d;
        if(Flow == 0) break;
    }
    return ans;
}

int main() {
    clean();
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; i++) scanf("%d", &P[ i ]);
    for(int i = 1; i <= N; i++) P[ i ] = -P[ i ];
    for(int i = 1; i <= M; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        P[ ++N ] = z;
        AddEdge( N, x, INF );
        AddEdge( x, N, 0 );
        AddEdge( N, y, INF );
        AddEdge( y, N, 0 );
        ans += z;
    }
    N++;
    S = 0; T = N;
    for(int i = 1; i < N; i++) 
        if(P[ i ] > 0) {
            AddEdge( S, i, P[ i ] );
            AddEdge( i, S, 0 );
        }
    for(int i = 1; i < N; i++) 
        if(P[ i ] < 0) {
            AddEdge( i, T, -P[ i ] );
            AddEdge( T, i, 0 );
        }
    while(bfs()) {
        for(int i = 0; i <= N; i++) Cur[ i ] = F[ i ];
        int d = dfs( S, INF );
        while(d) {
            ans -= d;
            d = dfs( S, INF );
        }
    }
    printf("%d\n", ans);
    return 0;
}

