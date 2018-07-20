#include<cstdio>
#include<cstring>
#define INF 2000000000

int min(int x, int y) {return (x < y) ? x : y; }

int get_int(){
	int t = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){
		t = t * 10 + ch - '0';
		ch = getchar();
	}
	return t;
}

struct Edge{
	int from, to, cap, flow;
	Edge(int from_ = 0, int to_ = 0, int cap_ = 0, int flow_ = 0) {from = from_; to = to_; cap = cap_; flow = flow_; return; }
};

int lp = 0, f[210], nxt[40010];
Edge edge[40010];
inline void add(int x, int y, int z) {edge[lp] = Edge(x, y, z, 0); nxt[lp] = f[x]; f[x] = lp++; return; }

int n, rec[210];

int l, r, q[210], p[210], a[210];
inline void qset() { l = 1; r = 0; return; }
inline void qadd(int x) { q[++r] = x; return; }
inline bool qempty() {return l > r; }
inline int qtop() { return q[l]; }
inline void qpop() { l++; return; }


int lans = 0, ans[210][210], vis[210];


bool is_prime(int x){
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0){
//			printf("%d 0\n", x);
			return false;
		}
//	printf("%d 1\n", x);
	return true;
}

void dfs(int x){
	ans[lans][0]++;
	ans[lans][ans[lans][0]] = x;
	vis[x] = 1;
	for(int t = f[x]; t != -1; t = nxt[t])
		if((vis[edge[t].to] == 0) && (edge[t].flow != 0)){
			dfs(edge[t].to);
			break;
		}
	return;
}


int main(){
	n = get_int();
	for(int i = 1; i <= n; i++) rec[i] = get_int();

	memset(f, 255, sizeof(f));
	for(int i = 1; i <= n; i++)
		if(rec[i] % 2 == 1) add(0, i, 2), add(i, 0, 0); else add(i, n + 1, 2), add(n + 1, i, 0);
	for(int i = 1; i <= n; i++) if(rec[i] % 2 == 1)
		for(int j = 1; j <= n; j++) if(rec[j] % 2 == 0)
			if(is_prime(rec[i] + rec[j]))
				add(i, j, 1), add(j, i, 0);
		
	int flow = 0;
	for(;;){
		memset(a, 0, sizeof(a));
		a[0] = INF;
		qset();
		qadd(0);
//		printf("\n");
		while(!qempty()){
			int x = qtop(); qpop();
//			printf("%d\n", x);
			for(int t = f[x]; t != -1; t = nxt[t]){
				Edge &e = edge[t];
				if(a[e.to]) continue;
				if(e.flow >= e.cap) continue;
				a[e.to] = min(a[x], e.cap - e.flow);
				p[e.to] = t;
				qadd(e.to);
			}
			if(a[n + 1]) break;
		}
		if(!a[n + 1]) break;
		flow += a[n + 1];
		for(int t = n + 1; t != 0; t = edge[p[t]].from) {
			edge[p[t]].flow += a[n + 1];
			edge[p[t] ^ 1].flow -= a[n + 1];
//			printf("%d %d\n", edge[p[t]].from, edge[p[t]].to);
		}
	}

	if(flow != n) {
		printf("Impossible\n");
		return 0;
	}

	memset(vis, 0, sizeof(vis));
	memset(ans, 0, sizeof(ans));
	vis[0] = 1; vis[n + 1] = 1;
	for(int i = 1; i <= n; i++)
		if(!vis[i]) { lans++; dfs(i); }
	printf("%d\n", lans);
	for(int i = 1; i <= lans; i++){
		printf("%d ", ans[i][0]);
		for(int j = 1; j <= ans[i][0]; j++) printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}
