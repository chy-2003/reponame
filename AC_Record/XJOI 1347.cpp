//XJOI 1347
#include <bits/stdc++.h>
using namespace std;
string s;
char ch, a[1010];
int num = 0, l = 0, t, t1, t2, t3;
int l1, l2, l3, b[1010], d[1010], bb[1010], dd[1010], cc[1010], rec[1010];
char c[1010];
int deg(char chh){
//	cout << chh << endl;
	if(chh == '(') return 0;
	if(chh == '+' || chh == '-') return 1;
	if(chh == '*' || chh == '/') return 2;
	if(chh == '^') return 3;
	return 0;
}
void print(){
	int i = 1, j = 1;
	while(bb[i] && i <= l1) i++;
	while(cc[j] && j <= l2) j++;
	for(int k = 1; k <= l3; k++){
		if(dd[k]) continue;
		if(d[k] == 1){
			cout << b[i] << " ";
			i++;
			while(bb[i] && i <= l1) i++;
		}
		if(d[k] == 2){
			cout << c[j] << " ";
			j++;
			while(cc[j] && j <= l2) j++;
		}
	}
	cout << endl;
	return;
}
int unfinished(){
	for(int i = 1; i <= l3; i++){
		if(dd[i]) continue;
		if(d[i] == 2) return i;
	}
	return 0;
}
int po(int xx, int yy){
	int ans = 1;
	for(int i = 1; i <= yy; i++) ans *= xx;
	return ans;
}
int oprat(int x, int y, int z){
	char ct = c[z];
	if(ct == '+') return b[x] + b[y];
	if(ct == '-') return b[x] - b[y];
	if(ct == '*') return b[x] * b[y];
	if(ct == '/') return b[x] / b[y];
	if(ct == '^') return po(b[x], b[y]);
	return 0;
}
int main(){
	cin >> s;
	s = '(' + s + ')';
	l = 1;
	a[l] = '(';
	for(int i = 1; i < s.size(); i++){
		ch = s[i];
//		cout << s[i] << endl;
		if(ch >= '0' && ch <= '9'){
			num = num * 10 + ch - '0';
		} else{
			if(s[i - 1] >= '0' && s[i - 1] <= '9'){
				l1++; l3++;
				d[l3] = 1; b[l1] = num; rec[l3] = l1;
				num = 0;
			}
			if(ch == ')'){
				while(a[l] != '('){
					l3++; l2++;
					d[l3] = 2; c[l2] = a[l]; rec[l3] = l2;
					l--;
				}
				l--;
			} else{
				if(ch != '(')
					while(l >= 1 && deg(a[l]) >= deg(ch)){
						l3++; l2++;
						d[l3] = 2; c[l2] = a[l]; rec[l3] = l2;
						l--;
					}
				l++;
				a[l] = ch;
			}
		}
	}
//	cout << l1 << " " <<  l2 << " "<< l3 << endl;
	print();
	while(1){
		t3 = unfinished();
		if(t3 == 0) break;
		t1 = 0; t2 = 0;
		for(int i = t3 - 1; i >= 1; i--){
			if(dd[i]) continue;
			if(t2 == 0) t2 = i; else{
				t1 = i; break;
			}
		}
//		cout << t1 << " " << t2 << " " << t3 << endl;
		t = oprat(rec[t1], rec[t2], rec[t3]);
		b[rec[t1]] = t;
		bb[rec[t2]] = 1;
		cc[rec[t3]] = 1;
		dd[t2] = 1; dd[t3] = 1;
		print();
	}
	return 0;
}
//8-(3+2*6)/5+4
