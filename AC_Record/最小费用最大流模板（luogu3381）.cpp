#include <bits/stdc++.h>
using namespace std;

const int MaxN = 5010, MaxM = 50010;
int N, M, S, T;
struct edge {
    int To, Flow, Cost, Next;
    edge( int To_ = 0, int Flow_ = 0, int Cost_ = 0, int Next_ = 0 ) {
        To = To_; Flow = Flow_; Cost = Cost_; Next = Next_;
        return;
    }
};
edge Edge[ MaxM << 1 ];
int Start[ MaxN ], UsedSpace;

inline void AddEdge( int From, int To, int Flow, int Cost ) {
    Edge[ ++UsedSpace ] = edge( To, Flow, Cost, Start[ From ] );
    Start[ From ] = UsedSpace;
    return;
}

int AnsFlow, AnsCost, Cost[ MaxN ], Flow[ MaxN ], Rec[ MaxN ];
queue< int > Queue;
bool InQueue[ MaxN ];

bool Spfa() {
    Queue.push( S );
    memset( Cost, 255, sizeof( Cost ) ); Cost[ S ] = 0;
    memset( InQueue, false, sizeof( InQueue ) );
    memset( Flow, 255, sizeof( Flow ) );
    Flow[ S ] = 2147483647;
    while( !Queue.empty() ) {
        int u = Queue.front();
        Queue.pop();
        InQueue[ u ] = false;
        for( int t = Start[ u ]; t != -1; t = Edge[ t ].Next ) {
            if( Edge[ t ].Flow <= 0 ) continue;
            if( ( Cost[ Edge[ t ].To ] != -1 ) && ( Cost[ Edge[ t ].To ] <= Cost[ u ] + Edge[ t ].Cost ) ) continue;
            Cost[ Edge[ t ].To ] = Cost[ u ] + Edge[ t ].Cost;
            Flow[ Edge[ t ].To ] = min( Flow[ u ], Edge[ t ].Flow );
            Rec[ Edge[ t ].To ] = t;
            if( !InQueue[ Edge[ t ].To ] ) {
                InQueue[ Edge[ t ].To ] = true;
                Queue.push( Edge[ t ].To );
            }
        }
    }
    if( Flow[ T ] == -1 ) return false;
    AnsFlow += Flow[ T ];
    int x = T;
    while( x != S ) {
        AnsCost += Flow[ T ] * Edge[ Rec[ x ] ].Cost; 
        Edge[ Rec[ x ] ].Flow -= Flow[ T ];
        Edge[ Rec[ x ] ^ 1 ].Flow += Flow[ T ];
        x = Edge[ Rec[ x ] ^ 1 ].To;
    }
    return true;
}

int main() {
    UsedSpace = -1; memset( Start, 255, sizeof( Start ) );
    scanf( "%d%d%d%d", &N, &M, &S, &T );
    for( int i = 1; i <= M; ++i ) {
        int u, v, w, f;
        scanf( "%d%d%d%d", &u, &v, &w, &f );
        AddEdge( u, v, w, f );
        AddEdge( v, u, 0, -f );
    }
    while( Spfa() );
    printf( "%d %d\n", AnsFlow, AnsCost );
    return 0;
}

