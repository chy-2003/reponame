#include <cstdio>
#include <cstring>
#include <algorithm>

struct Node {
    int LeftChild, RightChild, Size, Count, Key, RandomKey;
    Node( int LeftChild_ = 0, int RightChild_ = 0, int Size_ = 0, int Count_ = 0, int Key_ = 0, int RandomKey_ = 0 ) {
        LeftChild = LeftChild_; RightChild = RightChild_; Size = Size_; Count = Count_; Key = Key_; RandomKey = RandomKey_;
        return;
    }
};

const int INF = 2147483647;
const int MaxPoint = 100010;
Node Treap[ MaxPoint ];
int Used, Root;

int n, min, x;
char ch[10];

inline void init() {
    std::srand( ( unsigned long long ) "ORZ_PSC dalao" );
    memset( Treap, 0, sizeof( Treap ) );
    Used = 0;
    Root = 0;
    return;
}

inline void Updata( int Rt ) {
    Treap[ Rt ].Size = Treap[ Treap[ Rt ].LeftChild ].Size + Treap[ Treap[ Rt ].RightChild ].Size + Treap[ Rt ].Count;
    return;
}

inline void RightRotate( int & Rt ) {
    int k = Treap[ Rt ].LeftChild;
    Treap[ Rt ].LeftChild = Treap[ k ].RightChild;
    Treap[ k ].RightChild = Rt;
    Updata( Rt ); Updata( k );
    Rt = k;
    return;
}

inline void LeftRotate( int & Rt ) {
    int k = Treap[ Rt ].RightChild;
    Treap[ Rt ].RightChild = Treap[ k ].LeftChild;
    Treap[ k ].LeftChild = Rt;
    Updata( Rt ); Updata( k );
    Rt = k;
    return;
}

void Insert( int & Rt, int Key ) {
    if( Rt == 0 ) {
        Rt = ++Used;
        Treap[ Rt ] = Node( 0, 0, 1, 1, Key, std::rand() % INF );
        return;
    }
    ++Treap[ Rt ].Size;
    if( Key == Treap[ Rt ].Key ) {
        ++Treap[ Rt ].Count;
        return;
    }
    if( Key > Treap[ Rt ].Key ) {
        Insert( Treap[ Rt ].LeftChild, Key );
        if( Treap[ Treap[ Rt ].LeftChild ].RandomKey < Treap[ Rt ].RandomKey ) RightRotate( Rt );
        return;
    }
    if( Key < Treap[ Rt ].Key ) {
        Insert( Treap[ Rt ].RightChild, Key );
        if( Treap[ Treap[ Rt ].RightChild ].RandomKey < Treap[ Rt ].RandomKey ) LeftRotate( Rt );
        return;
    }
    return;
}

void Delete( int & Rt, int Key ) {
    if( Treap[ Rt ].Key == Key ) {
        if( Treap[ Rt ].Count > 1 ) {
            --Treap[ Rt ].Count;
            --Treap[ Rt ].Size;
            return;
        }
        if( !Treap[ Rt ].LeftChild || !Treap[ Rt ].RightChild ) {
            Rt = Treap[ Rt ].LeftChild + Treap[ Rt ].RightChild;
            return;
        }
        if( Treap[ Treap[ Rt ].LeftChild ].RandomKey < Treap[ Treap[ Rt ].RightChild ].RandomKey ) {
            RightRotate( Rt );
            Delete( Treap[ Rt ].RightChild, Key );
            return;
        } else {
            LeftRotate( Rt );
            Delete( Treap[ Rt ].LeftChild, Key );
            return;
        }
    }
    --Treap[ Rt ].Size;
    if( Key > Treap[ Rt ].Key ) Delete( Treap[ Rt ].LeftChild, Key ); else Delete( Treap[ Rt ].RightChild, Key );
    return;
}

int QueryKth( int Num ) {
    int Rt = Root, Ans = 0;
    while( Rt ) {
        if( Treap[ Treap[ Rt ].LeftChild ].Size < Num && Treap[ Treap[ Rt ].LeftChild ].Size + Treap[ Rt ].Count >= Num ) return Treap[ Rt ].Key;
        if( Treap[ Treap[ Rt ].LeftChild ].Size >= Num )
            Rt = Treap[ Rt ].LeftChild; 
        else {
            Num -= Treap[ Treap[ Rt ].LeftChild ].Size + Treap[ Rt ].Count;
            Rt = Treap[ Rt ].RightChild;
        }
    }
    return INF;
}

int main() {
    init();
    scanf( "%d%d", &n, &min );
    int Record = 0, Num = 0;
    int Ans_ = 0;
    for( int i = 1; i <= n; i++ ) {
        scanf("%s%d", ch, &x );
        if( ch[ 0 ] == 'I' ) { if( x < min + Record ) continue; Insert( Root, x - Record ); ++Num; }
        if( ch[ 0 ] == 'A' ) { Record += x; min -= x; }
        if( ch[ 0 ] == 'S' ) {
            Record -= x; min += x;
            int t = QueryKth( Num );
            while( t < min ) {
                Delete( Root, t );
                Num--; Ans_++;
                t = QueryKth( Num );
            }
        }
        if( ch[ 0 ] == 'F' ) if( x > Num ) printf( "-1\n" ); else printf( "%d\n", QueryKth( x ) + Record );
    }
    printf( "%d\n", Ans_ );
    return 0;
}

