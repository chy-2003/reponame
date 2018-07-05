//XJOI 3594
#include <bits/stdc++.h>
using namespace std;
int l, p[1000010], b[10000010], n;
int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		if(b[i] == 0){
			l++;
			p[l] = i;
		}
		for(int j = 1; j <= l; j++){
			if(i * p[j] > n) break;
			b[i * p[j]] = 1;
			if(i % p[j] == 0) break;
		}
	}
	printf("%d", l);
	return 0;
}