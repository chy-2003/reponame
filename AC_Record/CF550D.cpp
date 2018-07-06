#include<bits/stdc++.h>
using namespace std;
int k;
int main(){
	cin >> k;
	if(k % 2 == 0){
		printf("NO");
		return 0;
	}
	if(k == 1){
		printf("YES\n2 1\n1 2\n");
		return 0;
	}
	printf("YES\n");
	printf("%d %d\n", (k + 2) * 2, (k + 2) * k);
	for(int i = 2; i <= k; i++) printf("1 %d\n", i);
	for(int i = 2; i <= k + 1; i++) printf("%d %d\n", i, k + 2);
	for(int i = 2; i < k + 1; i++)
		for(int j = i + 1; j <= k + 1; j++){
			if((j == i + 1) && (i % 2 == 0)) continue;
			printf("%d %d\n", i, j);
		}
	printf("1 %d\n", k + 3);
	for(int i = k + 4; i <= 2 * k + 2; i++) printf("%d %d\n", k + 3, i);
	for(int i = k + 4; i <= 2 * k + 3; i++) printf("%d %d\n", i, 2 * k + 4);
	for(int i = k + 4; i < 2 * k + 3; i++)
		for(int j = i + 1; j <= 2 * k + 3; j++){
			if((j == i + 1) && (i % 2 == 1)) continue;
			printf("%d %d\n", i, j);
		}
	return 0;
}
