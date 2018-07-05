//XJOI 1230
#include<bits/stdc++.h>
using namespace std;
int n, a[1010], b[1010];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(b, 0, sizeof(b));
    int l = 0;
    for(int i = 1; i <= n; i++){
        l++;
        int id = l;
        while(id > 1 && b[id - 1] > a[i]){
            id--;
            swap(b[id], b[id + 1]);
        }
        b[id] = a[i];
    }
    for(int i = 1; i <= n; i++) printf("%d ", b[i]);
    return 0;
}