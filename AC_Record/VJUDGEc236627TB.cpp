#include<bits/stdc++.h>
#define mid ((l + r) >> 1)
using namespace std;
const int MAXN = 500010;
int n, m, x, y, X, Y, tag;

int lp = 0, f[MAXN], lin[MAXN << 1], nex[MAXN << 1];
void add(int x, int y){ lin[++lp] = y; nex[lp] = f[x]; f[x] = lp; return; }

int father[MAXN], deep[MAXN], son[MAXN], size[MAXN], top[MAXN], seg[MAXN], rev[MAXN];

int used = 0, tree[MAXN << 3]; //0 : all empty;  1 : all filled;  2 : unknow;

int get_int(){
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    int t = 0;
    while(ch >= '0' && ch <= '9'){
        t = t * 10 + ch - '0';
        ch = getchar();
    }
    return t;
}



void dfs1(int fa, int pos){
    father[pos] = fa;
    deep[pos] = deep[fa] + 1;
    size[pos] = 1;
    for(int t = f[pos]; t; t = nex[t])
        if(lin[t] != fa){
            dfs1(pos, lin[t]);
            size[pos] += size[lin[t]];
            if(size[lin[t]] > size[son[pos]]) son[pos] = lin[t];
        }
    return;
}


void give_(int x){
    used++;
    seg[x] = used;
    rev[used] = x;
    return;
}


void dfs2(int fa, int pos){
//    printf("Location Imfor : In function dfs2, pos = %d\n", pos);
    if(size[pos] > 1){
        top[son[pos]] = top[pos];
//        printf("let top[%d] = %d\n", son[pos], top[pos]);
        give_(son[pos]);
        dfs2(pos, son[pos]);
    }
    for(int t = f[pos]; t; t = nex[t])
        if(lin[t] != fa && lin[t] != son[pos]){
            top[lin[t]] = lin[t];
//            printf("let top[%d] = %d\n", lin[t], lin[t]);
            give_(lin[t]);
            dfs2(pos, lin[t]);
        }
//    printf("End function dfs2\n");
    return;
}


void tag_down(int pos, int l, int r){
    if(l == r) return;
    if(tree[pos] == 2) return;
    tree[pos << 1] = tree[pos];
    tree[(pos << 1) + 1] = tree[pos];
    return;
}


void collect(int pos, int l, int r){
    if(l == r) return;
    if(tree[pos << 1] == 1 && tree[(pos << 1) + 1] == 1){
        tree[pos] = 1;
        return;
    }
    if(tree[pos << 1] == 0 && tree[(pos << 1) + 1] == 0){
        tree[pos] = 0;
        return;
    }
    tree[pos] = 2;
    return;
}


void seg_set(int pos, int l, int r){
    if(X <= l && r <= Y){
        tree[pos] = tag;
        return;
    }
    if(tree[pos] != 2) tag_down(pos, l, r);
    if((tree[pos] != 2) && (tag != tree[pos])) tree[pos] = 2;
//    int mid = (l + r) >> 1;
    if(X <= mid) seg_set(pos << 1, l, mid);
    if(Y > mid) seg_set((pos << 1) + 1, mid + 1, r);
//    collect(pos, l, r);
    return;
}


int seg_ask(int pos, int l, int r){
//    tag_down(pos, l, r);
    if(tree[pos] != 2) return tree[pos];
//    int mid = (l + r) >> 1;
    if(X <= mid) return seg_ask(pos << 1, l, mid);
    if(X > mid) return seg_ask((pos << 1) + 1, mid + 1, r);
    return -1;
}


void fill(int x){
    X = seg[x]; Y = X + size[x] - 1; tag = 1;
//    printf("Location Infom : in function fill, x = %d, X = %d, Y = %d\n", x, X, Y);
    seg_set(1, 1, used);
    return;
}


void empty(int x){
//    printf("Location Inform: In function empty x = %d\n", x);
    int fx;
    while(x){
        fx = top[x];
        X = seg[fx]; Y = seg[x]; tag = 0;
//        printf("clear from %d to %d (%d-%d)\n", X, Y, fx, x);
        seg_set(1, 1, used);
        x = father[fx];
//        printf("Point Jump to %d\n", x);
    }
    return;
}


int ask(int x){
    X = seg[x];
    return seg_ask(1, 1, used);
}


int main(){
    n = get_int();
//    printf("%d\n", n);
    for(int i = 1; i < n; i++){
        x = get_int(); y = get_int();
        add(x, y); add(y, x);
    }
//    printf("*\n");
    dfs1(0, 1); //get first four values
//    printf("Father: "); for(int i = 1; i <= n; i++) printf("%d ", father[i]); printf("\n");
//    printf("Size  : "); for(int i = 1; i <= n; i++) printf("%d ", size[i]);   printf("\n");
//    printf("Son   : "); for(int i = 1; i <= n; i++) printf("%d ", son[i]);    printf("\n");
//    printf("Depth : "); for(int i = 1; i <= n; i++) printf("%d ", deep[i]);   printf("\n");
    give_(1); top[1] = 1;
    dfs2(0, 1); // get last three values
//    printf("Top   : "); for(int i = 1; i <= n; i++) printf("%d ", top[i]);    printf("\n");
//    printf("Seg   : "); for(int i = 1; i <= n; i++) printf("%d ", seg[i]);    printf("\n");
//    printf("Rev   : "); for(int i = 1; i <= n; i++) printf("%d ", rev[i]);    printf("\n");
    m = get_int();
    for(int i = 1; i <= m; i++){
        x = get_int(); y = get_int();
//        printf("In req %d x = %d, y = %d\n", i, x, y);
        if(x == 1) fill(y); else
        if(x == 2) empty(y); else
        printf("%d\n", ask(y));
//        printf("special output:\n");
//        for(int j = 1; j <= n; j++) printf("ask %d = %d\n", j, ask(j)); printf("\n");
    }
    return 0;
}

