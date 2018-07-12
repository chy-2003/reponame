#pragma GCC diagnostic error "-std=c++11"
#include<bits/stdc++.h>
using namespace std;
int n, a[100010], x, k, minnum, pos;
int f[100010][21];
set<int> s;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		x = a[i];
		for(int j = 0; j < 21; j++){
			if(x & 1){
				f[i][j] = i;
			}
			x >>= 1;
		}
	}
	for(int i = n; i >= 1; i--)
		for(int j = 0; j < 21; j++)
			if(f[i][j] == 0)
				f[i][j] = f[i + 1][j];
//	for(int i = 1; i <= n; i++){
//		for(int j = 0; j < 4; j++)
//			printf("%d ", f[i][j]);
//		printf("\n");
//	}
	s.clear();
	for(int i = 1; i <= n; i++){
		x = a[i];
//		printf("%d\n", x);
		s.insert(x);
		pos = i;
		k = 1;
		while(1){
			minnum = n + 1;
			k = 1;
			for(int j = 0; j < 21; j++){
				if(!(x & k))
					if(f[pos + 1][j] && f[pos + 1][j] < minnum)
						minnum = f[i + 1][j];
				k <<= 1;
			}
			if(minnum == n + 1) break;
			x |= a[minnum];
			pos = minnum;
//			printf("%d %d pos = %d\n", minnum, x, pos);
//			if(minnum ==3 && x == 3) return 0;
			s.insert(x);
		}
	}
	cout << s.size() << endl;
	return 0;
}
