//XJOI 3300
#include<bits/stdc++.h>
using namespace std;
char s1[60], s2[60], ch;
int l1, l2;
bool cmp(char ch1, char ch2){
    return ch1 > ch2;
}
int main(){
    l1 = 0;
    ch = getchar();
    while(ch >= 'a' && ch <= 'z'){
        l1++;
        s1[l1] = ch;
        ch = getchar();
    }
    ch = getchar();
    while(ch >= 'a' && ch <= 'z'){
        l2++;
        s2[l2] = ch;
        ch = getchar();
    }
    sort(s2 + 1, s2 + l2 + 1, cmp);
    int lin = 1;
    for(int i = 1; i <= l1; i++){
        if(lin > l2) break;
        if(s1[i] < s2[lin]){
            s1[i] = s2[lin];
            lin++;
        }
    }
    for(int i = 1; i <= l1; i++) printf("%c", s1[i]);
    return 0;
}