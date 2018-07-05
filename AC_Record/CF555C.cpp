//将题中图顺时针旋转90度，U->R:1 L->U:0
//R处理改变U（tree1）(max)   op  (tree2) (min)
#include<bits/stdc++.h>
using namespace std;


struct Node{
	int x, dir, id, zip;
};

const int MAXN = 1000000000, MAXQ = 200010;
int n, q, x, y, unzip[200010], t, tip1[800010], tip2[800010];
char ch;
Node a[MAXQ];


bool cmp1(Node x, Node y){
	return x.x < y.x;
}

bool cmp2(Node x, Node y){
	return x.id < y.id;
}

void tip1_down(int id, int l, int r){
	if(l == r) return;
	tip1[id << 1] = max(tip1[id << 1], tip1[id]);
	tip1[(id << 1) + 1] = max(tip1[(id << 1) + 1], tip1[id]);
	tip1[id] = 0;
	return;
}

void tip2_down(int id, int l, int r){
	if(l == r) return;
	tip2[id << 1] = min(tip2[id << 1], tip2[id]);
	tip2[(id << 1) + 1] = min(tip2[(id << 1) + 1], tip2[id]);
	tip2[id] = 1000000000;
	return;
}

void put1(int ll, int rr, int value, int id, int l, int r){
	tip1_down(id, l, r);
	if(ll <= l && r <= rr){
		tip1[id] = max(tip1[id], value);
//		printf("put1 : ll = %d   rr = %d   value = %d   l = %d   r = %d    tip = %d\n", ll, rr, value, l, r, tip1[id]);
		return;
	}
	if(ll <= (l + r) >> 1) put1(ll, rr, value, id << 1, l, (l + r) >> 1);
	if(rr > (l + r) >> 1) put1(ll, rr, value, (id << 1) + 1, ((l + r) >> 1) + 1, r);
	return;
}

void put2(int ll, int rr, int value, int id, int l, int r){
	tip2_down(id, l, r);
	if(ll <= l && r <= rr){
		tip2[id] = min(tip2[id], value);
//		printf("put2 : ll = %d   rr = %d   value = %d   l = %d   r = %d    tip = %d\n", ll, rr, value, l, r, tip2[id]);
		return;
	}
	if(ll <= (l + r) >> 1) put2(ll, rr, value, id << 1, l, (l + r) >> 1);
	if(rr > (l + r) >> 1) put2(ll, rr, value, (id << 1) + 1, ((l + r) >> 1) + 1, r);
	return;
}

int ask1(int t, int id, int l, int r){
//	printf("ask1 : t = %d   l = %d   r = %d   tip = %d\n", t, l, r, tip1[id]);
	tip1_down(id, l, r);
	if(l == r) return tip1[id];
	if(t <= (l + r) >> 1) return ask1(t, id << 1, l, (l + r) >> 1);
	else return ask1(t, (id << 1) + 1, ((l + r) >> 1) + 1, r);
}

int ask2(int t, int id, int l, int r){
//	printf("ask2 : t = %d   l = %d   r = %d   tip = %d\n", t, l, r, tip2[id]);
	tip2_down(id, l, r);
	if(l == r) return tip2[id];
	if(t <= (l + r) >> 1) return ask2(t, id << 1, l, (l + r) >> 1);
	else return ask2(t, (id << 1) + 1, ((l + r) >> 1) + 1, r);
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= q; i++){
		scanf("%d%d%c%c", &x, &y, &ch, &ch);
		a[i].x = x; a[i].id = i;
		a[i].dir = (ch == 'L') ? 0 : 1;
	}
	
	sort(a + 1, a + q + 1, cmp1); // zip
	a[0].x = 0;
	for(int i = 1; i <= q; i++) a[i].zip = i;
	for(int i = 1; i <= q; i++) if(a[i].x == a[i - 1].x) a[i].zip = a[i - 1].zip;
	for(int i = 1; i <= q; i++) unzip[a[i].zip] = a[i].x;
	unzip[0] = 0; unzip[q + 1] = n + 1;
	sort(a + 1, a + q + 1, cmp2); // unzip
//	for(int i = 1; i <= q; i++) printf("i = %d  x = %d  dir = %d  zip = %d  id = %d\n", i, a[i].x, a[i].dir, a[i].zip, a[i].id);
//	for(int i = 0; i <= q + 1; i++) printf("%d ", unzip[i]); printf("\n");
	
	put1(1, q, 0, 1, 1, q);
	memset(tip2, 0x3f, sizeof(tip2));
	put2(1, q, q + 1, 1, 1, q);
//	printf("load tip1 = %d   tip2 = %d\n", tip1[1], tip2[1]);
	
	for(int i = 1; i <= q; i++)
		if(a[i].dir == 0){
			t = ask1(a[i].zip, 1, 1, q);
//			printf("i = %d  x = %d  dir = %d  zip = %d  id = %d\n", i, a[i].x, a[i].dir, a[i].zip, a[i].id);
//			printf("t = %d  unzip = %d ", unzip[t], a[i].x);
			printf("%d\n", a[i].x - unzip[t]);
			put2(t, a[i].zip, a[i].zip, 1, 1, q);
			put1(a[i].zip, a[i].zip, a[i].zip, 1, 1, q);
//			printf("\n\n\n\n");
		} else{
			t = ask2(a[i].zip, 1, 1, q);
//			printf("i = %d  x = %d  dir = %d  zip = %d  id = %d\n", i, a[i].x, a[i].dir, a[i].zip, a[i].id);
//			printf("t = %d  unzip = %d ", unzip[t], a[i].x);
			printf("%d\n", unzip[t] - a[i].x);
			put1(a[i].zip, t, a[i].zip, 1, 1, q);
			put2(a[i].zip, a[i].zip, a[i].zip, 1, 1, q);
//			printf("\n\n\n\n");
		}
	return 0;
}
