#include<bits/stdc++.h>
using namespace std;
int n, l, r;
char s[2010];

int check(){
	int x = l, y = r;
	while(x <= y){
		if(s[x] < s[y]) return 1; else
		if(s[x] > s[y]) return 0;
		x++; y--;
	}
	return 1;
}

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	l = 0; r = n - 1;
	while(l <= r){
		if(check()){
			printf("%c", s[l]);
			l++;
		} else {
			printf("%c", s[r]);
			r--;
		}
	}
	return 0;
}
