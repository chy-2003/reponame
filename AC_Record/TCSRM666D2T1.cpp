//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class DevuAndGame {
public:
    string canWin( vector <int> nextLevel );
};
int rec[60];
string DevuAndGame::canWin(vector <int> nextLevel) {
	memset(rec, 0, sizeof(rec));
	int t = 0;
	while(1){
		rec[t] = 1;
		t = nextLevel[t];
		if(t == -1) return "Win";
		if(rec[t] == 1) return "Lose";
	}
	return "Lose";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int nextLevel[]           = {1, -1};
			string expected__         = "Win";

			clock_t start__           = clock();
			string received__         = DevuAndGame().canWin( vector <int>( nextLevel, nextLevel + ( sizeof nextLevel / sizeof nextLevel[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int nextLevel[]           = {1, 0, -1};
			string expected__         = "Lose";

			clock_t start__           = clock();
			string received__         = DevuAndGame().canWin( vector <int>( nextLevel, nextLevel + ( sizeof nextLevel / sizeof nextLevel[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int nextLevel[]           = {0, 1, 2};
			string expected__         = "Lose";

			clock_t start__           = clock();
			string received__         = DevuAndGame().canWin( vector <int>( nextLevel, nextLevel + ( sizeof nextLevel / sizeof nextLevel[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int nextLevel[]           = {29,33,28,16,-1,11,10,14,6,31,7,35,34,8,15,17,26,12,13,22,1,20,2,21,-1,5,19,9,18,4,25,32,3,30,23,10,27};
			string expected__         = "Win";

			clock_t start__           = clock();
			string received__         = DevuAndGame().canWin( vector <int>( nextLevel, nextLevel + ( sizeof nextLevel / sizeof nextLevel[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int nextLevel[]           = {17,43,20,41,42,15,18,35,-1,31,7,33,23,33,-1,-1,0,33,19,12,42,-1,-1,9,9,-1,39,-1,31,46,-1,20,44,41,-1,-1,12,-1,36,-1,-1,6,47,10,2,4,1,29};
			string expected__         = "Win";

			clock_t start__           = clock();
			string received__         = DevuAndGame().canWin( vector <int>( nextLevel, nextLevel + ( sizeof nextLevel / sizeof nextLevel[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int nextLevel[]           = {3, 1, 1, 2, -1, 4};
			string expected__         = "Lose";

			clock_t start__           = clock();
			string received__         = DevuAndGame().canWin( vector <int>( nextLevel, nextLevel + ( sizeof nextLevel / sizeof nextLevel[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int nextLevel[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = DevuAndGame().canWin( vector <int>( nextLevel, nextLevel + ( sizeof nextLevel / sizeof nextLevel[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int nextLevel[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = DevuAndGame().canWin( vector <int>( nextLevel, nextLevel + ( sizeof nextLevel / sizeof nextLevel[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int nextLevel[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = DevuAndGame().canWin( vector <int>( nextLevel, nextLevel + ( sizeof nextLevel / sizeof nextLevel[0] ) ) );
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
