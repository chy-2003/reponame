#include <cstdio>
#include <cstring>
#include <algorithm>

struct Matrix {
    int X1, Y1, X2, Y2;
};
struct Edge {
    int X, Y, H, Flag;
    Edge (int X_ = 0, int Y_ = 0, int H_ = 0, int Flag_ = 0) {
        X = X_; Y = Y_; H = H_; Flag = Flag_;
        return;
    }
};
struct Seg {
    int Len, Cover, Flag;
};

bool cmp(Edge x, Edge y) {
    return x.H < y.H || x.H == y.H && x.Flag < y.Flag;
}

const int Maxn = 50010, Maxd = 20010;
int n, ans = 0, X, Y;
Matrix a[Maxn];
Edge b[Maxn << 1];
Seg SegmentTree[Maxd << 2];

void PushDown(int Pos, int Left, int Right) {
    if(Left == Right) {
        SegmentTree[Pos].Flag = 0;
        return;
    }
    SegmentTree[Pos << 1].Cover += SegmentTree[Pos].Flag;
    SegmentTree[Pos << 1].Flag += SegmentTree[Pos].Flag;
    SegmentTree[Pos << 1 | 1].Cover += SegmentTree[Pos].Flag;
    SegmentTree[Pos << 1 | 1].Flag += SegmentTree[Pos].Flag;
    SegmentTree[Pos].Flag = 0;
    return;
}

void PushUp(int Pos, int Left, int Right) {
    if(Left == Right) return;
    if(SegmentTree[Pos << 1].Cover == SegmentTree[Pos << 1 | 1].Cover) {
        SegmentTree[Pos].Cover = SegmentTree[Pos << 1].Cover; 
        SegmentTree[Pos].Len = SegmentTree[Pos << 1].Len + SegmentTree[Pos << 1 | 1].Len;
        return;
    }
    if(SegmentTree[Pos << 1].Cover < SegmentTree[Pos << 1 | 1].Cover) {
        SegmentTree[Pos].Cover = SegmentTree[Pos << 1].Cover;
        SegmentTree[Pos].Len = SegmentTree[Pos << 1].Len;
        return;
    }
    if(SegmentTree[Pos << 1].Cover > SegmentTree[Pos << 1 | 1].Cover) {
        SegmentTree[Pos].Cover = SegmentTree[Pos << 1 | 1].Cover;
        SegmentTree[Pos].Len = SegmentTree[Pos << 1 | 1].Len;
        return;
    }
    return;
}

void Build(int Pos, int Left, int Right) {
    if(Left == Right) {
        SegmentTree[Pos].Len = 1;
        return;
    }
    int Mid = Left + Right >> 1;
    Build(Pos << 1, Left, Mid);
    Build(Pos << 1 | 1, Mid + 1, Right);
    PushUp(Pos, Left, Right);
    return;
}

void Insert(int Pos, int Left, int Right) {
    if(X <= Left && Right <= Y) {
        SegmentTree[Pos].Cover++;
        SegmentTree[Pos].Flag++;
        return;
    }
    PushDown(Pos, Left, Right);
    int Mid = Left + Right >> 1;
    if(X <= Mid) Insert(Pos << 1, Left, Mid);
    if(Y > Mid) Insert(Pos << 1 | 1, Mid + 1, Right);
    PushUp(Pos, Left, Right);
    return;
}

void Delete(int Pos, int Left, int Right) {
    if(X <= Left && Right <= Y) {
        SegmentTree[Pos].Cover--;
        SegmentTree[Pos].Flag--;
        return;
    }
    PushDown(Pos, Left, Right);
    int Mid = Left + Right >> 1;
    if(X <= Mid) Delete(Pos << 1, Left, Mid);
    if(Y > Mid) Delete(Pos << 1 | 1, Mid + 1, Right);
    PushUp(Pos, Left, Right);
    return;
}

void clean() {
    memset(b, 0, sizeof(b));
    memset(SegmentTree, 0, sizeof(SegmentTree));
    Build(1, 0, Maxd - 10);
    return;
}

void work() {
    int LastLen = SegmentTree[1].Len;
    for(int i = 1; i <= n << 1; i++) {
        if(b[i].Flag == 0) {
            X = b[i].X; Y = b[i].Y;
            Insert(1, 0, Maxd - 10);
        }
        if(b[i].Flag == 1) {
            X = b[i].X; Y = b[i].Y;
            Delete(1, 0, Maxd - 10);
        }
        X = 0; Y = Maxd - 10;
        int t = SegmentTree[1].Len;
        ans += std::abs(t - LastLen);
        LastLen = t;
    }
    return;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d%d%d", &a[i].X1, &a[i].Y1, &a[i].X2, &a[i].Y2);
    for(int i = 1; i <= n; i++) {
        a[i].X1 += 10000;
        a[i].Y1 += 10000;
        a[i].X2 += 10000;
        a[i].Y2 += 10000;
    }
    clean();
    for(int i = 1; i <= n; i++) {
        b[i * 2 - 1] = Edge(a[i].Y1, a[i].Y2 - 1, a[i].X1, 0);
        b[i * 2] = Edge(a[i].Y1, a[i].Y2 - 1, a[i].X2, 1);
    }
    std::sort(b + 1, b + 2 * n + 1, cmp);
    work();
    clean();
    for(int i = 1; i <= n; i++) {
        b[i * 2 - 1] = Edge(a[i].X1, a[i].X2 - 1, a[i].Y1, 0);
        b[i * 2] = Edge(a[i].X1, a[i].X2 - 1, a[i].Y2, 1);
    }
    std::sort(b + 1, b + 2 * n + 1, cmp);
    work();
    printf("%d\n", ans);
    return 0;
}
