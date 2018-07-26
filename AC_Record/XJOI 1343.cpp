#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d", &n);
    printf("%d\n", (n + 6) / 7 + (n + 5) / 7 + (n + 4) / 7 + min(n / 7, 1));
    return 0;
}

