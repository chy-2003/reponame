#include <cstdio>
#include <cstring>
#include <algorithm>

const int Maxd = 20010;
char ch[10];
int x, y, SegmentTree[Maxd << 2];

void Add(int Pos, int Left, int Right) {
    SegmentTree[Pos] ^= x;
    if(Left == Right) return;
    int Mid = Left + Right >> 1;
    if(x <= Mid) Add(Pos << 1, Left, Mid);
    if(x > Mid) Add(Pos << 1 | 1, Mid + 1, Right);
    return;
}

void Remove(int Pos, int Left, int Right) {
    Add(Pos, Left, Right);
    return;
}

int Query(int Pos, int Left, int Right) {
    if(x <= Left && Right <= y) return SegmentTree[Pos];
    int Mid = Left + Right >> 1, t1 = 0, t2 = 0;
    if(x <= Mid) t1 = Query(Pos << 1, Left, Mid);
    if(y > Mid) t2 = Query(Pos << 1 | 1, Mid + 1, Right);
    return t1 ^ t2;
}

int main() {
    memset(SegmentTree, 0, sizeof(SegmentTree));
    while(scanf("%s", ch) == 1) {
        if(ch[0] == 'A') {
            scanf("%d", &x);
            Add(1, 0, 20000);
        }
        if(ch[0] == 'R') {
            scanf("%d", &x);
            Remove(1, 0, 20000);
        }
        if(ch[0] == 'X') {
            scanf("%s", ch);
            scanf("%d", &x);
            scanf("%s", ch);
            scanf("%d", &y);
            printf("%d\n", Query(1, 0, 20000));
        }
    }
    return 0;
}
