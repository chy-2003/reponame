//XJOI 1123
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a[20], t, l, b;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        t = i;
        memset(a, 0, sizeof(a));
        l = 0;
        while(t){
            l++;
            a[l] = t % 10;
            t /= 10;
        }
        b = 1;
        for(int j = 1; j * 2 <= l; j++)
         if(a[j] != a[l - j + 1])
          b = 0;
        if(b) printf("%d\n", i);
    }
    return 0;
}