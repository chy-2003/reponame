//XJOI 3538
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(a > c) swap(a, c);
    if(b > c) swap(a, c);
    if(a * a + b * b == c * c) printf("yes"); else printf("no");
    return 0;
}