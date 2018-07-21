#include<cstdio>
using namespace std;
double f[100010];
int main(){
    f[1] = 0;
    for(int i = 2; i <= 100000; i++){
        double sum = 0;
        int cnt = 0;
        for(int j = 1; j * j <= i; ++j){
            if(i % j != 0) continue;
            int x = j, y = i / j;
            sum += f[x];
            ++cnt;
            if(x != y && y != i){
                sum += f[y];
                ++cnt;
            }
        }
        ++cnt;
//        printf("%d %d %.2lf %.2lf\n", i, cnt, (double)(cnt / (double)(cnt - 1)), sum);
        f[i] = (double)(cnt / (double)(cnt - 1)) * ((double)sum / (double)(cnt) + 1);
    }
//    for(int i = 1; i <= 10; i++) printf("%.8lf\n", f[i]);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        printf("Case %d: %.8lf\n", i, f[x]);
    }
    return 0;
}
