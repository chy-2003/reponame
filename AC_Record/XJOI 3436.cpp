//XJOI 3436
#include<bits/stdc++.h>
using namespace std;
int getint_(){
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    int num = 0;
    while(ch >= '0' && ch <= '9'){
        num = num * 10 + ch - '0';
        ch = getchar();
    }
    return num;
}
int getbit_(){
    char ch = getchar();
    while(ch != '0' && ch != '1') ch = getchar();
    return (ch == '0') ? 0 : 1;
}
int n, a[50];
int main(){
    n = getint_();
    for(int i = 1; i <= n; i++){
        a[i] = 0;
        for(int j = 1; j <= n; j++)
            if(getbit_() == 1) a[i] = j;
    }
    int ans = 0, t;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++)
            if(a[j] <= i){
                t = j; break;
            }
        for(int j = t; j > i; j--){
            swap(a[j], a[j - 1]);
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}