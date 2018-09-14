#include <cstdio>
#include <cstring>

const int MaxL = 100010, MaxM = 100010;
int L, M;
int x, y;
int SegmentTree[MaxL << 2], SegmTag[MaxL << 2];

void Clean() {
    memset(SegmentTree, 0, sizeof(SegmentTree));
    memset(SegmTag, 0, sizeof(SegmTag));
    return;
}

void TagDown(int Pos, int Left, int Right) {
    if(SegmTag[Pos] == 0) return;
    if(Left == Right) {
        SegmTag[Pos] = 0;
        return;
    }
    SegmTag[Pos] = 0;
    int Mid = Left + Right >> 1;
    SegmTag[Pos << 1] = 1;
    SegmentTree[Pos << 1] = Mid - Left + 1;
    SegmTag[Pos << 1 | 1] = 1;
    SegmentTree[Pos << 1 | 1] = Right - Mid;
    return;
}

void Cover(int Pos, int Left, int Right) {
    TagDown(Pos, Left, Right);
    if(x <= Left && Right <= y) {
        SegmentTree[Pos] = Right - Left + 1;
        SegmTag[Pos] = 1;
        return;
    }
    int Mid = Left + Right >> 1;
    if(x <= Mid) Cover(Pos << 1, Left, Mid);
    if(y > Mid) Cover(Pos << 1 | 1, Mid + 1, Right);
    SegmentTree[Pos] = SegmentTree[Pos << 1] + SegmentTree[Pos << 1 | 1];
    return;
}

int Query(int Pos, int Left, int Right) {
    TagDown(Pos, Left, Right);
    if(x <= Left && Right <= y) return SegmentTree[Pos];
    int Mid = Left + Right >> 1, t1 = 0, t2 = 0;
    if(x <= Mid) t1 = Query(Pos << 1, Left, Mid);
    if(y > Mid) t2 = Query(Pos << 1 | 1, Mid + 1, Right);
    return t1 + t2;
}

int main() {
    Clean();
    scanf("%d%d", &L, &M);
    for(int i = 1; i <= M; i++) {
        scanf("%d%d", &x, &y);
        Cover(1, 0, L);
    }
    x = 0; y = L;
    printf("%d\n", L + 1 - Query(1, 0, L));
    return 0;
}
