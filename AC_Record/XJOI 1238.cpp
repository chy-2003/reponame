//XJOI 1238
#include<bits/stdc++.h>
using namespace std;
long long l, r, k;
    int b = 0;
void work(long long tt){
    if(tt >= l){
        if(b == 0) b = 1;
        work(tt / k);
        printf("%lld ", tt);
    }
    return;
}
int main(){
    scanf("%lld%lld%lld", &l, &r, &k);
    long long t = (int)(log10(r) / log10(k));
    long long tt = 1;
    for(int i = 1; i <= t; i++) tt *= k;
    work(tt);
    if(b == 0) printf("-1");
    return 0;
}