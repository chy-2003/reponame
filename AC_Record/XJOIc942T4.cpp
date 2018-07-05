#include<bits/stdc++.h>
using namespace std;
int n, k, a1, a2;
int main(){
    cin >> n >> k;
    a1 = 0;
    for(int i = 2; i <= n; i++){
        a2 = (a1 + k) % i;
        a1 = a2;
    }
    printf("%d", a1 + 1);
    return 0;
}
