#include<bits/stdc++.h>
using namespace std;
int n, a, b, f[1000010], x, y, rec[1000010];
stringstream Sin;
string s;
int main(){
    getline(cin, s);
    Sin << s;
    Sin >> n >> a >> b;
    while(getline(cin, s)){
        Sin.clear();
        Sin.str("");
        Sin << s;
        Sin >> x;
        while(Sin >> y) {
            f[y] = x;
        }
    }
    while(a) { rec[a] = 1; a = f[a]; }
    while(b) { if(rec[b] == 1) { printf("%d\n", b); return 0; } b = f[b]; }
    return 0;
}

