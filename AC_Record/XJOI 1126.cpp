//XJOI 1126
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
     if(i % 3 == 2 && i % 5 == 3 && i % 7 == 2) printf("%d\n", i);
    return 0;
}