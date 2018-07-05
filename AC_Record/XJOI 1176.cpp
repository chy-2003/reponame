#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b, r;
	cin >> a >> b >> r;
	if(a >= r * 2 && b >= r * 2) printf("Alice win"); else printf("Bob win");
	return 0;
}
