#include<bits/stdc++.h>
using namespace std;
int n, k;
int x, y, lp = 0, f[1000010], val[2000010], lin[2000010], t;
int d[1000010][21], deep[1000010], note[1000010];

void add(int x, int y){
	lp++;
	val[lp] = y;
	lin[lp] = f[x];
	f[x] = lp;
	return;
}

void tree_build(int father, int id){
	d[id][0] = father;
	deep[id] = deep[father] + 1;
	for(int i = 1; i < 21; i++) d[id][i] = d[d[id][i - 1]][i - 1];
	int t = f[id];
	while(t){
		if(val[t] != father) tree_build(id, val[t]);
		t = lin[t];
	}
	return;
}

int get(int x){
	while(note[d[x][0]] != 1){
		for(int i = 20; i >= 0; i--)
			if(note[d[x][i]] == 0){
				x = d[x][i];
				break;
			}
	}
	return x;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i < n; i++){
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	note[0] = 1;
	for(int i = 0; i < 21; i++) d[n][i] = n;
	tree_build(n, n);
	int rest = n - k - 1;
	note[n] = 1;
	for(int i = n - 1; i >= 1; i--){
		if(rest == 0) break;
		if(note[i] == 1) continue;
		t = get(i);
		t = deep[i] - deep[t] + 1;
		if(t <= rest){
			t = i;
			while(note[t] == 0){
				note[t] = 1;
				if(t != 0)
				rest--;
				t = d[t][0];
			}
		}
	}
	for(int i = 1; i <= n; i++)
		if(note[i] == 0) printf("%d ", i);
	return 0;
}
