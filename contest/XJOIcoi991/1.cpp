#include <bits/stdc++.h>
using namespace std;
char ch1[200010], ch2[30];
int b, a;
void p(int x) {
    if(x / 2 > 0) p(x / 2);
    printf("%d", x % 2);
    return;
}
int main() {
    scanf("%s", ch1 + 1);
    scanf("%s", ch2 + 1);
    int l = strlen(ch1 + 1);
    b = 0;
    for(int i = 1; i <= strlen(ch2 + 1); i++) b = b * 2 + ch2[i] - '0';
    a = 0;
    for(int i = 1; i <= l; i++) {
        a = a * 2 + ch1[i] - '0';
        a %= b;
    }
    p(a);
    printf("\n");
    return 0;
}
