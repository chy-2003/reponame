//XJOI 3432
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int sum = 1;
    for(int i = 2; i < n; i++) sum *= i;
    printf("%d", sum);
    return 0;
}