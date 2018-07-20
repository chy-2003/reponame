#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 2000000000
using namespace std;
const int MAXN = 10010, MAXM = 100010;
struct Edge{
	int from, to, cap, flow;
	Edge(int from_ = 0, int to_ = 0, int cap_ = 0, int flow_ = 0){from = from_; to = to_; cap = cap_; flow = flow_; return; }
};


int get_int(){
	int t = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){
		t = t * 10 + ch - '0';
		ch = getchar();
	}
	return t;
}


int lp = 0, f[MAXN], nxt[MAXM << 1];
Edge edge[MAXM << 1];
inline void add_edge(int u, int v, int w){ edge[lp] = Edge(u, v, w, 0); nxt[lp] = f[u]; f[u] = lp; lp++; return; }


int n, m, s, t;
int p[MAXN], a[MAXN], ans = 0;

int l, r, q[MAXN];
inline void qset(){ l = 1; r = 0; return; }
inline void qpush(int x){ q[++r] = x; return; }
inline bool qempty(){ return l > r; }
inline int qtop(){ return q[l]; }
inline void qpop(){ l++; return; }


int main(){
	memset(f, 255, sizeof(f));
	n = get_int(); m = get_int(); s = get_int(); t = get_int();
	for(int i = 1; i <= m; i++){
		int ui, vi, wi;
		ui = get_int(); vi = get_int(); wi = get_int();
		add_edge(ui, vi, wi);
		add_edge(vi, ui, 0);
	}
	for(;;){
		qset();
		memset(a, 0, sizeof(a));
		a[s] = INF;
		qpush(s);
		while(!qempty()){
			int x = qtop(); qpop();
//			printf("flowing at %d\n", x);
			for(int tt = f[x]; tt != -1; tt = nxt[tt]){
				Edge & e = edge[tt];
				if(a[e.to]) continue;
				if(e.cap <= e.flow) continue;
				a[e.to] = min(a[x], e.cap - e.flow);
				p[e.to] = tt;
				qpush(e.to);
			}
			if(a[t]) break;
		}
		if(!a[t]) break;
		ans += a[t];
		for(int tt = t; tt != s; tt = edge[p[tt]].from){
			edge[p[tt]].flow += a[t];
			edge[p[tt] ^ 1].flow -= a[t];
		}
	}
	printf("%d\n", ans);
	return 0;
}
