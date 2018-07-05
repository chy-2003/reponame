//XJOI 3279
#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int l1, l2, a[1010], b[1010];
int main(){
    cin >> s1 >> s2;
    l1 = s1.size();
    l2 = s2.size();
    for(int i = l1; i >= 1; i--) a[i] = s1[l1 - i] - '0';
    for(int i = l2; i >= 1; i--) b[i] = s2[l2 - i] - '0';
    if(l2 > l1) l1 = l2;
    for(int i = 1; i <= l1; i++) a[i] += b[i];
    for(int i = 1; i <= l1; i++){
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    if(a[l1 + 1] > 0) l1++;
    for(int i = l1; i >= 1; i--) cout << a[i];
    return 0;
}