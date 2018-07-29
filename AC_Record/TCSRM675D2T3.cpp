//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class TreeAndPathLength2 {
public:
    string possible( int n, int s );
};
int rec[1010], ss, vis[60][1010];
void dfs(int rest, int cnt){
	if(cnt > ss) return;
	if(rest == 0) {
		rec[cnt] = 1;
		return;
	}
	if(vis[rest][cnt]) return;
	vis[rest][cnt] = 1;
	for(int i = 1; i <= rest; i++) dfs(rest - i, cnt + i + (i - 1) * i / 2);
	return;
}
string TreeAndPathLength2::possible(int n, int s) {
	ss = s;
	memset(vis, 0, sizeof(vis));
    memset(rec, 0, sizeof(rec));
	for(int i = 2; i <= n; i++) dfs(n - i, (i - 1) * (i - 2) / 2);
	if(rec[s]) return "Possible"; else return "Impossible";
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
			int n                     = 4;
			int s                     = 3;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = TreeAndPathLength2().possible( n, s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int n                     = 4;
			int s                     = 2;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = TreeAndPathLength2().possible( n, s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int n                     = 3;
			int s                     = 2;
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = TreeAndPathLength2().possible( n, s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int n                     = 5;
			int s                     = 4;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = TreeAndPathLength2().possible( n, s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int n                     = 50;
			int s                     = 999;
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = TreeAndPathLength2().possible( n, s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int n                     = 50;
			int s                     = 1000;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = TreeAndPathLength2().possible( n, s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int n                     = ;
			int s                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TreeAndPathLength2().possible( n, s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int n                     = ;
			int s                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TreeAndPathLength2().possible( n, s );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int n                     = ;
			int s                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TreeAndPathLength2().possible( n, s );
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
