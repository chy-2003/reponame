/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         佛祖保佑       永无BUG
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int N, M, R, P, x, y, z, X, Y, Z; 
int value[MAXN];

int lp = 0, f[MAXN], lin[MAXN << 1], nex[MAXN << 1];
inline void add_edge(int x, int y){ lin[++lp] = y; nex[lp] = f[x]; f[x] = lp; return; }

int used = 0;
struct Node{
    int sum, tip;
    Node(int sum_ = 0, int tip_ = 0){ sum = sum_; tip = tip_; }
};
Node tree[MAXN << 2];

int father[MAXN], depth[MAXN], size[MAXN], son[MAXN], top[MAXN], seg[MAXN], rev[MAXN];

inline int get_int(){
    int t = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9'){
        t =t * 10 + ch - '0';
        ch = getchar();
    }
    return t;
}



inline void give_space(int x){ used++; /*printf("Give space %d to %d\n", used, x);*/ seg[x] = used; rev[used] = x; return; }


void dfs1(int fa, int pos){
    depth[pos] = depth[fa] + 1;
    father[pos] = fa;
    size[pos] = 1;
    for(int t = f[pos]; t; t = nex[t])
        if(lin[t] != fa){
            dfs1(pos, lin[t]);
            size[pos] += size[lin[t]];
            if(size[son[pos]] < size[lin[t]]) son[pos] = lin[t];
        }
    return;
}


void dfs2(int fa, int pos){
    if(size[pos] > 1){
        top[son[pos]] = top[pos];
        give_space(son[pos]);
        dfs2(pos, son[pos]);
    }
    for(int t = f[pos]; t; t = nex[t])
        if(lin[t] != fa && lin[t] != son[pos]){
            top[lin[t]] = lin[t];
            give_space(lin[t]);
            dfs2(pos, lin[t]);
        }
    return;
}


void buildtree(int pos, int l, int r){
    tree[pos] = Node(0, 0);
    if(l == r){
        tree[pos].sum = value[rev[l]];
        return;
    }
    int mid = (l + r) >> 1;
    buildtree(pos << 1, l, mid);
    buildtree((pos << 1) + 1, mid + 1, r);
    tree[pos].sum = tree[pos << 1].sum + tree[(pos << 1) + 1].sum;
    tree[pos].sum %= P;
    return;
}


void tip_down(int pos, int l, int r){
//    printf("TipDown at pos = %d(l = %d, r = %d)\n", pos, l, r);
    if(tree[pos].tip == 0){
//        printf("Warning:No values to push down\n");
        return;
    }
    if(l == r){
        tree[pos].tip = 0;
//        printf("Warning:No sons\n changed 1 value: postip%d \n", tree[pos].tip);
        return;
    }
//    printf("Five values:\n leftsontip = %d, rightsontip = %d\n leftsonvalue = %d, rightsonvalue = %d\n postip = %d\n",
//            tree[pos << 1].tip, tree[(pos << 1) + 1].tip, tree[pos << 1].sum, tree[(pos << 1) + 1].sum, tree[pos].tip);
//    printf("\n");
    int mid = (l + r) >> 1;
    tree[pos << 1].tip += tree[pos].tip;
    tree[pos << 1].tip %= P;
    tree[pos << 1].sum += tree[pos].tip * (mid - l + 1);
    tree[pos << 1].sum %= P;
    tree[(pos << 1) + 1].tip += tree[pos].tip;
    tree[(pos << 1) + 1].tip %= P;
    tree[(pos << 1) + 1].sum += tree[pos].tip * (r - mid);
    tree[(pos << 1) + 1].sum %= P;
    tree[pos].tip = 0;
//    printf("changed five values:\n leftsontip = %d, rightsontip = %d\n leftsonvalue = %d, rightsonvalue = %d\n postip = %d\n",
//            tree[pos << 1].tip, tree[(pos << 1) + 1].tip, tree[pos << 1].sum, tree[(pos << 1) + 1].sum, tree[pos].tip);
//    printf("\n");
    return;
}


void seg_add(int pos, int l, int r){
//    printf("Location: pos = %d(l = %d, r = %d)\n", pos, l, r);
    tip_down(pos, l, r);
    if(X <= l && r <= Y){
        tree[pos].tip = Z;
//        printf("Making tip at pos = %d(l = %d, r = %d)\n", pos, l, r);
        tree[pos].sum += Z * (r - l + 1);
        tree[pos].sum %= P;
//        printf("Final value = %d\n", tree[pos].sum);
        return;
    }
    int mid = (l + r) >> 1;
    if(X <= mid) seg_add(pos << 1, l, mid);
    if(Y > mid) seg_add((pos << 1) + 1, mid + 1, r);
    tree[pos].sum = tree[pos << 1].sum + tree[(pos << 1) + 1].sum;
    tree[pos].sum %= P;
//    printf("Final value = %d\n", tree[pos].sum);
    return;
}


int seg_ask(int pos, int l, int r){
    tip_down(pos, l, r);
    if(X <= l && r <= Y) return tree[pos].sum;
    int mid = (l + r) >> 1, t1 = 0, t2 = 0;
    if(X <= mid) t1 = seg_ask(pos << 1, l, mid);
    if(Y > mid) t2 = seg_ask((pos << 1) + 1, mid + 1, r);
    return (t1 + t2) % P;
}


void add1(int x, int y, int z){
    Z = z;
    int fx = top[x], fy = top[y];
    while(fx != fy){
        if(depth[fx] < depth[fy]){ swap(fx, fy); swap(x, y); }
        X = seg[fx]; Y = seg[x];
        seg_add(1, 1, used);
        x = father[fx]; fx = top[x];
    }
    if(depth[x] < depth[y]) swap(x, y);
    X = seg[y]; Y = seg[x];
    seg_add(1, 1, used);
    return;
}


void add2(int x, int z){
    Z = z;
    X = seg[x]; Y = X + size[x] - 1;
    seg_add(1, 1, used);
    return;
}


int ask1(int x, int y){
    int fx = top[x], fy = top[y], ans = 0;
    while(fx != fy){
        if(depth[fx] < depth[fy]){ swap(fx, fy); swap(x, y); }
        X = seg[fx]; Y = seg[x];
        ans += seg_ask(1, 1, used);
        ans %= P;
        x = father[fx]; fx = top[x];
    }
    if(depth[x] < depth[y]) swap(x, y);
    X = seg[y]; Y = seg[x];
    ans += seg_ask(1, 1, used);
    ans %= P;
    return ans;
}


int ask2(int x){
    X = seg[x]; Y = X + size[x] - 1;
    return seg_ask(1, 1, used);
}

/*
void print_lin_Inform1(){
    printf("Father:"); for(int i = 1; i <= N; i++) printf("%d ", father[i]); printf("\n");
    printf("Depth :"); for(int i = 1; i <= N; i++) printf("%d ", depth[i]); printf("\n");
    printf("Size  :"); for(int i = 1; i <= N; i++) printf("%d ", size[i]); printf("\n");
    printf("Son   :"); for(int i = 1; i <= N; i++) printf("%d ", son[i]); printf("\n");
    return;
}


void print_lin_Inform2(){
    printf("Seg   :"); for(int i = 1; i <= N; i++) printf("%d ", seg[i]); printf("\n");
    printf("Rev   :"); for(int i = 1; i <= N; i++) printf("%d ", rev[i]); printf("\n");
    printf("Top   :"); for(int i = 1; i <= N; i++) printf("%d ", top[i]); printf("\n");
    return;
}


void value_check_print(){
    printf("Single Point Print: \n");
    for(int i = 1; i <= N; i++){
        X = seg[i]; Y = seg[i];
        printf("%d \n", seg_ask(1, 1, used));
    }
    printf("\n");
    return;
}
*/

int main(){
    N = get_int(); M = get_int(); R = get_int(); P = get_int();
    for(int i = 1; i <= N; i++) value[i] = get_int();
    for(int i = 1; i <= N; i++) value[i] %= P;
    for(int i = 1; i < N; i++){
        x = get_int(); y = get_int();
        add_edge(x, y); add_edge(y, x);
    }
    dfs1(0, R);
//    print_lin_Inform1();
    top[R] = R; give_space(R);
    dfs2(0, R);
//    print_lin_Inform2();
    buildtree(1, 1, used);
//    printf("tree_top_value = %d \n", tree[1].sum);
//    value_check_print();
    for(int i = 1; i <= M; i++){
        x = get_int();
        if(x == 1){
            x = get_int(); y = get_int(); z = get_int();
            z %= P;
            add1(x, y, z);
        } else
        if(x == 2){
            x = get_int(); y = get_int();
            printf("%d\n", ask1(x, y));
        } else
        if(x == 3){
            x = get_int(); z = get_int();
            z %= P;
            add2(x, z);
        } else
        if(x == 4){
            x = get_int();
            printf("%d\n", ask2(x));
        }
//        value_check_print();
    }
    return 0;
}

