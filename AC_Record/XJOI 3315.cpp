//XJOI 3315
#include<bits/stdc++.h>
using namespace std;
string s;
int l, x, y;
char m[8][8];
int main(){
    for(int i = 0; i < 8; i++)
     for(int j = 0; j < 8; j++)
      if((i + j) % 2 == 0) m[i][j] = '.'; else m[i][j] = ':';
    cin >> s >> s;
    l = 0;
    while(l < s.size()){
        if(s[l] >= 'A' && s[l] <= 'Z'){
            x = 8 - (s[l + 2] - '0');
            y = s[l + 1] - 'a';
            m[x][y] = s[l];
            l += 4;
        } else{
            x = 8 - (s[l + 1] - '0');
            y = s[l] - 'a';
            m[x][y] = 'P';
            l += 3;
        }
    }
    cin >> s >> s;
    l = 0;
    while(l < s.size()){
        if(s[l] >= 'A' && s[l] <= 'Z'){
            x = 8 - (s[l + 2] - '0');
            y = s[l + 1] - 'a';
            m[x][y] = s[l] - 'A' + 'a';
            l += 4;
        } else{
            x = 8 - (s[l + 1] - '0');
            y = s[l] - 'a';
            m[x][y] = 'p';
            l += 3;
        }
    }
    for(int i = 0; i < 8; i++){
        printf("+---+---+---+---+---+---+---+---+\n");
        for(int j = 0; j < 8; j++){
            printf("|");
            if((i + j) % 2 == 0) printf("."); else printf(":");
            printf("%c", m[i][j]);
            if((i + j) % 2 == 0) printf("."); else printf(":");
        }
        printf("|\n");
    }
    printf("+---+---+---+---+---+---+---+---+\n");
    return 0;
}