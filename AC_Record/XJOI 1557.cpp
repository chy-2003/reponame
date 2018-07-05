#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
const LL bz[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};
struct Node{
	LL x, y, dir;
};
LL n, m, a[60][60], x1, y1, x2, y2, s, rec[60][60][4], ttt[60][60];
char ch;
Node t;
LL l, r, q2[40010];
Node q[40010];
LL cmp(Node tt){
//	if(tt.x < 1 || tt.x > n - 1 || tt.y < 1 || tt.y > m - 1) return 0;
//	if(a[tt.x][tt.y] || a[tt.x + 1][tt.y + 1] || a[tt.x + 1][tt.y] || a[tt.x][tt.y + 1]) return 0;
	if(rec[tt.x][tt.y][tt.dir]) return 0;
	return 1;
}
void note(Node tt){
	rec[tt.x][tt.y][tt.dir] = 1;
	if(ttt[tt.x][tt.y] != 0)
	ttt[tt.x][tt.y] = min(ttt[tt.x][tt.y], q2[r]);
	else ttt[tt.x][tt.y] = q2[r];
	return;
}
void pr(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			printf("%3lld", ttt[i][j]);
		printf("\n");
	}
}
int main(){
	scanf("%lld%lld", &n, &m);
	for(LL i = 1; i <= n; i++)
		for(LL j = 1; j <= m; j++)
			scanf("%lld", &a[i][j]);
	scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
	cin >> ch;
	if(ch == 'N') s = 0;
	if(ch == 'E') s = 1;
	if(ch == 'S') s = 2;
	if(ch == 'W') s = 3;
	if((x1 == x2) && (y1 == y2)){
		printf("0");
		return 0;
	}
	t.dir = s; t.x = x1; t.y = y1;
	note(t);
	l = 0; r = 1; q[1] = t; q2[1] = 0;
//				printf("%lld %lld %lld %lld\n", q[r].x, q[r].y, q[r].dir, q2[r]);
	while(l < r){
		l++;
//				printf("%lld %lld %lld %lld\n", q[l].x, q[l].y, q[l].dir, q2[l]);
		for(int i = 1; i <= 3; i++){
			t = q[l];
			t.x += bz[0][t.dir] * i;
			t.y += bz[1][t.dir] * i;
			if(t.x < 1 || t.x > n - 1 || t.y < 1 || t.y > m - 1) break;
			if(a[t.x][t.y] || a[t.x + 1][t.y + 1] || a[t.x + 1][t.y] || a[t.x][t.y + 1]) break;
//			printf("%lld  %lld\n", t.x, t.y);
			if(cmp(t)){
				r++;
				q2[r] = q2[l] + 1;
				q[r] = t;
				note(t);
	//			printf("%lld %lld %lld %lld\n", q[r].x, q[r].y, q[r].dir, q2[r]);
				if((t.x == x2) && (t.y == y2)){
	//				pr();
					printf("%lld", q2[r]);
					return 0;
				}
			}
		}
		t = q[l];
		t.dir = (t.dir + 1) % 4;
		if(cmp(t)){
			r++;
			q2[r] = q2[l] + 1;
			q[r] = t;
			note(t);
	//			printf("%lld %lld %lld %lld\n", q[r].x, q[r].y, q[r].dir, q2[r]);
		}
		t = q[l];
		t.dir = (t.dir + 3) % 4;
		if(cmp(t)){
			r++;
			q2[r] = q2[l] + 1;
			q[r] = t;
			note(t);
	//			printf("%lld %lld %lld %lld\n", q[r].x, q[r].y, q[r].dir, q2[r]);
		}
	} 
	printf("-1");
	return 0;
}