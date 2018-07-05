//XJOI 1232
#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    int n;
    scanf("%d", &n);
    if(n == 0){
        printf("0");
        return 0;
    }
    if(n == 1){
        printf("2");
        return 0;
    }
    int a1 = 1, a2 = 2, a3;
    a[a1]++;
    a[a2]++;
    for(int i = 2; i < n; i++){
        a3 = (a1 + a2) % 1000000;
        a1 = a2; a2 = a3;
        a[a3]++;
    }
    int sum = 0;
    int j = 0;
    for(int i = 0; i < 1000000; i++){
        while(a[i]){
            sum += (1LL * j * i) % 1000000;
            j++;
            a[i]--;
            if(sum >= 1000000) sum -= 1000000;
        }
    }
    printf("%d", sum);
    return 0;
}