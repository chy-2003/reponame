//XJOI 1145
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a = 0, b = 0, c = 0, tot = 0;
    int t;
    scanf("%d", &t);
    while(t != -1){
        if(t == 1) a++;
        if(t == 2) b++;
        if(t == 3) c++;
        if(t == 1 || t == 2 || t == 3) tot++;
        scanf("%d", &t);
    }
    printf("A=%d\nB=%d\nC=%d\nTot=%d\n", a, b, c, tot);
    if(a >= tot / 2) printf("A-yes"); else
    if(b >= tot / 2) printf("B-yes"); else
    if(c >= tot / 2) printf("C-yes"); else
    printf("all-NO");
    return 0;
}