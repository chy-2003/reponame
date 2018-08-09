#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#define LL long long
using namespace std;
LL A, B, N;
LL len, q[40];
LL ask(LL t) {
	LL re = 0;
	for(LL i = 1; i < 1 << len; i++) {
		LL num = 1, cnt = 0;
		for(LL j = 0; j < len; j++) 
			if((i >> j) & 1) {
				cnt++;
				num *= q[j + 1];
			} 
		if(cnt % 2 == 1) re += t / num; else re -= t / num;
	}
	return t - re;
}
void work() {
	scanf("%lld%lld%lld", &A, &B, &N);
	len = 0;
	for(LL i = 2; i * i <= N; i++)
		if(N % i == 0) {
			q[++len] = i;
			while(N % i == 0) N /= i;
		}
	if(N > 1) q[++len] = N;
	printf("%lld\n", ask(B) - ask(A - 1));
	return;
}
int main() {
	LL t;
	scanf("%lld", &t);
	for(LL i = 1; i <= t; i++) {
		printf("Case #%lld: ", i);
		work();
	}
	return 0;
}
