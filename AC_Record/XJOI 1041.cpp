#include<bits/stdc++.h>
using namespace std;
int n, left_child[110], right_child[110], rec[110], x, y, z, root;
void first(int x){
	if(x == 0) return;
	printf("%d ", x);
	first(left_child[x]);
	first(right_child[x]);
	return;
}
void second(int x){
	if(x == 0) return;
	second(left_child[x]);
	printf("%d ", x);
	second(right_child[x]);
	return;
}
void third(int x){
	if(x == 0) return;
	third(left_child[x]);
	third(right_child[x]);
	printf("%d ", x);
	return;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &x, &y, &z);
		rec[y] = 1;
		rec[z] = 1;
		left_child[x] = y;
		right_child[x] = z;
	}
	for(int i = 1; i <= n; i++)
		if(rec[i] == 0){
			root = i;
			break;
		}
	first(root); printf("\n");
	second(root); printf("\n");
	third(root); printf("\n");
	return 0;
}
