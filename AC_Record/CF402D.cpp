#include<bits/stdc++.h>
using namespace std;
int n, m, a[5010], Fgcd[5010], bad[5010], t, g;
int gcd(int x, int y){
	int m = x % y;
	while(m){
		x = y; y = m; m = x % y;
	}
	return y;
}
int find(int x){
	int l = 1, r = m, mid;
	while(l < r){
		mid = (l + r) / 2;
		if(bad[mid] < x) l = mid + 1; else r = mid;
	}
	if(bad[l] == x) return 1; else return 0;
}
int get_(int x){
	int t = 0, p;
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0){
			if(find(i)) p = -1; else p = 1;
			while(x % i == 0){
				x /= i;
				t += p;
			}
		}
	if(x != 1){
		if(find(x)) t--; else t++;
	}
	return t;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	Fgcd[1] = a[1];
	for(int i = 2; i <= n; i++) Fgcd[i] = gcd(Fgcd[i - 1], a[i]);
//	for(int i = 1; i <= n; i++) printf("%d ", Fgcd[i]); printf("\n");
	for(int i = 1; i <= m; i++) scanf("%d", &bad[i]);
	for(int i = n; i >= 1; i--){
		t = get_(Fgcd[i]);
		if(t < 0){
			g = Fgcd[i];
//			printf("i = %d    t = %d    g = %d\n", i, t, g);
			for(int j = 1; j <= i; j++){
				a[j] /= g;
				Fgcd[j] /= g;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) ans += get_(a[i]);
	printf("%d\n", ans);
	return 0;
}
