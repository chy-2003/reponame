//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class GoodString {
public:
    string isGood( string s );
};
string st;
bool solve(int l, int r){
	if(l > r) return 1;
	if((r - l) % 2 == 0) return 0;
	if(st[l] == 'b') return 0;
	int t = 0;
	for(int i = l + 1; i <= r; i += 2)
		if(st[i] == 'b')
			if(solve(l + 1, i - 1) && solve(i + 1, r)){
				t = 1;
				break;
			}
	return t;
}
string GoodString::isGood(string s) {
	st = s;
	if(solve(0, s.size() - 1)) return "Good"; else return "Bad";
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
			string s                  = "ab";
			string expected__         = "Good";

			clock_t start__           = clock();
			string received__         = GoodString().isGood( s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string s                  = "aab";
			string expected__         = "Bad";

			clock_t start__           = clock();
			string received__         = GoodString().isGood( s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string s                  = "aabb";
			string expected__         = "Good";

			clock_t start__           = clock();
			string received__         = GoodString().isGood( s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string s                  = "ababab";
			string expected__         = "Good";

			clock_t start__           = clock();
			string received__         = GoodString().isGood( s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string s                  = "abaababababbaabbaaaabaababaabbabaaabbbbbbbb";
			string expected__         = "Bad";

			clock_t start__           = clock();
			string received__         = GoodString().isGood( s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string s                  = "aaaaaaaabbbaaabaaabbabababababaabbbbaabbabbbbbbabb";
			string expected__         = "Good";

			clock_t start__           = clock();
			string received__         = GoodString().isGood( s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			string s                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = GoodString().isGood( s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string s                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = GoodString().isGood( s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			string s                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = GoodString().isGood( s );
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
