//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class TheSquareRootDilemma {
public:
    int countPairs( int N, int M );
};
int f[80010];
int TheSquareRootDilemma::countPairs(int N, int M) {
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= N || i <= M; i++) 
        if((int)sqrt(i) * (int)sqrt(i) == i) f[i] = f[i - 1] + 1; else f[i] = f[i - 1];
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int t = i;
        for(int j = 2; j * j <= t; j++) 
            while(t % (j * j) == 0) t /= j * j;
        ans += f[M / t];
        if((int)sqrt(t) * (int)sqrt(t) == t && t != 1) ans += 1;
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
			int N                     = 2;
			int M                     = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheSquareRootDilemma().countPairs( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 10;
			int M                     = 1;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TheSquareRootDilemma().countPairs( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 3;
			int M                     = 8;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = TheSquareRootDilemma().countPairs( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 100;
			int M                     = 100;
			int expected__            = 310;

			clock_t start__           = clock();
			int received__            = TheSquareRootDilemma().countPairs( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheSquareRootDilemma().countPairs( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int N                     = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheSquareRootDilemma().countPairs( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int N                     = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheSquareRootDilemma().countPairs( N, M );
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
