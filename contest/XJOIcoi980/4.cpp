/*
H(i) = (H(i-1)+H(i+1))/2 - k
2H(i) = H(i-1)+H(i+1) - 2 * k
H(i+1) = 2H(i) - H(i - 1) + 2 * k
 
H(i+2) = 2H(i + 1) - H(i) + 2 * k
H(i+2) = 4H(i) - 2H(i-1) + 4 * k - H(i) + 2 * k
 = 3H(i) - 2H(i-1) + 6 * k
  
H(i+3) = 2H(i+2) - H(i+1) + 2 * k
H(i+3) = 6H(i) - 4H(i-1) + 12 * k - 2H(i) + H(i-1) - 2 * k + 2 * k
 = 4H(i) - 3H(i-1) + 12 * k
  
H(1)  = A
H(N) = B
 
prove : H(i+t) = (t+1)H(i) - tH(i-1) + (t + 1)t*k
 
H(i+t+1) = 2H(i+t) - H(i+t-1) + 2 * k
    = 2(t+1)H(i) - 2tH(i-1) + 2(t+1)t * k - tH(i) + (t-1)H(i-1) - t(t-1)*k + 2*k
    = (t+1)H(i) - (t+1)H(i-1) + (t+2)(t+1) * k
     
Q.E.D
 
i = 2
H(t+2) = (t+1)H(2) - tH(1) + (t+1)tk
    = (t+1)H(2) - tA + (t+1)tk
 
check1 :
H(1) = 1, H(2) = 1, k = 1
(t = 0) H(2) = 1 = H(2)
(t = 1) H(3) = 3 = 2H(2) - H(1) + 2 * k = 2 - 1 + 2 = 3
(t = 2) H(4) = 7 = 3H(2) - 2H(1) + 3 * 2 * k = 3 - 2 + 6 = 7
check2 :
H(1) = 1, H(2) = 2, k = 3
(t = 0) H(2) = 2 = H(2)
(t = 1) H(3) = 9 = 2H(2) - H(1) + 2 * k = 4 - 1 + 6 = 9
(t = 2) H(4) = 22 = 3H(2) - H(1) + 3 * 2 * k = 6 - 2 + 6 * 3 = 22
 
__OK
 
H(i) = h
t = i - 2
H(i - 2 + 2) = (i-1)H(2) - (i-2)A + (i-1)(i-2)k
(i-1)H(2) = H(i) + (i-2)A - (i-1)(i-2)k
H(2) = (H(i) + (i-2)A - (i-1)(i-2) k) / (i-1)
 
t = N - 2
B = H(N) = H(N-2 + 2) = (N-1)H(2) - (N-2)A + (N-1)(N-2)k
*/
#include <cstdio>
int n;
double A, h, k, ans;
inline double max(double x, double y) { return (x > y) ? x : y; }
int main() {
    scanf("%d%lf%lf%lf", &n, &A, &h, &k);
    ans = 0;
    for(int i = 2; i <= n; i++) {
        double h2 = (double)(h + (i - 2) * A - (double)(i - 1) * (i - 2) * k) / (double)(i - 1);
        ans = max(ans, (n - 1) * h2 - (n - 2) * A + (double)(n - 1) * (n - 2) * k);
    }
    printf("%.2lf\n", ans);
    return 0;
}
