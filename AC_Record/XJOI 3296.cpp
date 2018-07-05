//XJOI 3296
#include<bits/stdc++.h>
using namespace std;
int a, b, t;
string s;
void work(int x){
    if(x / b != 0) work(x / b);
    printf("%d", x % b);
}
int main(){
    cin >> a >> s >> b;
    t = 0;
    for(int i = 0; i < s.size(); i++){
        t = t * a + s[i] - '0';
    }
    work(t);
    printf("\n");
    return 0;
}