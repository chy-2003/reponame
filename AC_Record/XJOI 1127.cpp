//XJOI 1127
#include<bits/stdc++.h>
using namespace std;
int sqr(int x){
    return x * x;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 100; i <= n; i++)
     if(sqr(i / 100 + i % 100) == i) printf("%d\n", i);
    return 0;
}