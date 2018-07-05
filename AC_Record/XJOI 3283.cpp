//XJOI 3283
//XJOI 3284
#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int l1, l2, a[1010], b[1010], c[1010], l3;
int bigger(int x){
    int l = l1 - x + 1;
    if(l > l2) return 1;
    if(l < l2) return 0;
    for(int i = l; i >= 1; i--){
        if(a[x + i - 1] > b[i]) return 1;
        if(a[x + i - 1] < b[i]) return 0;
    }
    return 1;
}
void dec(int x){
    for(int i = x; i <= l1; i++){
        if(a[i] < b[i - x + 1]){
            a[i] += 10;
            a[i + 1]--;
        }
        a[i] -= b[i - x + 1];
    }
    while(l1 > 1 && a[l1] == 0) l1--;
    return;
}
int main(){
    cin >> s1 >> s2;
//	cout << s1 << endl << s2 << endl;
    l1 = s1.size(); l2 = s2.size();
    l3 = l1;
    for(int i = 0; i < l1; i++)
        a[i + 1] = s1[l1 - i - 1] - '0';
    for(int i = 0; i < l2; i++)
        b[i + 1] = s2[l2 - i - 1] - '0';
    for(int i = l1; i >= 1; i--)
        while(bigger(i)){
            c[i]++;
            dec(i);
        }
    while(l3 > 1 && c[l3] == 0) l3--;
    for(int i = l3; i >= 1; i--) printf("%d", c[i]);
    printf("\n");
    for(int i = l1; i >= 1; i--) printf("%d", a[i]);
    return 0;
}