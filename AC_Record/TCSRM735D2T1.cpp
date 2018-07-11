//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class BinaryCalculator {
public:
    int minimumSteps( int a, int b );
};
int BinaryCalculator::minimumSteps(int a, int b) {
	int ans = 0;
    while(a != b){
		while(a < b){
			a += 3;
			ans++;
		}
		while(a > b){
			a -= 2;
			ans++;
		}
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
			int a                     = 10;
			int b                     = 14;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = BinaryCalculator().minimumSteps( a, b );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int a                     = 23;
			int b                     = 23;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = BinaryCalculator().minimumSteps( a, b );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int a                     = 18;
			int b                     = 12;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = BinaryCalculator().minimumSteps( a, b );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int a                     = 23;
			int b                     = 62;
			int expected__            = 13;

			clock_t start__           = clock();
			int received__            = BinaryCalculator().minimumSteps( a, b );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int a                     = ;
			int b                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BinaryCalculator().minimumSteps( a, b );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int a                     = ;
			int b                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BinaryCalculator().minimumSteps( a, b );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int a                     = ;
			int b                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BinaryCalculator().minimumSteps( a, b );
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

