//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class MegaFactorialDiv2 {
public:
    int countDivisors( int N, int K );
};
const int MOD = 1000000009;
int f[1010][110], cnt[1010];
int MegaFactorialDiv2::countDivisors(int N, int K) {
    memset(f, 0, sizeof(f));
    f[N][K] = 1;
    for(int i = 0; i <= N + K; i++) 
        for(int j = 0; j <= K && j <= i; j++) {
            int x = N - (i - j);
            int y = K - j;
            if(x <= 0 || y <= 0) continue;
//            printf("%d %d %d\n", x, y, f[x][y]);
            if(x - 1 >= 0) f[x - 1][y] = (f[x - 1][y] + f[x][y]) % MOD;
            if(y - 1 >= 0) f[x][y - 1] = (f[x][y - 1] + f[x][y]) % MOD;
 //           printf("%d %d %d\n%d %d %d\n\n", x - 1, y, f[x - 1][y], x, y - 1, f[x][y - 1]);
        }
//    for(int i = 1; i <= N; i++) printf("%d ", f[i][0]);
//    printf("\n");
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= N; i++) {
        int t = i;
        for(int j = 2; j * j <= t; j++)
            while(t % j == 0) {
                t /= j;
                cnt[j] = (cnt[j] + f[i][0]) % MOD;
            }
        if(t) cnt[t] = (cnt[t] + f[i][0]) % MOD;
    }
    int ans = 1;
    for(int i = 2; i <= 1000; i++) 
        ans = (1LL * ans * (cnt[i] + 1)) % MOD;
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
			int K                     = 1;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = MegaFactorialDiv2().countDivisors( N, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 3;
			int K                     = 2;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = MegaFactorialDiv2().countDivisors( N, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 4;
			int K                     = 2;
			int expected__            = 18;

			clock_t start__           = clock();
			int received__            = MegaFactorialDiv2().countDivisors( N, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 6;
			int K                     = 3;
			int expected__            = 1392;

			clock_t start__           = clock();
			int received__            = MegaFactorialDiv2().countDivisors( N, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int N                     = 100;
			int K                     = 2;
			int expected__            = 321266186;

			clock_t start__           = clock();
			int received__            = MegaFactorialDiv2().countDivisors( N, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MegaFactorialDiv2().countDivisors( N, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MegaFactorialDiv2().countDivisors( N, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MegaFactorialDiv2().countDivisors( N, K );
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
