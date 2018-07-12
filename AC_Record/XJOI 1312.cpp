//#pragma GCC diagnostic error "-std=c++11"
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
string s;
int a[30010], b[30010], x;
stringstream Sin;
int main(){
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	getline(cin, s);
	Sin.clear();
	Sin << s;
	while(Sin >> x){
		a[x] = 1;
	}
	getline(cin, s);
	Sin.clear();
	Sin << s;
	while(Sin >> x){
		b[x] = 1;
	}
	for(int i = 1; i <= 30000; i++)
		if(a[i] || b[i]) printf("%d ", i);
	printf("\n");
	for(int i = 1; i <= 30000; i++)
		if(a[i] && !b[i]) printf("%d ", i);
	printf("\n");
	for(int i = 1; i <= 30000; i++)
		if(a[i] && b[i]) printf("%d ", i);
	printf("\n");
	for(int i = 1; i <= 30000; i++)
		if(a[i] && !b[i] || !a[i] && b[i]) printf("%d ", i);
	printf("\n");
	return 0;
}
