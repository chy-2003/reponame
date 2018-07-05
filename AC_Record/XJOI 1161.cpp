//XJOI 1161
#include<bits/stdc++.h>
using namespace std;
int n;
string a[1010];
bool cmp(string s1, string s2){
    int l = min(s1.size(), s2.size());
    for(int i = 0; i < l; i++){
        if(s1[i] < s2[i]) return true;
        if(s1[i] > s2[i]) return false;
    }
    if(s1.size() > l) return false;
    if(s2.size() > l) return true;
    return false;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++) cout << a[i] << endl;
    return 0;
}