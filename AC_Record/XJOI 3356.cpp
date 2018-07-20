#include<cstdio>
#include<cstring>
#include<algorithm>

int get_int(){
	int t = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){
		t = t * 10 + ch - '0';
		ch = getchar();
	}
	return t;
}
int E, F, n, p, w, f[10010];

int main(){
	E = get_int(); F = get_int();
	E = F - E;
	n = get_int();
	memset(f, 255, sizeof(f));
	f[0] = 0;
	for(int i = 1; i <= n; i++){
		p = get_int(); w = get_int();
		for(int j = 0; j + w <= E; j++){
			if(f[j] == -1) continue;
			if(f[j + w] == -1) f[j + w] = f[j] + p; else f[j + w] = std::min(f[j + w], f[j] + p);
		}
	}
	if(f[E] == -1) printf("This is impossible.\n"); else printf("The minimum amount of money in the piggy-bank is %d.\n", f[E]);
}
