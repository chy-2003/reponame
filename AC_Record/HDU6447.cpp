#pragma GCC diagnoistic error "-std=c++11"
#pragma GCC optimize ("Ofast")
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>

const int INF = 2147483647;
const int MaxN = 100010;
struct village {
    int x, y, v;
    village( int x_ = 0, int y_ = 0, int v_ = 0 ) {
        x = x_; y = y_; v = v_; return;
    }
};
bool cmp( village x, village y ) {
    return x.x < y.x || x.x == y.x && x.y < y.y;
}
village Village[ MaxN ];
int N;
int Num, RecY[ MaxN ], RecT[ MaxN ];

struct node {
    int LeftChild, RightChild, Size, Key, RandomKey, Max, Val;
    node( int LeftChild_ = 0, int RightChild_ = 0, int Size_ = 0, int Key_ = 0, int RandomKey_ = 0, int Max_ = 0, int Val_ = 0 ) {
        LeftChild = LeftChild_; RightChild = RightChild_; Size = Size_; Key = Key_; RandomKey = RandomKey_; Max = Max_; Val = Val_; return;
    }
};
node Treap[ MaxN ];
int Used, Root;

inline void Clean() {
    memset( Village, 0, sizeof( Village ) );
    Used = 0; Root = 0;
    memset( Treap, 0, sizeof( Treap ) );
    return;
}

inline void Updata( int Root ) {
    Treap[ Root ].Size = Treap[ Treap[ Root ].LeftChild ].Size + Treap[ Treap[ Root ].RightChild ].Size + 1;
    Treap[ Root ].Max = std::max( Treap[ Root ].Val, std::max( Treap[ Treap[ Root ].LeftChild ].Max, Treap[ Treap[ Root ].RightChild ].Max ) );
    return;
}

inline void LeftRotate( int & Root ) {
    int k = Treap[ Root ].RightChild;
    Treap[ Root ].RightChild = Treap[ k ].LeftChild;
    Treap[ k ].LeftChild = Root;
    Updata( Root ); Updata( k );
    Root = k;
    return;
}

inline void RightRotate( int & Root ) {
    int k = Treap[ Root ].LeftChild;
    Treap[ Root ].LeftChild = Treap[ k ].RightChild;
    Treap[ k ].RightChild = Root;
    Updata( Root ); Updata( k );
    Root = k;
    return;
}

void Insert( int & Root, int Key, int Val ) {
    if( !Root ) {
        Root = ++Used;
        Treap[ Root ] = node( 0, 0, 1, Key, rand() % INF, Val, Val );
        return;
    }
    if( Key == Treap[ Root ].Key ) {
        Treap[ Root ].Val = std::max( Treap[ Root ].Val, Val );
        Updata( Root );
        return;
    }
    if( Key < Treap[ Root ].Key ) {
        Insert( Treap[ Root ].LeftChild, Key, Val );
        if( Treap[ Treap[ Root ].LeftChild ].RandomKey < Treap[ Root ].RandomKey ) RightRotate( Root );
        else Updata( Root );
    } else {
        Insert( Treap[ Root ].RightChild, Key, Val );
        if( Treap[ Treap[ Root ].RightChild ].RandomKey < Treap[ Root ].RandomKey ) LeftRotate( Root );
        else Updata( Root );
    }
    return;
}

int QueryMax( int Key ) {
    int Rt = Root, Ans = 0;
    while( Rt ) {
        if( Treap[ Rt ].Key >= Key ) {
            Rt = Treap[ Rt ].LeftChild;
        } else {
            Ans = std::max( Ans, std::max( Treap[ Treap[ Rt ].LeftChild ].Max, Treap[ Rt ].Val ) );
            Rt = Treap[ Rt ].RightChild;
        }
    }
    return Ans;
}

void Work() {
    Clean();
    int M;
    N = 0;
    scanf( "%d", &M );
    for( int i = 1; i <= M; ++i ) {
        int x, y, v;
        scanf( "%d%d%d", &x, &y, &v );
        if( x && y ) 
            Village[ ++N ] = village( x, y, v );
    }
    std::sort( Village + 1, Village + N + 1, cmp );
    Insert( Root, 0, 0 );
    int Ans = 0;
    Num = 0;
    for( int i = 1; i <= N; ++i ) {
        if( Village[ i ].x != Village[ i - 1 ].x ) {
            for( int j = 1; j <= Num; ++j ) Insert( Root, RecY[ j ], RecT[ j ] );
            Num = 0;
        }
        int t = QueryMax( Village[ i ].y );
        t += Village[ i ].v;
        Ans = std::max( Ans, t );
        ++Num;
        RecY[ Num ] = Village[ i ].y;
        RecT[ Num ] = t;
    }
    printf( "%d\n", Ans );
    return;
}

int main() {
    std::srand( std::time( NULL ) );
    int t;
    scanf( "%d", &t );
    for( int i = 1; i <= t; ++i ) Work();
    return 0;
}

