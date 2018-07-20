#include<cstdio>
#include<cmath>
const int MAXN = 100010;
int n, m, power[MAXN], k, count[MAXN], nxt[MAXN], num;

//the function get_block change the possition information into the number of the block
inline int get_block(int x){
	if(x > n) return num + 1;
	return (x + k - 1) / k;
}

int main(){
	scanf("%d%d", &n, &m);
	k = (int)sqrt(n); num = (n + k - 1) / k;
	for(int i = 1; i <= n; i++) scanf("%d", &power[i]);
	//block i lays from (k - 1) * i + 1 to k * i
	//the sum of the blocks is (n + k - 1) / k
	//the virtual block is the ((n + k - 1)/k)^th block
	//count[i] save the step to jump out of the block,   nxt[i] save the possition after the ball jump out
	for(int i = n; i >= 1; i--){
		int pos1, pos2;
		pos1 = i; pos2 = pos1 + power[i];
		if(get_block(pos1) != get_block(pos2)){
			count[i] = 1; nxt[i] = pos2;
		} else{
			count[i] = count[pos2] + 1;
			nxt[i] = nxt[pos2];
		}
	}
	//printf("*\n");
	int x, y, z;
	for(int i = 1; i <= m; i++){
		scanf("%d", &x);
		if(x == 1){
			scanf("%d", &y);
			int ans = 0, last = 0;
			while(get_block(y) <= num){
				ans += count[y]; last = y; y = nxt[y];
			}
			while(last + power[last] <= n) last += power[last];
			printf("%d %d\n", last, ans);
		} else {
			scanf("%d%d", &y, &z); int rec = y;
			power[y] = z;
			if(get_block(y) != get_block(y + z)){
				count[y] = 1; nxt[y] = y + z;
			} else {
				count[y] = count[y + z] + 1;
				nxt[y] = nxt[y + z];
			}
			for(int t = rec - 1; get_block(t) == get_block(rec); t--)
				if(get_block(t) != get_block(t + power[t])){
					count[t] = 1; nxt[t] = t + power[t];
				} else {
					count[t] = count[t + power[t]] + 1;
					nxt[t] = nxt[t + power[t]];
				}
		}
	}
	return 0;
}
