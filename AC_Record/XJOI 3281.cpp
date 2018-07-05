//XJOI 3281
#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int l1, l2, a[1010], b[1010];
int l3, c[2010];
int main(){
    cin >> s1 >> s2;
    l1 = s1.size();
    l2 = s2.size();
    for(int i = l1; i >= 1; i--) a[i] = s1[l1 - i] - '0';
    for(int i = l2; i >= 1; i--) b[i] = s2[l2 - i] - '0';
    l3 = l1 + l2;
    for(int i = 1; i <= l1; i++)
     for(int j = 1; j <= l2; j++)
      c[i + j - 1] += a[i] * b[j];
    for(int i = 1; i <= l3; i++){
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    while(l3 > 1 && c[l3] == 0) l3--;
    for(int i = l3; i >= 1; i--) cout << c[i];
    return 0;
}