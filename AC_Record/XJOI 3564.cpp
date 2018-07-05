//XJOI 3564
#include<bits/stdc++.h>
using namespace std;
int n, a[110], sum;
double aver;
int main(){
    while(scanf("%d", &n) == 1){
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sum = 0;
        for(int i = 1; i <= n; i++) sum += a[i];
        aver = (double)sum / n;
        for(int i = 1; i <= n; i++)
         if(a[i] < aver) printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}