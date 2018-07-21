#include<bits/stdc++.h>
using namespace std;
double p[20], A[520], B[520];
int n, k1, k2, k3, a, b, c;
void work(){
    scanf("%d%d%d%d%d%d%d", &n, &k1, &k2, &k3, &a, &b, &c);
    memset(p, 0, sizeof(p));
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    for(int i = 1; i <= k1; i++)
        for(int j = 1; j <= k2; j++)
            for(int k = 1; k <= k3; k++)
                if(!(i == a && j == b && k == c))
                    ++p[i + j + k];
    p[0] = 1;
    for(int i = 0; i <= k1 + k2 + k3; i++) p[i] = p[i] / (double)(k1 * k2 * k3);
    for(int i = n; i >= 0; i--){
        A[i] = p[0];
        B[i] = 1;
        for(int j = 3; j <= k1 + k2 + k3; j++){
            A[i] += p[j] * A[i + j];
            B[i] += p[j] * B[i + j];
        }
    }
    double ans = B[0] / (1.0 - A[0]);
    printf("%.15lf\n", ans);
    return;
}
int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) work();
    return 0;
}

