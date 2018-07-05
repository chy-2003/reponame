//XJOI 3285
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int a[1010], l;
};
int n;
Node a1, a2, a3;
int main(){
    scanf("%d", &n);
    if(n == 1){
        printf("1");
        return 0;
    }
    if(n == 2){
        printf("1");
        return 0;
    }
    a1.l = 1;
    a1.a[1] = 1;
    a2.l = 1;
    a2.a[1] = 1;
    for(int i = 3; i <= n; i++){
        a3.l = max(a1.l, a2.l);
        for(int j = 1; j <= a3.l; j++)
         a3.a[j] = a2.a[j] + a1.a[j];
        for(int j = 1; j <= a3.l; j++){
            a3.a[j + 1] += a3.a[j] / 10;
            a3.a[j] %= 10;
        }
        if(a3.a[a3.l + 1] > 0) a3.l++;
        a1 = a2; a2 = a3;
    }
    for(int i = a2.l; i >= 1; i--) cout << a2.a[i];
    return 0;
}