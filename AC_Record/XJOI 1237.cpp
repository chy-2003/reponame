//XJOI 1237
#include <bits/stdc++.h>
using namespace std;
int k, a[100010], l, b[100010], rec1, rec2;
long long ans = 0;
string s;
int main(){
	cin >> k;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		l++;
		a[l] = s[i] - '0';
	}
	if(k == 0){
		int i = 0, la = 0, t;
		while(la < l){
			i = la + 1;
			while(i <= l && a[i] == 0) i++;
			t = i - la - 1;
			ans += (long long)t * (t + 1) / 2;
			la = i;
		}
		printf("%lld", ans);
		return 0;
	}
	int la = l + 1;
	for(int i = l; i >= 1; i--){
		if(a[i] == 0) continue;
		b[i] = la;
		la = i;
	}
	b[0] = la;
	int i = 0, j = 0;
	for(int tt = 1; tt <= k; tt++){
		if(j == l + 1) break;
		j = b[j];
	}
	while(j <= l){
//		printf("%d %d\n", i, j);
		ans += (long long)(b[i] - i) * (b[j] - j);
		j = b[j]; i = b[i];
	}
	printf("%lld", ans);
	return 0;
}