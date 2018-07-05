//XJOI 1139
#include<bits/stdc++.h>
using namespace std;
int main(){
    char ch = getchar();
    for(int i = 'A'; i <= ch; i++){
        for(int j = 1; j <= ch - i; j++)
         printf(" ");
        for(int j = 'A'; j <= i; j++)
         printf("%c", j);
        for(int j = i - 1; j >= 'A'; j--)
         printf("%c", j);
        printf("\n");
    }
    return 0;
}