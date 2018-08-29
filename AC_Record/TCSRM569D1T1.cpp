//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class TheDevice {
public:
    int minimumAdditional( vector <string> plates );
};
int n, m;
int TheDevice::minimumAdditional(vector <string> plates) {
    n = plates.size();
    m = plates[0].size();
    int ans = 0;
    for(int i = 0; i < m; i++) {
        int cnt1 = 0, cnt2 = 0;
        for(int j = 0; j < n; j++) {
            if(plates[j][i] == '0') cnt2++;
            if(plates[j][i] == '1') cnt1++;
        }
        ans = max(ans, max(2 - cnt1, 0) + max(1 - cnt2, 0));
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
			string plates[]           = {"010",  "011",  "101"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheDevice().minimumAdditional( vector <string>( plates, plates + ( sizeof plates / sizeof plates[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string plates[]           = {"0",  "1",  "0",  "1"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheDevice().minimumAdditional( vector <string>( plates, plates + ( sizeof plates / sizeof plates[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string plates[]           = {"01010101",  "10101010"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheDevice().minimumAdditional( vector <string>( plates, plates + ( sizeof plates / sizeof plates[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string plates[]           = {"10010101011",  "00010101001",  "00100010111",  "00101010101",  "01010111101"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheDevice().minimumAdditional( vector <string>( plates, plates + ( sizeof plates / sizeof plates[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string plates[]           = {"1101001011010",  "0010000010101",  "1010101011110",  "1101010100111",  "1011111110111"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheDevice().minimumAdditional( vector <string>( plates, plates + ( sizeof plates / sizeof plates[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			string plates[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheDevice().minimumAdditional( vector <string>( plates, plates + ( sizeof plates / sizeof plates[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string plates[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheDevice().minimumAdditional( vector <string>( plates, plates + ( sizeof plates / sizeof plates[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string plates[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheDevice().minimumAdditional( vector <string>( plates, plates + ( sizeof plates / sizeof plates[0] ) ) );
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
