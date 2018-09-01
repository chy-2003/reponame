//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class CentaurCompanyDiv2 {
public:
    long long count( vector <int> a, vector <int> b );
};
long long ans[60], conection[60][60], n;
void dfs(int pos, int fa) {
    ans[pos] = 1;
    for(int i = 1; i <= n; i++) {
        if(i == fa || conection[pos][i] == 0) continue;
        dfs(i, pos);
        ans[pos] *= (ans[i] + 1);
    }
    return;
}
long long CentaurCompanyDiv2::count(vector <int> a, vector <int> b) {
    n = a.size() + 1;
    memset(conection, 0, sizeof(conection));
    for(int i = 0; i < n - 1; i++) conection[a[i]][b[i]] = conection[b[i]][a[i]] = 1;
    memset(ans, 0, sizeof(ans));
    dfs(1, 0);
    for(int i = 2; i <= n; i++) ans[1] += ans[i];
    return ans[1] + 1;
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int a[]                   = {1};
			int b[]                   = {2};
			long long expected__      = 4LL;

			clock_t start__           = clock();
			long long received__      = CentaurCompanyDiv2().count( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int a[]                   = {2,2};
			int b[]                   = {1,3};
			long long expected__      = 7LL;

			clock_t start__           = clock();
			long long received__      = CentaurCompanyDiv2().count( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int a[]                   = {1,2,3,4,5,6,7,8,9};
			int b[]                   = {2,3,4,5,6,7,8,9,10};
			long long expected__      = 56LL;

			clock_t start__           = clock();
			long long received__      = CentaurCompanyDiv2().count( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int a[]                   = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int b[]                   = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51};
			long long expected__      = 1125899906842675LL;

			clock_t start__           = clock();
			long long received__      = CentaurCompanyDiv2().count( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int a[]                   = {10, 7, 2, 5, 6, 2, 4, 9, 7};
			int b[]                   = {8, 10, 10, 4, 1, 6, 2, 2, 3};
			long long expected__      = 144LL;

			clock_t start__           = clock();
			long long received__      = CentaurCompanyDiv2().count( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int a[]                   = ;
			int b[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = CentaurCompanyDiv2().count( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int a[]                   = ;
			int b[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = CentaurCompanyDiv2().count( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int a[]                   = ;
			int b[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = CentaurCompanyDiv2().count( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
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
