//XJOI 3317
#include <bits/stdc++.h>
using namespace std;
int l, i, fail;
string s;
string st[1010];
int main()
{
    l = 1;
    i = 1;
    st[1] = "http://www.hzxjhs.com/";
    cin >> s;
    while(s != "QUIT"){
        fail = 0;
        if(s == "VISIT"){
            cin >> s;
            l = i;
            l++;
            i = l;
            st[l] = s;
        } else
        if(s == "BACK"){
            if(i == 1){
                printf("Ignored\n");
                fail = 1;
            } else
            i--;
        } else
        if(s == "FORWARD"){
            if(i == l){
                printf("Ignored\n");
                fail = 1;
            } else
            i++;
        }
        if(fail == 0)
        cout << st[i] << endl;
        cin >> s;
    }
    return 0;
}