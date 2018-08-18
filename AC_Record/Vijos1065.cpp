#include <bits/stdc++.h>
using namespace std;
int n, le, a[20], x;
int l, r, q[5000020][2];
int rec[5010];
int get(int x) {
	if(x == 0) return 0;
	return ((get(q[x][1]) * 10 + q[x][0]) % n);
}
void p(int x) {
	if(x == 0) return;
	p(q[x][1]);
	printf("%d", q[x][0]);
	return;
}
int main() {
	scanf("%d", &n);
	scanf("%d", &le);
	for(int i = 1; i <= le; i++) scanf("%d", &a[i]);
	sort(a + 1, a + le + 1);
	l = r = 0;
	for(int i = 1; i <= le; i++) {
		if(a[i] == 0) continue;
		if(a[i] % n == 0) {
			printf("%d\n", a[i]);
			return 0;
		}
		q[++r][0] = a[i];
		q[r][1] = 0;
		rec[a[i] % n] = 1;
	}
	while(l < r) {
		l++;
		for(int i = 1; i <= le; i++) {
			int t = get(l);
			t = (t * 10 + a[i]) % n;
			if(rec[t]) continue;
			q[++r][0] = a[i];
			q[r][1] = l;
			rec[t] = 1;
			if(t == 0) {
				p(r); printf("\n");
				return 0;
			}
		}
		if(r > 5000000) {
			printf("0\n");
			return 0;
		}
	}
	return 0;
}
