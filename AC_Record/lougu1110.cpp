#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1147483647;
const int MaxN = 1000010;

struct node {
	int LeftChild, RightChild, Size, Count, Key, RandomKey;
	node( int LeftChild_ = 0, int RightChild_ = 0, int Size_ = 0, int Count_ = 0, int Key_ = 0, int RandomKey_ = 0 ) {
		LeftChild = LeftChild_; RightChild = RightChild_; Size = Size_; Count = Count_; Key = Key_; RandomKey = RandomKey_;
		return;
	}
};

struct treap {
	int Used, Root;
	node Tree[ MaxN ];
private :
	inline void Updata( int Root ) {
		Tree[ Root ].Size = Tree[ Tree[ Root ].LeftChild ].Size + Tree[ Tree[ Root ].RightChild ].Size + Tree[ Root ].Count;
		return;
	}
	inline void LeftRotate( int & Root ) {
		int k = Tree[ Root ].RightChild;
		Tree[ Root ].RightChild = Tree[ k ].LeftChild;
		Tree[ k ].LeftChild = Root;
		Updata( Root ); Updata( k );
		Root = k;
		return;
	}
	inline void RightRotate( int & Root ) {
		int k = Tree[ Root ].LeftChild;
		Tree[ Root ].LeftChild = Tree[ k ].RightChild;
		Tree[ k ].RightChild = Root;
		Updata( Root ); Updata( k );
		Root = k;
		return;
	}
public :
	inline void Clean() {
		Used = 0; Root = 0; memset( Tree, 0, sizeof( Tree ) );
		return;
	}
	void Insert( int & Root, int Key ) {
		if( Root == 0 ) {
			Root = ++Used;
			Tree[ Root ] = node( 0, 0, 1, 1, Key, rand() % INF );
			return;
		}
		++Tree[ Root ].Size;
		if( Tree[ Root ].Key == Key ) {
			++Tree[ Root ].Count;
			return;
		}
		if( Key < Tree[ Root ].Key ) {
			Insert( Tree[ Root ].LeftChild, Key );
			if( Tree[ Tree[ Root ].LeftChild ].RandomKey < Tree[ Root ].RandomKey ) RightRotate( Root );
			return;
		}
		if( Key > Tree[ Root ].Key ) {
			Insert( Tree[ Root ].RightChild, Key );
			if( Tree[ Tree[ Root ].RightChild ].RandomKey < Tree[ Root ].RandomKey ) LeftRotate( Root );
			return;
		}
		return;
	}
	void Delete( int & Root, int Key ) {
		if( Tree[ Root ].Key == Key ) {
			if( Tree[ Root ].Count > 1 ) {
				--Tree[ Root ].Count; 
				--Tree[ Root ].Size;
				return;
			}
			if( !Tree[ Root ].LeftChild || !Tree[ Root ].RightChild ) {
				Root = Tree[ Root ].LeftChild + Tree[ Root ].RightChild;
				return;
			}
			if( Tree[ Tree[ Root ].LeftChild ].RandomKey < Tree[ Tree[ Root ].RightChild ].RandomKey ) {
				RightRotate( Root );
				Delete( Tree[ Root ].RightChild, Key );
				return;
			} else {
				LeftRotate( Root );
				Delete( Tree[ Root ].LeftChild, Key );
				return;
			}
		}
		--Tree[ Root ].Size;
		if( Key < Tree[ Root ].Key ) Delete( Tree[ Root ].LeftChild, Key ); else Delete( Tree[ Root ].RightChild, Key );
		return;
	}
	int QueryPre( int Key ) {
		int Rt = Root, Ans = -INF;
		while( Rt ) {
			if( Tree[ Rt ].Key == Key && Tree[ Rt ].Count > 1 ) return Tree[ Rt ].Key;
			if( Key > Tree[ Rt ].Key ) {
				Ans = Tree[ Rt ].Key;
				Rt = Tree[ Rt ].RightChild;
			} else Rt = Tree[ Rt ].LeftChild;
		}
		return Ans;
	}
	int QuerySue( int Key ) {
		int Rt = Root, Ans = INF;
		while( Rt ) {
			if( Tree[ Rt ].Key == Key && Tree[ Rt ].Count > 1 ) return Tree[ Rt ].Key;
			if( Key < Tree[ Rt ].Key ) {
				Ans = Tree[ Rt ].Key;
				Rt = Tree[ Rt ].LeftChild;
			} else Rt = Tree[ Rt ].RightChild;
		}
		return Ans;
	}
	int QueryKth( int Num ) {
		int Rt = Root;
		while( Rt ) {
			if( Tree[ Tree[ Rt ].LeftChild ].Size < Num && Tree[ Tree[ Rt ].LeftChild ].Size + Tree[ Rt ].Count >= Num )
				return Tree[ Rt ].Key;
			if( Tree[ Tree[ Rt ].LeftChild ].Size >= Num )
				Rt = Tree[ Rt ].LeftChild;
			else {
				Num -= Tree[ Tree[ Rt ].LeftChild ].Size + Tree[ Rt ].Count;
				Rt = Tree[ Rt ].RightChild;
			}
		}
		return 0;
	}
};

int N, M, Record[ MaxN ][ 2 ], Ans2;
treap Treap1, Treap2;
char ch[ 20 ];

int main() {
	srand( ( unsigned long long ) "F**k Bugs" );
	memset( Record, 0, sizeof( Record ) );
	scanf( "%d%d", &N, &M );
	for( int i = 1; i <= N; ++i ) scanf( "%d", &Record[ i ][ 0 ] );
	for( int i = 1; i <= N; ++i ) Record[ i ][ 1 ] = Record[ i ][ 0 ];
	Record[ N + 1 ][ 0 ] = INF;
	
	Treap1.Clean(); Treap2.Clean();
	for( int i = 1; i <= N; ++i ) Treap1.Insert( Treap1.Root, abs( Record[ i + 1 ][ 0 ] - Record[ i ][ 1 ] ) );
	Ans2 = INF;
	Treap2.Insert( Treap2.Root, -INF / 2 );
	Treap2.Insert( Treap2.Root, INF );
	for( int i = 1; i <= N; ++i ) {
		int Pre = Treap2.QueryPre( Record[ i ][ 0 ] );
		int Sue = Treap2.QuerySue( Record[ i ][ 0 ] );
		Ans2 = min( Ans2, abs( Record[ i ][ 0 ] - Pre ) );
		Ans2 = min( Ans2, abs( Record[ i ][ 0 ] - Sue ) );
		Treap2.Insert( Treap2.Root, Record[ i ][ 0 ] );
	}
	
	for( int i = 1; i <= M; ++i ) {
		scanf( "%s", ch );
		if( ch[ 0 ] == 'I' ) {
			int x, y; scanf( "%d%d", &x, &y );
			Treap1.Delete( Treap1.Root, abs( Record[ x + 1 ][ 0 ] - Record[ x ][ 1 ] ) );
			Treap1.Insert( Treap1.Root, abs( y - Record[ x + 1 ][ 0 ] ) );
			Treap1.Insert( Treap1.Root, abs( y - Record[ x ][ 1 ] ) );
			Record[ x ][ 1 ] = y;
			
			Treap2.Insert( Treap2.Root, y );
			int Pre = Treap2.QueryPre( y );
			int Sue = Treap2.QuerySue( y );
			Ans2 = min( Ans2, abs( y - Pre ) );
			Ans2 = min( Ans2, abs( y - Sue ) );
		} else 
		if( ch[ 4 ] == 'G' ) printf( "%d\n", Treap1.QueryKth( 1 ) ); else printf( "%d\n", Ans2 );
	}
	return 0;
}
