#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define LL long long 
using namespace std;

const LL Mod = 1000000007;
LL n, t1, t2, t3, t4, t, tt;

int main() {
    cin >> n;
    n %= Mod;
//  5 * n * n * n * ( n * n - 1 ) / 3
    t1 = 5LL * n % Mod * n % Mod * n % Mod;
    t = 1LL  * n % Mod * n % Mod;
    t = ( ( t - 1 ) % Mod + Mod ) % Mod;
    t1 = t1 * t % Mod;
    t1 =  t1 * 333333336LL % Mod;

//  4 * n * n * n * ( 4 * n * n - 1 ) / 3
    t2 = 4LL * n % Mod * n % Mod * n % Mod;
    t = 4LL  * n % Mod * n % Mod;
    t = ( ( t - 1 ) % Mod + Mod ) % Mod;
    t2 = t2 * t % Mod;
    t2 = t2 * 333333336LL % Mod;

//  8 * n * n * n * n * n
    t3 = 8LL * n % Mod * n % Mod * n % Mod * n % Mod * n % Mod;

//  t1 = n * n * n * ( 4 * n * n - 1 ) / 3;
//  t1 += n * n * n * n * n;
//  t1 * 2
    tt = 1LL * n % Mod * n % Mod * n % Mod;
    t = 4LL  * n % Mod * n % Mod;
    t = ( ( t - 1 ) % Mod + Mod ) % Mod;
    tt = tt * t % Mod;
    tt = tt * 333333336LL % Mod;
    t = 1LL  * n % Mod * n % Mod * n % Mod * n % Mod * n % Mod;
    tt = ( tt + t ) % Mod;
    t4 = tt * 2 % Mod;

    t1 = ( t1 + t2 ) % Mod;
    t1 = ( t1 + t3 ) % Mod;
    t1 = ( t1 + t4 ) % Mod;
    cout << t1 << endl;
    return 0;
}
