#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define LL long long
using namespace std;
const int MAXN = 1000010, MAXM = 10000010;
int n, m, T, rxa, rxc, rya, ryc, rp, x, y, z, a, b;
int lp = 0, f[MAXN], lin[MAXM], nxt[MAXM], val[MAXM];
inline void add(int x, int y, int z) {
	lin[++lp] = y; nxt[lp] = f[x]; val[lp] = z; f[x] = lp; return;
}
 
LL dis[MAXN];
int len = 0, q[MAXN], pos[MAXN];
void qpush(int x) {
	len++; q[len] = x; pos[x] = len;
	int id = len;
	while(id > 1 && (dis[q[id]] < dis[q[id >> 1]])) {
		swap(pos[q[id]], pos[q[id >> 1]]);
		swap(q[id], q[id >> 1]);
		id >>= 1;
	}
	return;
}
void qpop() {
	pos[q[1]] = 0;
	pos[q[len]] = 1;
	q[1] = q[len];
	len--;
	int id = 1;
	while(id << 1 <= len) {
		if(id << 1 | 1 > len) {
			if(dis[q[id << 1]] < dis[q[id]]) {
				swap(pos[q[id << 1]], pos[q[id]]);
				swap(q[id << 1], q[id]);
				break;
			} else break;
		} else {
			if(dis[q[id << 1]] < dis[q[id << 1 | 1]]) {
				if(dis[q[id << 1]] < dis[q[id]]) {
					swap(pos[q[id << 1]], pos[q[id]]);
					swap(q[id << 1], q[id]);
					id <<= 1;
				} else break;
			} else {
				if(dis[q[id << 1 | 1]] < dis[q[id]]) {
					swap(pos[q[id << 1 | 1]], pos[q[id]]);
					swap(q[id << 1 | 1], q[id]);
					id = id << 1 | 1;
				} else break;
			}
		}
	}
	return;
}
void qrefresh(int x) {
	while(x > 1 && dis[q[x]] < dis[q[x >> 1]]) {
		swap(pos[q[x]], pos[q[x >> 1]]);
		swap(q[x], q[x >> 1]);
		x >>= 1;
	}
	return;
}
 
int t;
int main() {
	scanf("%d%d", &n, &m);
	scanf("%d%d%d%d%d%d", &T, &rxa, &rxc, &rya, &ryc, &rp);
	x = 0; y = 0; z = 0;
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= T; i++) {
		x = ((LL)x * rxa + rxc) % rp;
		y = ((LL)y * rya + ryc) % rp;
		a = min(x % n + 1, y % n + 1);
		b = max(y % n + 1, y % n + 1);
		add(a, b, 1e8 - 100 * a);
	}
	for(int i = 1; i <= m -T; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
	}
	memset(dis, 255, sizeof(dis));
	memset(pos, 0, sizeof(pos));
	dis[1] = 0;
	qpush(1);
	while(len > 0) {
		t = q[1];
		qpop();
		for(int k = f[t]; k; k = nxt[k]) {
			if(dis[lin[k]] == -1 || dis[lin[k]] > dis[t] + val[k]) {
				dis[lin[k]] = dis[t] + val[k];
				if(pos[lin[k]] == 0) qpush(lin[k]); else qrefresh(pos[lin[k]]);
			}
		}
	}
	printf("%lld\n", dis[n]);
	return 0;
}

