#include<bits/stdc++.h>
#define LL int
using namespace std;
 
 
LL n, m, k, p, sum1[1010], sum2[1010];
long long rec[1000010];
long long  ans = -1000000000000000000, cnt;
LL a[1010][1010];
LL q1[1010], q2[1010], l1, l2, t;
 
 
void clear1();
void push1(LL x);
LL top1();
void pop1();
 
void clear2();
void push2(LL x);
LL top2();
void pop2();
 
 
 
int main(){
	scanf("%d%d%d%d", &n, &m, &k, &p);
	for(LL i = 1; i <= n; i++) for(LL j = 1; j <= m; j++) scanf("%d", &a[i][j]);
	memset(sum1, 0, sizeof(sum1)); memset(sum2, 0, sizeof(sum2));
	for(LL i = 1; i <= n; i++) for(LL j = 1; j <= m; j++) sum1[i] += a[i][j], sum2[j] += a[i][j];
		clear1(); clear2(); cnt = 0;
		for(LL j = 1; j <= n; j++) push1(sum1[j]);
		rec[0] = 0;
		for(LL j = 1; j <= k; j++){ t = top1(); pop1(); cnt += t; push1(t - p * m); rec[j] = cnt;}
//		for(LL i = 0; i <= k; i++) printf("%lld ", rec[i]); printf("\n");
		for(LL j = 1; j <= m; j++) push2(sum2[j]);
		ans = rec[k]; cnt = 0;
		for(LL j = 1; j <= k; j++){ 
			t = top2(); pop2(); cnt += t; push2(t - p * n); 
//			printf("%lld ", rec[k - j] + cnt - (long long)((long long)(k - j) * p) * j);
			ans = max(ans, rec[k - j] + cnt - (long long)((long long)(k - j) * p) * j); 
		}
	printf("%lld\n", ans);
	return 0;
}
 
 
 
 
void clear1(){ l1 = 0; memset(q1, 0, sizeof(q1)); return; }
 
void clear2(){ l2 = 0; memset(q2, 0, sizeof(q2)); return; }
 
void push1(LL x){ l1++; q1[l1] = x; LL t = l1; while(t > 1 && q1[t >> 1] < q1[t]){ swap(q1[t >> 1], q1[t]); t >>= 1; } return; }
 
void push2(LL x){ l2++; q2[l2] = x; LL t = l2; while(t > 1 && q2[t >> 1] < q2[t]){ swap(q2[t >> 1], q2[t]); t >>= 1; } return; }
 
LL top1(){ return q1[1]; }
 
LL top2(){ return q2[1]; }
 
void pop1(){
	q1[1] = q1[l1]; l1--;
	LL t = 1;
	while((t << 1) <= l1){
		if(((t << 1) + 1) > l1)
			if(q1[t << 1] > q1[t]) swap(q1[t << 1], q1[t]), t <<= 1;
			else break;
		else
			if(q1[(t << 1) + 1] > q1[t << 1])
				if(q1[(t << 1) + 1] > q1[t]) swap(q1[(t << 1) + 1], q1[t]), t = (t << 1) + 1;
				else break;
			else
				if(q1[t << 1] > q1[t]) swap(q1[t << 1], q1[t]), t <<= 1;
				else break;
	}
	return;
}
 
void pop2(){
	q2[1] = q2[l2]; l2--;
	LL t = 1;
	while((t << 1) <= l2){
		if(((t << 1) + 1) > l2)
			if(q2[t << 1] > q2[t]) swap(q2[t << 1], q2[t]), t <<= 1;
			else break;
		else
			if(q2[(t << 1) + 1] > q2[t << 1])
				if(q2[(t << 1) + 1] > q2[t]) swap(q2[(t << 1) + 1], q2[t]), t = (t << 1) + 1;
				else break;
			else
				if(q2[t << 1] > q2[t]) swap(q2[t << 1], q2[t]), t <<= 1;
				else break;
	}
	return;
}
