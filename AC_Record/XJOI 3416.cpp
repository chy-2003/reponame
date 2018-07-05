//XJOI 3416
#include<bits/stdc++.h>
using namespace std;
long long q, l, r, mid;
long long count(long long x){
    long long cnt = 0;
    while(x){
        x /= 5;
        cnt += x;
    }
    return cnt;
}
int main(){
    cin >> q;
    l = 1;
    r = 1000000000000000000;
    while(l < r){
        mid = (l + r) / 2;
        if(count(mid) >= q) r = mid; else l = mid + 1;
    }
    if(count(l) == q) cout << l; else printf("impossible");
    return 0;
}