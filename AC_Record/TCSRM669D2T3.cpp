//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class LineMSTDiv2 {
public:
    int count( int N );
};
long long MOD = 1000000007;
long long power(long long x){
	if(x == 0) return 1;
	long long t = power(x / 2);
	t = (t * t) % MOD;
	if(x % 2 == 1) t = (t * 2) % MOD;
	return t;
}
long long doit(long long x, long long num){
//	printf("%lld %lld\n", x, num);
	if(x == 0) return 1;
	if(x == 1){
		long long t = ((num + 1) * num / 2 - num) % MOD;
//		printf("%lld\n", t);
		return power(t);
	}
}
int LineMSTDiv2::count(int N) {
	long long n = N - 1;
    long long ans = 1;
	for(long long i = 3; i <= N; i++) ans = (ans * i) % MOD;
//	printf("%lld\n", ans);
	long long sum = 0;
	for(long long i = 0; i < (1 << n); i++){
//		puts("");
		long long la = i & 1, cnt = 1;
		long long tt = 1;
		for(long long j = 1; j < n; j++){
			long long t = (i >> j) & 1;
			if(t == la) cnt = (cnt + 1) % MOD; else tt = (tt * doit(la, cnt)) % MOD, cnt = 1, la = t;
		}
		tt = (tt * doit(la, cnt)) % MOD;
//		printf("%lld %lld\n", i, tt);
		sum = (sum + tt) % MOD;
	}
//	printf("%lld\n",sum);
	ans = (ans * sum) % MOD;
	return ans;
}

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if ( casenum != -1 ) {
			if ( run_test_case( casenum ) == -1 && !quiet )
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			return;
		}
		
		int correct = 0, total = 0;
		for ( int i=0;; ++i ) {
			int x = run_test_case(i);
			if ( x == -1 ) {
				if ( i >= 100 ) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if ( total == 0 ) {
			cerr << "No test cases run." << endl;
		} else if ( correct < total ) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( expected == received ) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int N                     = 3;
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = LineMSTDiv2().count( N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = LineMSTDiv2().count( N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 16;
			int expected__            = 682141922;

			clock_t start__           = clock();
			int received__            = LineMSTDiv2().count( N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 3: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LineMSTDiv2().count( N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 4: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LineMSTDiv2().count( N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LineMSTDiv2().count( N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
		default:
			return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
