#include<bits/stdc++.h>
using namespace std;


struct Node{
	long long num;
	char fi, la;
};
long long k, x, n, m, t1, t2, t;
Node x1, x2;


long long cnt(long long len, long long num, long long pos);
Node make(long long len, long long num, long long pos, long long meth);
long long work(Node a, Node b);
void print(Node a, long long x);


int main(){
	scanf("%I64d%I64d%I64d%I64d", &k, &x, &n, &m);
	for(long long i1 = 0; i1 + i1 <= n; i1++)
		for(long long j1 = 0; j1 + j1 <= m; j1++)              //The num of "AC" in t1 & t2
			for(long long i2 = 1; i2 <= 3; i2++)
				for(long long j2 = 1; j2  <= 3; j2++){               //"AC" left / mid / right
					t1 = cnt(n, i1, i2);
					t2 = cnt(m, j1, j2);
					for(long long i3 = 1; i3 <= t1; i3++)
						for(long long j3 = 1; j3 <= t2; j3++){       //head & tail
							x1 = make(n, i1, i2, i3);
							x2 = make(m, j1, j2, j3);
//							printf("%I64d %I64d %I64d %I64d\n", i2, j2, i3, j3);
//							printf("%I64d %c %c   %I64d %c %c\n", x1.num, x1.fi, x1.la, x2.num, x2.fi, x2.la);
							t = work(x1, x2);
							if(t == x){
								print(x1, n);
								print(x2, m);
								return 0;
							}
						}
				}
	printf("Happy new year!\n");
	return 0;
}


long long cnt(long long len, long long num, long long pos){
	if(len == 1) return 3;
	if(num == 0) return 4;
	if(pos == 1){
		if(len == num * 2) return 1; else return 2;
	} else
	if(pos == 3){
		if(len == num * 2) return 0; else return 2;
	} else{
		if(len <= num * 2 + 1) return 0; else return 4;
	}
}


Node make(long long len, long long num, long long pos, long long meth){
	Node t;
	if(len == 1)
		if(meth == 1){t.fi = 'A'; t.la = 'A'; t.num = 0; return t; } else 
		if(meth == 2){t.fi = 'C'; t.la = 'C'; t.num = 0; return t; } else
		if(meth == 3){t.fi = 'B'; t.la = 'B'; t.num = 0; return t; }
	if(num == 0){
		if(meth == 1){t.fi = 'A'; t.la = 'A'; t.num = 0; return t; } else 
		if(meth == 2){t.fi = 'C'; t.la = 'A'; t.num = 0; return t; } else
		if(meth == 3){t.fi = 'C'; t.la = 'B'; t.num = 0; return t; } else
		if(meth == 4){t.fi = 'A'; t.la = 'B'; t.num = 0; return t; }
	}
	t.num = num; t.fi = '*'; t.la = '*';
	if(pos == 1){
		if(len == num * 2){ t.fi = 'A'; t.la = 'C'; return t; } else{
			t.fi = 'A'; t.la = (meth == 1) ? 'A' : 'C';
//			if(len == 3 && num == 1 && pos == 1 && meth == 1) printf("*");
			return t;
		}
	} else 
	if(pos == 3){
		t.fi = (meth == '1') ? 'A' : 'C'; t.la = 'C'; return t;
	} else{
		if(meth == 1){ t.fi = 'A'; t.la = 'A'; } else
		if(meth == 2){ t.fi = 'A'; t.la = 'C'; } else
		if(meth == 3){ t.fi = 'C'; t.la = 'A'; } else
		if(meth == 4){ t.fi = 'C'; t.la = 'C'; };
		return t;
	}
}

long long work(Node a, Node b){
	if(k == 1) return a.num;
	if(k == 2) return b.num;
	Node c;
	for(long long i = 3; i <= k; i++){
		c.fi = a.fi; c.la = b.la; c.num = a.num + b.num;
		if(a.la == 'A' && b.fi == 'C') c.num++;
		a = b; b = c;
	}
	return b.num;
}

void print(Node a, long long x){
	if(x == 1){
		printf("%c\n", a.fi);
		return;
	}
	if(a.fi == 'A'){
		if(a.num > 0)
			for(long long i = 1; i <= a.num; i++) printf("AC"); else printf("%c", a.fi);
		if(a.num > 0)
			for(long long i = a.num * 2 + 1; i <= x - 1; i++) printf("B");
		else
			for(long long i = 2; i <= x - 1; i++) printf("B");
		if(a.num * 2 != x) printf("%c", a.la);
		printf("\n");
	} else{
		printf("%c", a.fi);
		for(long long i = 1; i <= a.num; i++) printf("AC");
		for(long long i = a.num * 2 + 2; i <= x - 1; i++) printf("B");
		if(a.num * 2 + 1 != x) printf("%c", a.la);
		printf("\n");
	}
	return;
}
