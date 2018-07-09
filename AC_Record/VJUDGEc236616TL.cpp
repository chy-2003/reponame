#include<bits/stdc++.h>
using namespace std;
int n, l[310], c[310], m, t, rec[20], p[310], ans;
int f[310][1200];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &l[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
 //   printf("*\n");
	ans = 1000000000;
	for(int i = 1; i <= n; i++){
		memset(f, 255, sizeof(f));
		t = l[i];
		m = 0;
		for(int j = 2; j * j <= t; j++)
			if(t % j == 0){
				m++;
				rec[m] = j;
				while(t % j == 0) t /= j;
			}
        if(t != 1){
            m++; rec[m] = t;
        }
   //     printf("*\n");
		memset(p, 0, sizeof(p));
		for(int j = 1; j <= n; j++){
			t = 1;
			for(int k = 1; k <= m; k++){
				if(l[j] % rec[k] == 0) p[j] |= t;
				t <<= 1;
			}
		}
		f[0][p[i]] = 0;
       // for(int j = 0; j <= p[i]; j++){
        //    for(int k = 0; k <= n; k++)
       //         printf("%d ", f[k][j]);
      ///      printf("\n");
      //  }
      //  printf("\n");
		for(int j = 0; j < n; j++){
            for(int k = 0; k <= p[i]; k++)
                f[j + 1][k] = f[j][k];
			for(int k = 0; k <= p[i]; k++)
				if(f[j][k] != -1){
                    if(j + 1 != i){
				    	if(f[j + 1][k & p[j + 1]] == -1) f[j + 1][k & p[j + 1]] = f[j][k] + c[j + 1];
				    	else f[j + 1][k & p[j + 1]] = min(f[j][k] + c[j + 1], f[j + 1][k & p[j + 1]]);    
                    } else{
				    	if(f[j + 1][k & p[j + 1]] == -1) f[j + 1][k & p[j + 1]] = f[j][k];
				    	else f[j + 1][k & p[j + 1]] = min(f[j][k], f[j + 1][k & p[j + 1]]);  
                    }
				}
        }
		for(int j = 0; j <= n; j++)
			if(f[j][0] != -1) ans = min(f[j][0] + c[i], ans);
   //     printf("*\n");
   //     for(int j = 1; j <= m; j++) printf("%d ", rec[j]); printf("\n");
    //    for(int j = 1; j <= n; j++) printf("%d ", p[j]); printf("\n");
       // for(int j = 0; j <= p[i]; j++){
        //    for(int k = 0; k <= n; k++)
       //         printf("%d ", f[k][j]);
     //       printf("\n");
   //     }
 //       printf("%d\n", ans);
	}
    if(ans != 1000000000) printf("%d\n", ans); else printf("-1\n");
	return 0;
}
