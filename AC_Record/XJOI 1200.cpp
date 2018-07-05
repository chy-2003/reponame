//XJOI 1200
#include<bits/stdc++.h>
using namespace std;
int a[30];
int main(){
    char ch;
    while(cin >> ch)
     if(ch >= 'a' && ch <= 'z') a[ch - 'a']++;
    for(int i = 0; i < 26; i++)
     if(a[i] != 0) printf("%c:%d\n", i + 'a', a[i]);
    return 0;
}