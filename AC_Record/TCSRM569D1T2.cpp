//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class TheJediTest {
public:
    int minimumSupervisors( vector <int> students, int K );
};
int TheJediTest::minimumSupervisors(vector <int> students, int K) {
    int ans = 0, n = students.size();
    for(int i = 0; i < n; i++) {
        ans += (students[i] + K - 1) / K;
        int res = K - (students[i] % K);
        if(res == K) res = 0;
        if(i + 1 < n) {
            int res2 = min(res, students[i + 1]);
            res -= res2; students[i + 1] -= res2;
            students[i] += res2;
        }
        if(i + 2 < n) {
            int res2 = min(res, students[i + 2]);
            students[i + 2] -= res2;
            students[i] += res2;
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
			int students[]            = {3, 6, 3};
			int K                     = 4;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors( vector <int>( students, students + ( sizeof students / sizeof students[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int students[]            = {1, 1, 1, 1};
			int K                     = 4;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors( vector <int>( students, students + ( sizeof students / sizeof students[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int students[]            = {0, 0, 0, 0};
			int K                     = 12345;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors( vector <int>( students, students + ( sizeof students / sizeof students[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int students[]            = {15, 0, 13, 4, 29, 6, 2};
			int K                     = 7;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors( vector <int>( students, students + ( sizeof students / sizeof students[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int students[]            = {1284912, 1009228, 9289247, 2157, 2518, 52781, 2, 2818, 68};
			int K                     = 114;
			int expected__            = 102138;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors( vector <int>( students, students + ( sizeof students / sizeof students[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 5: {
			int students[]            = {2, 1, 6, 3};
			int K                     = 4;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors( vector <int>( students, students + ( sizeof students / sizeof students[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 6: {
			int students[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors( vector <int>( students, students + ( sizeof students / sizeof students[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int students[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors( vector <int>( students, students + ( sizeof students / sizeof students[0] ) ), K );
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
