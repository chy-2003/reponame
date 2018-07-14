#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int n, a[30][30], cnt[30], ans[30], t, l, finished;
int main(){
    cin >> n;
    cin >> s1;
    for(int i = 2; i <= n; i++){
        cin >> s2;

        finished = 0;
        l = min(s1.size(), s2.size());
        for(int j = 0; j < l; j++)
            if(s1[j] != s2[j]){
                finished = 1;
                a[s1[j] - 'a'][s2[j] - 'a']++;
                cnt[s2[j] - 'a']++;
                break;
            }
        if(finished == 0 && s1.size() > s2.size()){
            printf("Impossible\n");
            return 0;
        }

        s1 = s2;
    }

    for(int i = 1; i <= 26; i++){
        t = -1;
        for(int j = 0; j < 26; j++)
            if(cnt[j] == 0){
                cnt[j] = -1;
                t = j;
                break;
            }
        if(t == -1){
            printf("Impossible\n");
            return 0;
        }
        ans[i] = t;
        for(int j = 0; j < 26; j++)
            if(a[t][j])
                cnt[j] -= a[t][j];
    }
    for(int i = 1; i <= 26; i++) printf("%c", ans[i] + 'a'); printf("\n");
    return 0;
}
