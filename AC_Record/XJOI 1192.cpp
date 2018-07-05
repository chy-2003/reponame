//XJOI 1192
#include<bits/stdc++.h>
using namespace std;
int main(){
    int le = 0, di = 0, o = 0;
    char ch = getchar();
    while(ch != '?'){
        if((ch >= 'A') && (ch <= 'Z') || (ch >= 'a') && (ch <= 'z'))
         le++; else
        if((ch >= '1') && (ch <= '9')) di++; else o++;
        ch = getchar();
    }
    printf("Letters=%d\nDigits=%d\nOthers=%d\n", le, di, o);
    return 0;
}