#include<bits/stdc++.h>
using namespace std;
int n;
string s[10], ss;
int f[10][10], t;
int rec1[10], rec2[10], us1[10], us2[10], bo;

int find(string st){
	for(int i = 1; i <= n; i++)
		if(s[i] == st) return i;
	return 0;
}

void check(){
//	printf("In FunctionCheck:\n");
//	for(int i = 1; i <= n; i++) cout << rec1[i] << " "; cout << endl;
//	for(int i = 1; i <= n; i++) cout << rec2[i] << " "; cout << endl;
	int l1, l2;
	l1 = 1; l2 = 1;
	while(l1 <= n && l2 <= n){
		if(f[rec2[l2]][rec1[l1]] == 1) l1++; else l2++;
	}
//	printf("The ans id %d\n", (l1 > n) ? 0 : 1);
//	printf("EndCheck\n");
	if(l1 > n) bo = 0;
	return;
}

void print(){
	printf("Yes\n");
	for(int i = 1; i <= n; i++) cout << s[rec1[i]] << " ";
	cout << "\n";
	return;
}

void work2(int pos){
//	printf("Work2: Depth = %d\n", pos);
	if(pos > n){
		check();
		return;
	}
	for(int i = 1; i <= n; i++)
		if(us2[i] == 0){
			us2[i] = 1;
			rec2[pos] = i;
			work2(pos + 1);
			if(bo == 0) return;
			us2[i] = 0;
		}
	return;
}

void work(int pos){
//	printf("Work1: Depth = %d\n", pos);
	if(pos > n){
		bo = 1;
		memset(us2, 0, sizeof(us2));
		work2(1);
		if(bo == 1){
			print();
			exit(0);
		}
		return;
	}
	for(int i = 1; i <= n; i++)
		if(us1[i] == 0){
			us1[i] = 1;
			rec1[pos] = i;
			work(pos + 1);
			us1[i] = 0;
		}
	return;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i];
	sort(s + 1, s + n + 1);
//	for(int i = 1; i <= n; i++) cout << s[i] << endl;
	for(int i = 1; i <= n; i++){
		cin >> t;
		for(int j = 1; j <= t; j++){
			cin >> ss;
			f[i][find(ss)] = 1;
		}
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++) printf("%d ", f[i][j]);
//		printf("\n");
//	} printf("\n");
	memset(us1, 0, sizeof(us1));
	memset(us2, 0, sizeof(us2));
	work(1);
	printf("No\n");
	return 0;
}
