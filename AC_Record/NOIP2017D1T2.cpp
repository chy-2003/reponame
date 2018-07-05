#include<bits/stdc++.h>
using namespace std;

int n, po, b[110], x, y;
string a[110];
int c[110];

int read1();
void read2();
void work();
int com_fail();
int FE_com();
int var_com();
void UnP();
void read3(int t);

int main(){
	int t; t = read1();
	while(t){ work(); t--; }
	return 0;
}

void work(){
	read2();
//	printf("%d %d\n", n, po);
	for(int i = 1; i <= n; i++) getline(cin, a[i]);
	if(com_fail()){
		printf("ERR\n");
		return;
	}
	UnP();
	int ans = 0, l;
	l = 0;
	b[0] = 0;
	for(int i = 1; i <= n; i++){
		if(b[i] == -1) l--; else
		if(b[i] == -2){ l++; c[l] = -2; } else
		{ l++; c[l] = (c[l - 1] == -2) ? -2 : c[l - 1] + b[i]; }
		ans = max(ans, c[l]);
	}
	if(ans == po) printf("Yes\n"); else printf("No\n");
	return;
}

int com_fail(){ if(FE_com() || var_com()) return 1; else return 0; }

int FE_com(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(a[i][0] == 'F') cnt++; else cnt--;
		if(cnt < 0) return 1;
	}
	if(cnt > 0) return 1;
	return 0;
}

char ch[110], ll, chh;
int re[27];

int var_com(){
	ll = 0;
	memset(re, 0, sizeof(re));
	for(int i = 1; i <= n; i++){
		if(a[i][0] == 'E'){ re[ch[ll] - 'a'] = 0; ll--; } else
		{
			chh = a[i][2];
			if(re[chh - 'a'] == 1) return 1;
			re[chh - 'a'] = 1;
			ll++;
			ch[ll] = chh;
		}
	}
	return 0;
}

void UnP(){
	for(int i = 1; i <= n; i++)
		if(a[i][0] == 'E') b[i] = -1; else{
			read3(i);
			if(x > y) b[i] = -2; else
			if(x == y) b[i] = 0; else
			if(x < y && y <= 100) b[i] = 0; else
			if(x < y && x <= 100 && y > 100) b[i] = 1; else
			if(x < y && x > 100 && y > 100) b[i] = 0;
//			printf("%d %d %d\n", x, y, b[i]);
		}
	return;
}

int read1(){
	string s;
	int num = 0;
	getline(cin, s);
	for(int i = 0; i < s.size(); i++)
		if(s[i] >= '0' && s[i] <= '9') num = num * 10 + s[i] - '0'; else break;
	return num;
}

void read2(){
	string s;
	getline(cin, s);
	n = 0; int i = 0;
	while(s[i] >= '0' && s[i] <= '9'){ n = n * 10 + s[i] - '0'; i++; } i += 3;
	if(s[i] == '1'){ po = 0; return; } po = 0; i += 2;
	while(s[i] >= '0' && s[i] <= '9'){ po = po * 10 + s[i] - '0'; i++; }
	return;
}

void read3(int t){
	int i = 4;
	if(a[t][i] == 'n'){ x = 101; i++; } else{
		x = 0;
		while(a[t][i] >= '0' && a[t][i] <= '9'){
			x = x * 10 + a[t][i] - '0';
			i++;
		}
	}
	i++;
	if(a[t][i] == 'n'){ y = 101; i++;} else{
		y = 0;
		while(a[t][i] >= '0' && a[t][i] <= '9'){
			y = y * 10 + a[t][i] - '0';
			i++;
		}
	}
	return;
}