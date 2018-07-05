#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL f[40][40][40], N, K, M, S, rec[40];
char s[40];
int main(){
	scanf("%lld%lld%lld", &N, &K, &M);
	f[1][1][1] = 1;
	for(LL i = 1; i <= N; i++)
		for(LL j = 1; j <= K; j++)
			for(LL k = 1; k <= M; k++){
				if(i == 1 && j == 1 && k == 1) continue;
//				if(K * M - M + N < M * j + i - k) continue;
				if(k > 1) f[i][j][k] = f[i - 1][j][k - 1];
				else
					for(LL kk = 1; kk <= M; kk++){
						f[i][j][k] += f[i - 1][j - 1][kk];
					}
			}
	LL ans = 0;
	for(LL i = 1; i <= M; i++) ans += f[N][K][i];
	printf("%lld\n", ans);
	LL cnt;
	scanf("%lld", &S);
	for(LL tt = 1; tt <= S; tt++){
		scanf("%s", s + 1);
		s[0] = '0';
		ans = 0;
		cnt = 1;
		memset(rec, 0, sizeof(rec));
		for(LL i = 1; i <= strlen(s + 1); i++)
			if(s[i] == s[i - 1]) rec[i] = rec[i - 1] + 1;
			else rec[i] = 1; 
		for(LL i = 2; i <= strlen(s + 1); i++){
			if(s[i] != s[i - 1]) cnt++;
			if(s[i] == '1')
				if(s[i - 1] == '1'){
					for(LL k = 1; k <= M; k++) 
						ans += f[N - i + 1][K - cnt][k];
				} else{
					for(LL k = 1; k <= M - rec[i - 1]; k++)
						ans += f[N - i + 1][K - cnt + 2][k];
				}
//			printf("%lld ", ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
