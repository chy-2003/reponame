#include <bits/stdc++.h>
using namespace std;
long long Cat[30];
void init() {
    Cat[0] = 1;
    Cat[1] = 1;
    Cat[2] = 2;
    Cat[3] = 5;
    for(int i = 4; i <= 23; i++) 
        for(int j = 0; j < i; j++) 
            Cat[i] += Cat[j] * Cat[i - j - 1];
    return;
}
void pr(int num, int n) {
//    printf("[%d, %d]", num, n);
    long long t = 0;
    for(int i = 0; i < num; i++) {
        t += Cat[i] * Cat[num - i - 1];
        if(t >= n) {
            t -=  Cat[i] * Cat[num - i - 1];
            t = n - t;
            if(i > 0) {
                printf("(");
                pr(i, (t + Cat[num - i - 1] - 1) / Cat[num - i - 1]);
                printf(")");
            }
            printf("X");
            if(i < num - 1) {
                printf("(");
                pr(num - i - 1, (t - 1) % Cat[num - i - 1] + 1);
                printf(")");
            }
            return;
        }
    }
    return;
}
void work(int n) {
    long long t = 0;
    for(int i = 1; i <= 23; i++) {
        t += Cat[i];
        if(t >= n) {
            pr(i, n - (t - Cat[i]));
            return;
        }
    }
    return;
}
int main() {
    init();
    int n;
    scanf("%d", &n);
    while(n) {
        work(n);
        printf("\n");
        scanf("%d", &n);
    } 
    return 0;
}
