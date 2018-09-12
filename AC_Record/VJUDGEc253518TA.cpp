/*
 * It's f**king TLE
 *
 * x+y=a, x*y=k*b
 * (x+y)^2=x^2+y^2+2*x*y=a^2
 * (x-y)^2=x^2+y^2-2*x*y=(x+y)^2-4*x*y=a^2-4*k*b
 * x+y=a, x-y=sqrt(a^2-4*k*b)
 * c=sqrt(a^2-4*k*b)
 * x=0.5*(a+c), y=0.5*(a-c)
 * No Solution : a^2-4*k*b<0, a^2-4*k*b!=t^2, a!=c(mod 2)
 *
 * But, K=??????!!!!!!
 *
 * F**K
 *
 * k=gcd(x,y)
 * x=k*x1, y=k*y1, b=x1*y1*k, a=k*(x1+y1) (gcd(x1,y1)=1)
 * k=gcd(a,b)
 *
 * Ohhhhh! That's GOOD;
 */
#include <cstdio>
#include <cmath>

long long gcd( long long x, long long y ) {
    long long m = x % y;
    while( m ) {
        x = y; y = m; m = x % y;
    }
    return y;
}

long long a, b, c, k, delta;

int main() {
    while( scanf( "%lld%lld", &a, &b ) == 2 ) {
        k = gcd( a, b );
        delta = a * a - 4 * k * b;
        if( delta < 0 ) {
            printf( "No Solution\n" );
            continue;
        }
        c = sqrt( delta );
        if( c * c != delta ) {
            printf( "No Solution\n" );
            continue;
        }
        if( ( a + c ) % 2 != 0 ) {
            printf( "No Solution\n" );
            continue;
        }
        printf( "%lld %lld\n", ( a - c ) / 2, ( a + c ) / 2 );
    }
    return 0;
}
