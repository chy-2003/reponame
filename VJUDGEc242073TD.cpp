#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 50010, MAXP = 50010;
int n, dis[MAXP], a, b, c, max_P;
int lp, f[MAXN], lin[MAXP * 2 + MAXN], nxt[MAXP * 2 + MAXN], val[MAXP * 2 + MAXN];
inline void add(int x, int y, int z) { lin[++lp] = y; nxt[lp] = f[x]; val[lp] = z; f[x] = lp; return; }
int vis[MAXN];
struct cmp {
	bool operator () (pair<int, int> x, pair<int, int> y) {
		return x.second < y.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
int t;
int main() {
	while(scanf("%d", &n) == 1) {
		lp = 0; memset(f, 0, sizeof(f));
		max_P = 0;
		memset(dis, 255, sizeof(dis));
		for(int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a, &b, &c);
			add(a, b + 1, c);
			max_P = max(max_P, b + 1);
		}
		for(int i = 1; i <= max_P; i++) {
			add(i - 1, i, 0);
			add(i, i - 1, -1);
		}
		while(!pq.empty()) pq.pop();
		memset(vis, 0, sizeof(vis));
		dis[0] = 0;
		pq.push(pair<int, int>(0, 0));
		while(!pq.empty()) {
			t = pq.top().first;
			pq.pop();
			while(!pq.empty() && vis[t]) {
				t = pq.top().first;
				pq.pop();
			}
			if(pq.empty() && vis[t]) break;
			for(int i = f[t]; i; i = nxt[i]) {
				if(vis[lin[i]]) continue;
				if(dis[t] + val[i] > dis[lin[i]]) {
					dis[lin[i]] = dis[t] + val[i];
					pq.push(pair<int, int>(lin[i], dis[lin[i]]));
				}
			}
		}
		printf("%d\n", dis[max_P]);
	}
	return 0;
}
