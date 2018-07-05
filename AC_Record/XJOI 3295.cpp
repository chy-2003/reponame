//XJOI 3295
#include<bits/stdc++.h>
using namespace std;
string s;
int l1, l2;
int main(){
    cin >> s;
    s = "a" + s + "a";
    l1 = 0; l2 = 0;
    for(int i = 0; i < s.size() - 1; i++)
     if(s[i] != 'a'){
        l1 = i;
        break;
     }
    if(l1 == 0){
        s[s.size() - 2] = 'z';
        for(int i = 1; i < s.size() - 1; i++) printf("%c", s[i]);
        return 0;
    }
    for(int i = l1; i < s.size() - 1; i++)
     if(s[i + 1] == 'a'){
        l2 = i;
        break;
     }
    for(int i = l1; i <= l2; i++) s[i] = s[i] - 1;
    for(int i = 1; i < s.size() - 1; i++) printf("%c", s[i]);
    return 0;
}