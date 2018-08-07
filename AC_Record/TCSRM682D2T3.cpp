//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class FriendlyRobot {
public:
    int findMaximumReturns( string instructions, int changesAllowed );
};
string s;
int dp[310][310], len;
int dfs(int id, int rest) {
	if(id >= len) return 0;
	if(dp[id][rest] != -1) return dp[id][rest];
	dp[id][rest] = 0;
	int x = 0, y = 0;
	for(int i = id; i < len; i++) {
		if(s[i] == 'U') y++;
		if(s[i] == 'D') y--;
		if(s[i] == 'L') x--;
		if(s[i] == 'R') x++;
		int t = abs(x) + abs(y);
		if(t % 2 == 1) continue;
		if(t / 2 > rest) continue;
		dp[id][rest] = max(dp[id][rest], dfs(i + 1, rest - t / 2) + 1);
	}
	return dp[id][rest];
}
int FriendlyRobot::findMaximumReturns(string instructions, int changesAllowed) {
    memset(dp, 255, sizeof(dp));
	s = instructions;
	len = s.size();
	return dfs(0, changesAllowed);
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
			string instructions       = "UULRRLLL";
			int changesAllowed        = 1;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = FriendlyRobot().findMaximumReturns( instructions, changesAllowed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string instructions       = "ULDR";
			int changesAllowed        = 0;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FriendlyRobot().findMaximumReturns( instructions, changesAllowed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string instructions       = "ULDR";
			int changesAllowed        = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = FriendlyRobot().findMaximumReturns( instructions, changesAllowed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string instructions       = "ULDRRLRUDUDLURLUDRUDL";
			int changesAllowed        = 4;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = FriendlyRobot().findMaximumReturns( instructions, changesAllowed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string instructions       = "LRLDRURDRDUDDDDRLLRUUDURURDRRDRULRDLLDDDDRLRRLLRRDDLRURLRULLLLLRRRDULRULULRLRDLLDDLLRDLUUDUURRULUDUDURULULLDRUDUUURRRURUULRLDLRRRDLLDLRDUULUURUDRURRLURLDLDDUUURRURRLRDLDDULLUDLUDULRDLDUURLUUUURRLRURRDLRRLLLRDRDUUUDRRRDLDRRUUDUDDUDDRLUDDULRURRDRUDLDLLLDLUDDRLURLDUDRUDDDDURLUUUDRLURDDDDLDDRDLUDDLDLURR";
			int changesAllowed        = 47;
			int expected__            = 94;

			clock_t start__           = clock();
			int received__            = FriendlyRobot().findMaximumReturns( instructions, changesAllowed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string instructions       = "UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU";
			int changesAllowed        = 300;
			int expected__            = 150;

			clock_t start__           = clock();
			int received__            = FriendlyRobot().findMaximumReturns( instructions, changesAllowed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		} 
		case 6: {
			string instructions       = "UD";
			int changesAllowed        = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FriendlyRobot().findMaximumReturns( instructions, changesAllowed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		} 

		// custom cases

/*      case 7: {
			string instructions       = ;
			int changesAllowed        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FriendlyRobot().findMaximumReturns( instructions, changesAllowed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			string instructions       = ;
			int changesAllowed        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FriendlyRobot().findMaximumReturns( instructions, changesAllowed );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 9: {
			string instructions       = ;
			int changesAllowed        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FriendlyRobot().findMaximumReturns( instructions, changesAllowed );
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
