//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class CombiningSlimes {
public:
    int maxMascots( vector <int> a );
};
int f[110][110], s[110], n;
int CombiningSlimes::maxMascots(vector <int> a) {
    memset(f, 0, sizeof(f));
	memset(s, 0, sizeof(s));
	s[1] = a[0];
	n = a.size();
	for(int i = 1; i < n; i++) s[i + 1] = a[i] + s[i];
	for(int t = 2; t <= n; t++){
		for(int i = 1; i <= n - t + 1; i++){
			int j = i + t - 1;
			for(int k = i; k < j; k++) f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + (s[j] - s[k]) * (s[k] - s[i - 1]));
		}
	}
	return f[1][n];
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
			int a[]                   = {3,4};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = CombiningSlimes().maxMascots( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int a[]                   = {2,2,2};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = CombiningSlimes().maxMascots( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int a[]                   = {1,2,3};
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = CombiningSlimes().maxMascots( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int a[]                   = {3,1,2};
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = CombiningSlimes().maxMascots( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int a[]                   = {7,6,5,3,4,6};
			int expected__            = 395;

			clock_t start__           = clock();
			int received__            = CombiningSlimes().maxMascots( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int a[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CombiningSlimes().maxMascots( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int a[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CombiningSlimes().maxMascots( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int a[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CombiningSlimes().maxMascots( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
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
