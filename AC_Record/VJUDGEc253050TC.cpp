#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct node {
    long long x, y;
    node( long long x_ = 0, long long y_ = 0 ) { x = x_; y = y_; return; }
};
node Node[ 100010 ];
long long n, x;
struct comperation {
    bool operator () ( pair< int, long long > x, pair< int, long long > y ) {
        return x.first > y.first || x.first == y.first && x.second < y.second;
    }
};
priority_queue< pair< int, long long >, vector< pair< int, long long > >, comperation > PQ;

void Work() {
    scanf( "%lld", &n );
    while( !PQ.empty() ) PQ.pop();
    long long ans = 0, num = 0;
    for( long long i = 1; i <= n; ++i ) {
        scanf( "%lld", &x );
        if( !PQ.empty() && PQ.top().first < x ) {
            ++num;
            ans += x - PQ.top().first;
            if( PQ.top().second == 1 ) --num; else ++num;
            PQ.pop();
            PQ.push( pair< int, long long >( x, 1 ) );
            PQ.push( pair< int, long long >( x, 0 ) );
        } else PQ.push( pair< int, long long >( x, 0 ) );
    }
    printf( "%lld %lld\n", ans, num );
    return;
}

int main() {
    long long t;
    scanf( "%lld", &t );
    for( long long i = 1; i <= t; ++i ) Work();
    return 0;
}

