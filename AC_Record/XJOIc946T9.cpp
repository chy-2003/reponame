#include<bits/stdc++.h>
using namespace std;
int n, m, road[30][30], d[30], t, l1, l2, c1[30], c2[30], rec[30];
string s1, s2;
void dfs(int father, int id){
	d[id] = father;
	for(int i = 0; i < 26; i++)
		if(i != father && road[id][i] == 1) dfs(id, i);
	return;
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s1 >> s2;
		road[s1[0] - 'A'][s2[0] - 'A'] = 1;
		road[s2[0] - 'A'][s1[0] - 'A'] = 1;
	}
	d['R' - 'A'] = 'R' - 'A';
	dfs('R' - 'A', 'R' - 'A');
	for(int i = 1; i <= m; i++){
		cin >> s1 >> s2;
		memset(rec, 0, sizeof(rec));
		t = s1[0] - 'A';
		l1 = 1;
		c1[l1] = t;
		rec[t] = 1;
		while(t != 'R' - 'A'){
			t = d[t];
			l1++;
			rec[t] = l1;
			c1[l1] = t;
		}
		t = s2[0] - 'A';
		l2 = 0;
		while(rec[t] == 0){
			l2++;
			c2[l2] = t;
			t = d[t];
		}
		l1 = rec[t];
		for(int j = 1; j <= l1; j++) printf("%c", c1[j] + 'A');
		for(int j = l2; j >= 1; j--) printf("%c", c2[j] + 'A');
		printf(" ");
	}
	return 0;
}
