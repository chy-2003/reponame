//XJOI 1216
#include<bits/stdc++.h>
using namespace std;
int n, m;
struct Node{
    string s1, s2, s3, s4, s5, s6;
};
string s;
Node po[110];
int fin;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
     cin >> po[i].s1 >> po[i].s2 >> po[i].s3 >> po[i].s4 >> po[i].s5 >> po[i].s6;
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> s;
        fin = 0;
        for(int j = 1; j <= n; j++)
         if(po[j].s1 == s){
            fin = 1;
            cout << po[j].s1 << " " << po[j].s2 << " " << po[j].s3 << " " <<
                    po[j].s4 << " " << po[j].s5 << " " << po[j].s6 << endl;
                    break;
         }
        if(fin == 0){
            cout << "not found" << endl;
        }
    }
    return 0;
}