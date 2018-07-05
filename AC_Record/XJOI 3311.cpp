#include<bits/stdc++.h>
using namespace std;
int n, cnt = 0;
string s, ans;
int cnt1(){
    int t = 0;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '1') t++; else if(s[i] != '0') return 0;
    return t;
}
int cnt2(){
    return s.size() - 1;
}
int main(){
    scanf("%d", &n);
    ans = "0";
    for(int i = 1; i <= n; i++){
        cin >> s;
        if(s == "0"){
        	printf("0");
        	return 0;
        }
        if(cnt1() == 1) cnt += cnt2(); else ans = s;
    }
    if(ans != "0")
    cout << ans;
    else printf("1");
    for(int i = 1; i <= cnt; i++) printf("0");
    return 0;
}
