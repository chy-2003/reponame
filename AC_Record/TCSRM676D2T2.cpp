//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class BoardEscapeDiv2 {
public:
    string findWinner( vector <string> s, int k );
};
const int bz[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};
int n, m, a[60][60];
int b[60][60][110];
int dfs(int x, int y, int z) {
	if(b[x][y][z] != -1) return b[x][y][z];
	if(z == 0 || a[x][y] == 0) return 0;
	int move = 0, t = 0, tt;
	for(int i = 0; i < 4; i++) {
		if(a[x + bz[0][i]][y + bz[1][i]] == 2) continue;
		tt = dfs(x + bz[0][i], y + bz[1][i], z - 1);
		move = 1;
		if(tt == 0) t = 1;
	}
	if(move == 0) b[x][y][z] = 0; else b[x][y][z] = t;
	return b[x][y][z];
}
string BoardEscapeDiv2::findWinner(vector <string> s, int k) {
    n = s.size(); m = s[0].size();
	int x, y;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(s[i][j] == '#') a[i + 1][j + 1] = 2; else
			if(s[i][j] == '.') a[i + 1][j + 1] = 1; else
			if(s[i][j] == 'E') a[i + 1][j + 1] = 0; else
			if(s[i][j] == 'T') {
				x = i + 1; y = j + 1;
				a[i + 1][j + 1] = 1;
			}
		}
	}
	for(int i = 1; i <= n; i++) { a[i][0] = 2; a[i][m + 1] = 2; }
	for(int i = 1; i <= m; i++) { a[0][i] = 2; a[n + 1][i] = 2; }
	memset(b, 255, sizeof(b));
	int t = dfs(x, y, k);
	if(t == 1) return "Alice"; else return "Bob";
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
			string s[]                = {"T.#",  "#.E"};
			int k                     = 3;
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = BoardEscapeDiv2().findWinner( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string s[]                = {"E#E",  "#T#",  "E#E"};
			int k                     = 99;
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = BoardEscapeDiv2().findWinner( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string s[]                = {"#E...",  "#...E",  "E.T#.",  "..#.."};
			int k                     = 13;
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = BoardEscapeDiv2().findWinner( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string s[]                = {"TE"};
			int k                     = 50;
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = BoardEscapeDiv2().findWinner( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string s[]                = {".T."};
			int k                     = 1;
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = BoardEscapeDiv2().findWinner( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string s[]                = {"..........................",  "......EEE..EEE..E...E.....",  ".....E.....E..E.EE.EE.....",  "......EEE..EEE..E.E.E.....",  ".........E.E.E..E...E.....",  "......EEE..E..E.E...E.....",  "..........................",  "...E#E#E#E#E#E#E#E#E#E#...",  "..........................",  "......EEE..EEE...EEE......",  ".....E........E.E.........",  "......EEE.....E..EEE......",  ".....E...E...E..E...E.....",  "......EEE....E...EEE......",  "..........................",  "...#E#E#E#E#E#E#E#E#E#E...",  "..........................",  "....EE...E...E..E.EEE.E...",  "...E.....E...E..E.E...E...",  "...E.EE..E...EEEE.EE..E...",  "...E..E..E...E..E.E.......",  "....EE...EEE.E..E.E...E...",  "T........................."};
			int k                     = 100;
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = BoardEscapeDiv2().findWinner( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 6: {
			string s[]                = {"##E###", "...T.E"};
			int k                     = 27;
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = BoardEscapeDiv2().findWinner( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 7: {
			string s[]                = ;
			int k                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BoardEscapeDiv2().findWinner( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			string s[]                = ;
			int k                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BoardEscapeDiv2().findWinner( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ), k );
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
