//XJOI 1199
#include<bits/stdc++.h>
using namespace std;
int get_int(){
    string c;
    getline(cin, c);
    int i = 0;
    int num = 0;
    while(c[i] < '0' || c[i] > '9') i++;
    while(c[i] >= '0' && c[i] <= '9'){
        num = num * 10 + c[i] - '0';
        i++;
    }
    return num;
}
int main(){
    int n;
    n = get_int();
    string s;
    int b;
    for(int i = 1; i <= n; i++){
        getline(cin, s);
        b = 1;
        if(s[0] == ' ' || s[s.size() - 1] == ' ') b = 0;
        if(b)
         for(int j = 0; j < s.size(); j++){
    //      cout << s[j] << endl;
          if(s[j] == 'O'){
            b = 0;
            break;
          } else
          if(s[j] == 'o'){
            if(s[j + 1] == 'i' && s[j + 2] == 'e' && s[j + 3] == 'r')
             j += 3;
            else{
                b = 0;
                break;
            }
          } else
        if(s[j] == ' '){
            if(!(s[j + 1] == 'o')){
                b = 0;
                break;
            }
        } else{
            b = 0;
            break;
        }
        }
        if(b) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}