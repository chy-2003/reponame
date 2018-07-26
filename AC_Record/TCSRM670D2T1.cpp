//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class Cdgame {
public:
    int rescount( vector <int> a, vector <int> b );
};
set<int> s;
int A, B, n;
int Cdgame::rescount(vector <int> a, vector <int> b) {
    s.clear();
	n = a.size(); A = 0; B = 0;
	for(int i = 0; i < n; ++i) A += a[i];
	for(int i = 0; i < n; ++i) B += b[i];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			s.insert((A - a[i] + b[j]) * (B - b[j] + a[i]));
	return s.size();
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
			int a[]                   = {1,2};
			int b[]                   = {3,4};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Cdgame().rescount( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int a[]                   = {1,2,4};
			int b[]                   = {8,16,32};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = Cdgame().rescount( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int a[]                   = {1,1,1};
			int b[]                   = {1,1,1};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Cdgame().rescount( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int a[]                   = {1,2,3};
			int b[]                   = {5,5,5};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Cdgame().rescount( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int a[]                   = {3,3,4,1};
			int b[]                   = {2,2,2,100};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = Cdgame().rescount( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int a[]                   = {31,34,55,56,57};
			int b[]                   = {1,2,3,4,5};
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = Cdgame().rescount( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int a[]                   = ;
			int b[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Cdgame().rescount( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int a[]                   = ;
			int b[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Cdgame().rescount( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int a[]                   = ;
			int b[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Cdgame().rescount( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
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
