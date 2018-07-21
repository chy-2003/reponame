#include<cstdio>
int n, m;
double p;
double power(int x, double t){
    if(x == 0) return 1;
    double tt = power(x / 2, t);
    tt = tt * tt;
    if(x & 1) tt = tt * t;
    return tt;
}
int main(){
    scanf("%d%d", &n, &m);
    p = power(m, (double)((double)(n - 1) / (n)));
    p = (double)n - (double)(n) * p;
    printf("%.10lf\n", p);
    return 0;
}

