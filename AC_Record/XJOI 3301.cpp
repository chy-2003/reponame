//XJOI 3301
#include<cstdio>
#include<cstring>
#include<algorithm>
int a, b, c, mem[10][100010], i, t;
int main(){
    scanf("%d%d%d", &a, &b, &c);
    a %= b;
    t = 0;
    memset(mem, 0, sizeof(mem));
    i = 0;
    while(1){
        a *= 10;
        t = a / b;
        a %= b;
        i++;
        if(t == c){
            printf("%d", i);
            break;
        }
        if(mem[t][a] != 0) break;
        mem[t][a] = 1;
    }
    if(mem[t][a] != 0) printf("-1");
    return 0;
}