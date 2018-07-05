//XJOI 1359
#include<bits/stdc++.h>
using namespace std;
int n, m, t;
string s;
void p(int x){
    if(x / m != 0) p(x / m);
    int y = x % m;
    if(y >= 10) printf("%c", y - 10 + 'A'); else
    printf("%d", y);
    return;
}