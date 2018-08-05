#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010, MAXM = 20;
int n, m, k, rec[1010], vis[2010], cnt;
char ch;
void clean() {
    memset(rec, 0, sizeof(rec));
    memset(vis, 9, sizeof(vis));
    return;
}
void work() {
	clean();
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			ch = getchar();
			while(ch != 'A' && ch != 'B') ch = getchar();
			rec[i] = rec[i] * 2 + ch - 'A';
		}
	int ans = 0;
	for(int i = 0; i < 1 << m; i++) {
		memset(vis, 0, sizeof(vis));
        cnt = 0;
        for(int j = 1; j <= n; j++) {
            int x = i & rec[j];
            vis[x]++; cnt++;
        }
        int t = 0;
        for(int j = 0; j < 1 << m; j++) t = t + (cnt - vis[j]) * vis[j];
        if(t >= k * 2) ans++;
	}
    printf("%d\n", ans);
    return;
}
int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) printf("Case #%d: ", i), work();
	return 0;
}

