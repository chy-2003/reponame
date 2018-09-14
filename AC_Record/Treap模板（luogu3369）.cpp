#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>

struct Node {
	int LeftChild, RightChild, Value, Random, Size, Count;
	Node(int LeftChild_ = 0,int RightChild_ = 0, int Value_ = 0, int Random_ = 0, int Size_ = 0, int Count_ = 0) {
		LeftChild = LeftChild_; RightChild = RightChild_; Value = Value_; Random = Random_; Size = Size_; Count = Count_;
		return;
	}
};
const int INF = 2147483647; 
const int MaxRand = INF;
const int Maxn = 100010;
Node Treap[Maxn];
int n, used_space, Root;

inline void Clean() {
	memset(Treap, 0, sizeof(Treap));
	used_space = 0; n = 0; Root = 0;
	srand(time(NULL));
	return;
}

inline void UpdateSize(int x) {
	Treap[x].Size = Treap[Treap[x].LeftChild].Size + Treap[Treap[x].RightChild].Size + Treap[x].Count;
	return;
}

inline void LeftRotate(int & x) {
	int y = Treap[x].RightChild;
	Treap[x].RightChild = Treap[y].LeftChild;
	Treap[y].LeftChild = x;
	Treap[y].Size = Treap[x].Size;
	UpdateSize(x);
	x = y;
	return;
}

inline void RightRotate(int & x) {
	int y = Treap[x].LeftChild;
	Treap[x].LeftChild = Treap[y].RightChild;
	Treap[y].RightChild = x;
	Treap[y].Size = Treap[x].Size;
	UpdateSize(x);
	x = y;
	return;
}

void Insert(int & Root, int key) {
	if(!Root) {
		Root = ++used_space;
		Treap[Root] = Node(0, 0, key, random() % MaxRand, 1, 1);
		return;
	}
	Treap[Root].Size++;
	if(Treap[Root].Value == key) {
		Treap[Root].Count++;
		return;
	}
	if(Treap[Root].Value > key) {
		Insert(Treap[Root].LeftChild, key);
		if(Treap[Treap[Root].LeftChild].Random < Treap[Root].Random) RightRotate(Root);
		return;
	}
	if(Treap[Root].Value < key) {
		Insert(Treap[Root].RightChild, key);
		if(Treap[Treap[Root].RightChild].Random < Treap[Root].Random) LeftRotate(Root);
		return;
	}
	return;
}

void Delete(int & Root, int key) {
	if(Treap[Root].Value == key) {
		if(Treap[Root].Count > 1) {
			Treap[Root].Count--;
			Treap[Root].Size--;
			return;
		}
		if(!Treap[Root].LeftChild || !Treap[Root].RightChild) {
			Root = Treap[Root].LeftChild + Treap[Root].RightChild;
			return;
		}
		if(Treap[Treap[Root].LeftChild].Random < Treap[Treap[Root].RightChild].Random) {
			RightRotate(Root);
			Delete(Root, key);
			return;
		}
		if(Treap[Treap[Root].LeftChild].Random > Treap[Treap[Root].RightChild].Random) {
			LeftRotate(Root);
			Delete(Root, key);
			return;
		}
	}
	Treap[Root].Size--;
	if(key < Treap[Root].Value) Delete(Treap[Root].LeftChild, key);
	if(key > Treap[Root].Value) Delete(Treap[Root].RightChild, key);
	return;
}

int QueryRank(int key) {
	int Rt = Root, ans = 0;
	while(Rt) {
		if(key == Treap[Rt].Value) return ans + Treap[Treap[Rt].LeftChild].Size + 1;
		if(key < Treap[Rt].Value)
			Rt = Treap[Rt].LeftChild;
		else {
			ans += Treap[Treap[Rt].LeftChild].Size + Treap[Rt].Count;
			Rt = Treap[Rt].RightChild;
		}
	}
	return ans;
}

int QueryKth(int key) {
	int Rt = Root;
	while(key && Rt) {
		if(Treap[Treap[Rt].LeftChild].Size < key && Treap[Treap[Rt].LeftChild].Size + Treap[Rt].Count >= key) return Treap[Rt].Value;
		if(Treap[Treap[Rt].LeftChild].Size >= key) 
			Rt = Treap[Rt].LeftChild;
		else {
			key -= Treap[Treap[Rt].LeftChild].Size + Treap[Rt].Count;
			Rt = Treap[Rt].RightChild;
		}
	}
	return 0;
}

int QueryPre(int key) {
	int Rt = Root, ans = -INF;
	while(Rt) {
		if(Treap[Rt].Value < key) {
            ans = Treap[Rt].Value;
            Rt = Treap[Rt].RightChild;
        } else 
            Rt = Treap[Rt].LeftChild;
	}
    return ans;
}

int QuerySue(int key) {
    int Rt = Root, ans = INF;
    while(Rt) {
        if(Treap[Rt].Value > key) {
            ans = Treap[Rt].Value;
            Rt = Treap[Rt].LeftChild;
        } else 
            Rt = Treap[Rt].RightChild;
    }
    return ans;
}

int main() {
	Clean();
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int Operator, x; scanf("%d%d", &Operator, &x);
		if(Operator == 1) Insert(Root, x);
//        printf("space = %d, Size = %d, Count = %d, LeftChild = %d, RightChild = %d, key = %d, random = %d\n", used_space, Treap[1].Size, Treap[1].Count, Treap[1].LeftChild, Treap[1].RightChild, Treap[1].Value, Treap[1].Random);
//        printf("Root %d\n", Root);
		if(Operator == 2) Delete(Root, x);
		if(Operator == 3) printf("%d\n", QueryRank(x));
		if(Operator == 4) printf("%d\n", QueryKth(x));
		if(Operator == 5) printf("%d\n", QueryPre(x));
        if(Operator == 6) printf("%d\n", QuerySue(x));
//        printf("Operator %d Finished\n", i);
	}
	return 0;
}
