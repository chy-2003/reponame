//XJOI 2200
#include<bits/stdc++.h>
using namespace std;
struct Big_Num{
    int len, a[210];
};
void print_Big_Num(Big_Num x){
    for(int i = x.len; i >= 1; i--) printf("%d", x.a[i]);
    printf("\n");
    return;
}
Big_Num a, b, c;
Big_Num get_Big_Num(){
    Big_Num t;
    t.len = 0;
    memset(t.a, 0, sizeof(t.a));
    char ch = getchar();
    while((ch < '0') || (ch > '9')) ch = getchar();
    while((ch >= '0') && (ch <= '9')){
        t.len++;
        t.a[t.len] = ch - '0';
        ch = getchar();
    }
    for(int i = 1; i * 2 <= t.len; i++) swap(t.a[i], t.a[t.len - i + 1]);
    return t;
}
bool Doubled(Big_Num x){
    if(x.a[1] != 0 && x.a[1] % 2 == 0) return true;
    if(x.a[1] == 0 && x.len > 1) return true;
    return false;
}
Big_Num Double(Big_Num x){
    Big_Num t = x;
    for(int i = 1; i <= t.len; i++) t.a[i] *= 2;
    for(int i = 1; i <= t.len; i++){
        t.a[i + 1] += t.a[i] / 10;
        t.a[i] = t.a[i] % 10;
    }
    if(t.a[t.len + 1] > 0) t.len++;
    return t;
}
Big_Num Divide(Big_Num x){
    Big_Num t = x;
    for(int i = t.len; i >= 1; i--){
        t.a[i - 1] += t.a[i] % 2 * 10;
        t.a[i] /= 2;
    }
    if(t.len > 1 && t.a[t.len] == 0) t.len--;
    return t;
}
bool Bigger(Big_Num x, Big_Num y){
    if(x.len > y.len) return true;
    if(x.len < y.len) return false;
    for(int i = x.len; i >= 1; i--){
        if(x.a[i] > y.a[i]) return true;
        if(x.a[i] < y.a[i]) return false;
    }
    return true;
}
Big_Num dec(Big_Num x, Big_Num y){
    Big_Num t;
    t.len = x.len;
    memset(t.a, 0, sizeof(t.a));
    for(int i = 1; i <= x.len; i++){
        if(x.a[i] < y.a[i]){
            x.a[i] += 10;
            x.a[i + 1]--;
        }
        t.a[i] = x.a[i] - y.a[i];
    }
    while(t.len > 1 && t.a[t.len] == 0) t.len--;
    return t;
}
Big_Num Big_gcd(Big_Num x, Big_Num y){
    int i = 0, j = 0;
    while(Doubled(x)){
        i++;
        x = Divide(x);
    }
    while(Doubled(y)){
        j++;
        y = Divide(y);
    }
    i = min(i, j);
    Big_Num z;
    z.len = 0;
    memset(z.a, 0, sizeof(z.a));
    while(1){
        if(Bigger(y, x))
         swap(x, y);
        z = dec(x, y);
        x = z;
        if(z.len == 1 && z.a[1] == 0){
            while(i){
                i--;
                y = Double(y);
            }
            return y;
        }
        while(Doubled(x))
         x = Divide(x);
//      print_Big_Num(x);
//      print_Big_Num(y);
//      printf("\n");
    }
}
Big_Num muilti(Big_Num x, Big_Num y){
    Big_Num t;
    t.len = 0;
    memset(t.a, 0, sizeof(t.a));
    for(int i = 1; i <= x.len; i++)
     for(int j = 1; j <= y.len; j++)
      t.a[i + j - 1] += x.a[i] * y.a[j];
    t.len = x.len + y.len;
    for(int i = 1; i <= t.len; i++){
        t.a[i + 1] += t.a[i] / 10;
        t.a[i] %= 10;
    }
    while(t.len > 1 && t.a[t.len] == 0) t.len--;
    return t;
}
Big_Num division(Big_Num x, Big_Num y){
    Big_Num t, ans, o;
    t.len = 0; ans.len = 0;
    memset(t.a, 0, sizeof(t.a)); memset(ans.a, 0, sizeof(ans.a));
    for(int i = x.len; i >= 1; i--){
        t.len++;
        for(int j = t.len; j >= 1; j--)
         t.a[j] = t.a[j - 1];
        t.a[1] = x.a[i];
        while(t.len > 1 && t.a[t.len] == 0) t.len--;
        while(Bigger(t, y)){
            ans.a[i]++;
            t = dec(t, y);
        }
    }
    ans.len = x.len;
    while(ans.len > 1 && ans.a[ans.len] == 0) ans.len--;
    return ans;
}
int main(){
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    a = get_Big_Num();
//  print_Big_Num(a);
    b = get_Big_Num();
//  print_Big_Num(b);
    c = Big_gcd(a, b);
//  print_Big_Num(c);
    a = muilti(a, b);
//  print_Big_Num(a);
    a = division(a, c);
    print_Big_Num(a);
    return 0;
}