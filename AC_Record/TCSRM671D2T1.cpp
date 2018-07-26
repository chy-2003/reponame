//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class BearPaints {
public:
    long long maxArea( int W, int H, long long M );
};
long long BearPaints::maxArea(int W, int H, long long M) {
    long long ans = 0;
	for(int i = 1; i <= W; i++){
		ans = max(1LL * i * min(1LL * H, 1LL * (M / i)), ans);
	}
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int W                     = 3;
			int H                     = 5;
			long long M               = 14LL;
			long long expected__      = 12LL;

			clock_t start__           = clock();
			long long received__      = BearPaints().maxArea( W, H, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int W                     = 4;
			int H                     = 4;
			long long M               = 10LL;
			long long expected__      = 9LL;

			clock_t start__           = clock();
			long long received__      = BearPaints().maxArea( W, H, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int W                     = 1000000;
			int H                     = 12345;
			long long M               = 1000000000000LL;
			long long expected__      = 12345000000LL;

			clock_t start__           = clock();
			long long received__      = BearPaints().maxArea( W, H, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int W                     = 1000000;
			int H                     = 1000000;
			long long M               = 720000000007LL;
			long long expected__      = 720000000000LL;

			clock_t start__           = clock();
			long long received__      = BearPaints().maxArea( W, H, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int W                     = 1000000;
			int H                     = 1000000;
			long long M               = 999999999999LL;
			long long expected__      = 999999000000LL;

			clock_t start__           = clock();
			long long received__      = BearPaints().maxArea( W, H, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int W                     = ;
			int H                     = ;
			long long M               = LL;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = BearPaints().maxArea( W, H, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int W                     = ;
			int H                     = ;
			long long M               = LL;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = BearPaints().maxArea( W, H, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int W                     = ;
			int H                     = ;
			long long M               = LL;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = BearPaints().maxArea( W, H, M );
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
