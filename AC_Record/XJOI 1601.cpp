//XJOI 1601
#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    int t = n / 2;
    int r, l, mid;
    for(int i = 1; i <= t; i++){
        r = n / i + 1;
        l = 1;
        while(l < r){
            mid = (l + r + 1) / 2;
            if((i + (i + mid - 1)) * mid / 2 > n) r = mid - 1;
            else l = mid;
        }
        if((i + (i + l - 1)) * l / 2 == n){
            if(i == 1){
                printf("0 %d\n", i + l - 1);
            }
            printf("%d %d\n", i, i + l - 1);
        }
    }
    return 0;
}