//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class PenguinEmperor {
public:
    int countJourneys( int numCities, long long daysPassed );
};
const long long mod = 1000000007;
long long dp[400][400];
long long one[400], zero[400], g[400];
int n;
void muilti(long long x) {
    while(x) {
        if(x & 1) {
            memset(g, 0, sizeof(g));
            for(int i = 0; i < n; i++) 
                for(int j = 0; j < n; j++) 
                    g[(i + j) % n] = (g[(i + j) % n] + one[i] * zero[j] % mod) % mod;
            for(int i = 0; i < n; i++) 
                zero[i] = g[i];
        }
        x >>= 1;
        memset(g, 0, sizeof(g));
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++) 
                g[(i + j) % n] = (g[(i + j) % n] + one[i] * one[j] % mod) % mod;
        for(int i = 0; i < n; i++) 
            one[i] = g[i];
    }
    return;
}
int PenguinEmperor::countJourneys(int numCities, long long daysPassed) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    n = numCities;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < n; ++j) 
            if((j + i ) % n != ((j - i) % n + n) % n)
                dp[i][j] = (dp[i - 1][(j + i) % n] + dp[i - 1][((j - i) % n + n) % n]) % mod;
            else dp[i][j] = dp[i - 1][(j + i) % n];
    memset(one, 0, sizeof(one));
    for(int i = 0; i < n; i++) one[i] = dp[n][i];
    memset(zero, 0, sizeof(zero));
    zero[0] = 1;
    muilti(daysPassed / n);
    memset(g, 0, sizeof(g));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g[(i + j) % n] = (g[(i + j) % n] + zero[i] * dp[daysPassed % n][j] % mod) % mod;
    for(int i = 0; i < n; i++)
        zero[i] = g[i];
    return zero[0];
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
			int numCities             = 3;
			long long daysPassed      = 2LL;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys( numCities, daysPassed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int numCities             = 4;
			long long daysPassed      = 3LL;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys( numCities, daysPassed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int numCities             = 5;
			long long daysPassed      = 36LL;
			int expected__            = 107374182;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys( numCities, daysPassed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int numCities             = 300;
			long long daysPassed      = 751LL;
			int expected__            = 413521250;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys( numCities, daysPassed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int numCities             = 300;
			long long daysPassed      = 750LL;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys( numCities, daysPassed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int numCities             = 350;
			long long daysPassed      = 1000000000000000000LL;
			int expected__            = 667009739;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys( numCities, daysPassed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			int numCities             = 5;
			long long daysPassed      = 7LL;
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys( numCities, daysPassed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 7: {
			int numCities             = ;
			long long daysPassed      = LL;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys( numCities, daysPassed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int numCities             = ;
			long long daysPassed      = LL;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys( numCities, daysPassed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 9: {
			int numCities             = ;
			long long daysPassed      = LL;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys( numCities, daysPassed );
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
