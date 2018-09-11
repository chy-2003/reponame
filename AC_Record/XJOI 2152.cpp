/*
 * 10 10 
 * 1 3 2 7 5 8 10 4 9 6 
 * Query 3 
 * OutPut 2;
 * Top 5 
 * 5 1 3 2 7 8 10 4 9 6
 * Ask 6 
 * OutPut 9;
 * Bottom 3 
 * 5 1 2 7 8 10 4 9 6 3
 * Ask 3 
 * OutPut 9;
 * Top 6 
 * 6 5 1 2 7 8 10 4 9 3
 * Insert 4 –1 
 * 6 5 1 2 7 8 4 10 9 3
 * Query 5 
 * OutPut 7;
 * Query 2 
 * OutPut 5;
 * Ask 2 
 * OutPut 3;
 * Total OutPut: 2 9 9 7 5 3
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>

struct Node {
    int LeftChild, RightChild, Value, Random, Size;
    Node(int LeftChild_ = 0,int RightChild_ = 0, int Value_ = 0, int Random_ = 0, int Size_ = 0) {
        LeftChild = LeftChild_; RightChild = RightChild_; Value = Value_; Random = Random_; Size = Size_;
        return;
    }
};
const int INF = 2147483647; 
const int Maxrand = INF;
const int Maxn = 80010;
Node Treap[Maxn << 1];
int n, m, used_space, Root;
int Reflection[Maxn], iReflection[Maxn << 2];
int RanSizeLeft, RanSizeRight, Auto;

inline void Clean() {
    memset(Treap, 0, sizeof(Treap));
    used_space = 0; n = 0; Root = 0;
    memset(Reflection, 0, sizeof(Reflection));
    memset(iReflection, 0, sizeof(iReflection));
    srand(time(NULL));
    Auto = Maxn;
    return;
}

inline void UpdateSize(int x) {
    Treap[x].Size = Treap[Treap[x].LeftChild].Size + Treap[Treap[x].RightChild].Size + 1;
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
        Treap[Root] = Node(0, 0, key, random() % Maxrand, 1);
        return;
    }
    Treap[Root].Size++;
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
            ans += Treap[Treap[Rt].LeftChild].Size + 1;
            Rt = Treap[Rt].RightChild;
        }
    }
    return ans;
}

int QueryKth(int key) {
    int Rt = Root;
    while(key && Rt) {
        if(Treap[Treap[Rt].LeftChild].Size < key && Treap[Treap[Rt].LeftChild].Size + 1 >= key) return Treap[Rt].Value;
        if(Treap[Treap[Rt].LeftChild].Size >= key) 
            Rt = Treap[Rt].LeftChild;
        else {
            key -= Treap[Treap[Rt].LeftChild].Size + 1;
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
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        Reflection[x] = i;
        iReflection[i + Auto] = x;
        Insert(Root, i);
    }
    RanSizeLeft = 1;
    RanSizeRight = n;
    for(int i = 1; i <= m; i++) {
        char ch[10];
        scanf("%s", ch);
        if(ch[0] == 'T') {
            int x; scanf("%d", &x);
            Delete(Root, Reflection[x]);
            Reflection[x] = --RanSizeLeft;
            iReflection[RanSizeLeft + Auto] = x;
            Insert(Root, Reflection[x]);
        }
        if(ch[0] == 'B') {
            int x; scanf("%d", &x);
            Delete(Root, Reflection[x]);
            Reflection[x] = ++RanSizeRight;
            iReflection[RanSizeRight + Auto] = x;
            Insert(Root, Reflection[x]);
        }
        if(ch[0] == 'I') {
            int x, y; scanf("%d%d", &x, &y);
            if(y == -1) {
                int k = iReflection[QueryPre(Reflection[x]) + Auto];
                Delete(Root, Reflection[k]); Delete(Root, Reflection[x]);
                std::swap(iReflection[Reflection[x] + Auto], iReflection[Reflection[k] + Auto]);
                std::swap(Reflection[x], Reflection[k]);
                Insert(Root, Reflection[x]);
                Insert(Root, Reflection[k]);
            }
            if(y == 1) {
                int k = iReflection[QuerySue(Reflection[x]) + Auto];
                Delete(Root, Reflection[k]); Delete(Root, Reflection[x]);
                std::swap(iReflection[Reflection[x] + Auto], iReflection[Reflection[k] + Auto]);
                std::swap(Reflection[x], Reflection[k]);
                Insert(Root, Reflection[x]);
                Insert(Root, Reflection[k]);
            }
        }
        if(ch[0] == 'A') {
            int x; scanf("%d", &x);
            printf("%d\n", QueryRank(Reflection[x]) - 1);
        }
        if(ch[0] == 'Q') {
            int x; scanf("%d", &x);
            printf("%d\n", iReflection[QueryKth(x) + Auto]);
        }
    }
    return 0;
}

