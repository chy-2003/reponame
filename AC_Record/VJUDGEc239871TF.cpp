#include<bits/stdc++.h>
using namespace std;
int w, b;
double f[1010][1010];
int main(){
    scanf("%d%d", &w, &b);
    for(int i = 1; i <= w; i++) f[i][0] = 1;
    for(int i = 1; i <= b; i++) f[0][i] = 0;
    for(int i = 1; i <= w; i++)
        for(int j = 1; j <= b; j++){
            f[i][j] += (double) i / (double)(i + j);
            if(j >= 2) 
                f[i][j] += f[i - 1][j - 2] * (double) j / (double)(i + j) * (double)(j - 1) / (double)(i + j - 1) * (double)i / (double)(i + j - 2);
            if(j >= 3) 
                f[i][j] += f[i][j - 3] * (double) j / (double)(i + j) * (double)(j - 1) / (double)(i + j - 1) * (double)(j - 2) / (double)(i + j - 2);
        }
    printf("%.10lf\n", f[w][b]);
    return 0;
}

