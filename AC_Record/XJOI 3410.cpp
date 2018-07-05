//XJOI 3410
#include<bits/stdc++.h>
using namespace std;
long long n, l1, l2, t;
int main(){
    cin >> n;
    l1 = (int)floor(sqrt(n));
    if(l1 * l1 >= n) l1--;
    l2 = l1 + 1;
    t = (l1 * l1 + l2 * l2 + 1) / 2;
    if(l2 % 2 == 1){
        if(n <= t) printf("%d %d", l2, n - l1 * l1);
        else printf("%d %d", l2 * l2 - n + 1, l2);
    } else{
        if(n <= t) printf("%d %d", n - l1 * l1, l2);
        else printf("%d %d", l2, l2 * l2 - n + 1);
    }
    return 0;
}