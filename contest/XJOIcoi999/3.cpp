#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

string s;

int main() {
	cin >> s;
	int len = s.size();
	long long t = 0;
	long long ans = 1;
	for( int i = len - 1; i >= 0; --i ) {
		if( s[ i ] == ')' ) t++; else ans = ans * t % 1000000007, t--;
	}
	cout << ans << endl;
	return 0;
}
