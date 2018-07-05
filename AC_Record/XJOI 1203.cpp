//XJOI 1203
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++)
     if(s[i] == ' ') printf(" ");
     else printf("%c", (s[i] - 'a' + 1) % 26 + 'a');
    return 0;
}