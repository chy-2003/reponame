#include<bits/stdc++.h>
using namespace std;
int n, a[100010], bo, t;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = (int)sqrt(n); i >= 1; i--)
        if(n % i == 0){
        	if(n / 2 > 2){
        	    for(int j = 0; j < i; j++){
            	    if(a[j] == 0) continue;
           	     	t = j + i; t %= n;
           	     	bo = 1;
           	     	while(t != j){
                    	if(a[t] == 0){
                    	    bo = 0;
                        	break;
                    	}
                    	t += i;
                    	t %= n;
                	}
                	if(bo == 1){
                   		printf("YES\n");
                    	return 0;
                	}
            	}
        	}
        	if(i > 2){
        	    for(int j = 0; j < n / i; j++){
            	    if(a[j] == 0) continue;
           	     	t = j + n / i; t %= n;
           	     	bo = 1;
           	     	while(t != j){
                    	if(a[t] == 0){
                    	    bo = 0;
                        	break;
                    	}
                    	t += n / i;
                    	t %= n;
                	}
                	if(bo == 1){
                   		printf("YES\n");
                    	return 0;
                	}
            	}
        	}
        }	
    printf("NO\n");
    return 0;
}

