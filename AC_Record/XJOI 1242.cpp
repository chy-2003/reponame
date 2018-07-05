//XJOI 1242
#include<bits/stdc++.h>
using namespace std;
int a[2010], l1 = 0;
int l2 = 0;
struct Node{
    int left, right;
};
Node rec[4000010];
int l, r;
char ch;
bool cmp(Node x, Node y){
    return x.left < y.left || (x.left == y.left && x.right < y.right);
}
int find_(int l, int r, int x){
    int mid;
    while(l < r){
        mid = (l + r) / 2;
        if(rec[mid].left <= x) l = mid + 1; else r = mid;
    }
    return l;
}
int main(){
    char ch = getchar();
    while(ch >= 'a' && ch <= 'z'){
        l1++;
        a[l1] = ch - 'a' + 1;
        ch = getchar();
    }
    for(int i = 1; i <= l1; i++){
        l = i;
        r = i;
        while(l > 0 && r <= l1 && a[l] == a[r]){
            l2++;
            rec[l2].left = l;
            rec[l2].right = r;
            l--; r++;
        }
    }
    for(int i = 1; i < l1; i++){
        l = i;
        r = i + 1;
        while(l > 0 && r <= l1 && a[l] == a[r]){
            l2++;
            rec[l2].left = l;
            rec[l2].right = r;
            l--; r++;
        }
    }
    sort(rec + 1, rec + l2 + 1, cmp);
    int t;
    long long ans = 0;
    rec[0].left = 0;
    rec[l2 + 1].left = 2010;
    for(int i = 1; i < l2; i++){
        if(rec[i].left == rec[i - 1].left)
         t = find_(t, l2 + 1, rec[i].right);
        else
        t = find_(i + 1, l2 + 1, rec[i].right);
        ans += l2 - t + 1;
    }
    printf("%lld", ans);
    return 0;
}