//XJOI 3401
#include <bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
int l, ans = 0;
int num;
int cmp(char x, char y){
    if(x == '(' && y == ')') return 0;
    if(x == '[' && y == ']') return 0;
    if(x == '{' && y == '}') return 0;
    if(x == '<' && y == '>') return 0;
    return 1;
}
int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '[' || s[i] == '<' || s[i] == '{' || s[i] == '(') num++; else num--;
        if(num < 0){
            printf("Impossible");
            return 0;
        }
    }
    if(num > 0){
        printf("Impossible");
        return 0;
    }
    l = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '[' || s[i] == '<' || s[i] == '{' || s[i] == '('){
            l++; a[l] = s[i];
        } else{
            if(cmp(a[l], s[i])) ans++;
            l--;
        }
    }
    cout << ans;
    return 0;
}