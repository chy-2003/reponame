//XJOI 1322
#include<bits/stdc++.h>
using namespace std;
char ch, a[110];
int l, len;
int find(int l, int r, char ch){
    for(int i = l; i <= r; i++)
     if(a[i] == ch){
        return i;
     }
    return -1;
}
void work(int fl, int fr, int ml, int mr){
    if(fl > fr) return;
    int t = find(ml, mr, a[fl]);
    if(t == -1){
        printf("ERROR!");
        exit;
    }
    work(fl + 1, fl + t - ml, ml, t - 1);
    work(fl + t - ml + 1, fr, t + 1, mr);
    cout << a[t];
    return;
}
int main(){
    while(cin >> ch){
        l++;
        a[l] = ch;
    }
    len = l / 2;
    work(1, len, len + 1, l);
    return 0;
}