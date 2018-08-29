#include <bits/stdc++.h>
using namespace std;
const int MOD = 100000000;
long long n, Cat[1010];
int main() {
    memset(Cat, 0, sizeof(Cat));
    cin >> n;
    Cat[0] = 1;
    Cat[1] = 1;
    Cat[2] = 2;
    Cat[3] = 5;
    for(long long i = 4; i <= n; i++) {
        for(long long j = 0; j < i; j++)
            Cat[i] = (Cat[i] + Cat[j] * Cat[i - j - 1] % MOD) % MOD;
    }
    cout << Cat[n] << endl;
    return 0;
}
