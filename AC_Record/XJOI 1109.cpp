//XJOI 1109
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    if(n > 60){
        printf("NO");
        return 0;
    }
    if(n <= 30){
        printf("%.2f", (double)(n * 0.2));
        return 0;
    }
    printf("%.2f", (double)(30 * 0.2 + (n - 30) * 0.6));
    return 0;
}