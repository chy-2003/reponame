#include<bits/stdc++.h>
using namespace std;

struct cmp{
	bool operator () (int x, int y){
		return x > y;
	}
};

long long n, m, a[1010][1010], cnt[1010], x, y, t;
priority_queue<int, vector<int>, cmp> pq;

int main(){
	scanf("%lld%lld", &n, &m);
	for(long long i = 1; i <= m; i++){
		scanf("%lld%lld", &x, &y);
		a[x][y] = 1;
	}
	for(long long i = 1; i <= n; i++)
		for(long long j = 1; j <= n; j++) 
			cnt[j] += a[i][j];
	for(long long i = 1; i <= n; i++)
		if(cnt[i] == 0) pq.push(i);
	for(long long i = 1; i <= n; i++){
		t = pq.top();
		pq.pop();
		printf("%lld ", t);
		for(long long j = 1; j <= n; j++)
			if(a[t][j]){
				a[t][j] = 0;
				cnt[j]--;
				if(cnt[j] == 0) pq.push(j);
			}
	}
	return 0;
}