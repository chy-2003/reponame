#include<bits/stdc++.h>
using namespace std;
int n, t;
map<int, int> hash;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &t);
		if(hash[t] == 1) printf("ignored\n"); else printf("accepted\n"), hash[t] = 1;
	}
	return 0;
}
