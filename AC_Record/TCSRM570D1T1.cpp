//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class RobotHerb {
public:
    long long getdist( int T, vector <int> a );
};
const int bz[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};
long long dir, x, y;
long long RobotHerb::getdist(int T, vector <int> a) {
    dir = x = y = 0;
    int n = a.size();
    for(int i = 0; i < n; i++) {
        x += a[i] * bz[0][dir];
        y += a[i] * bz[1][dir];
        dir = (dir + a[i]) % 4;
    }
    if(dir == 0) return T * (abs(x) + abs(y));
    if(dir == 2) 
        if(T % 2 == 1) return abs(x) + abs(y); else return 0;
    T = T % 4;
    long long s = 0, xx = 0, yy = 0;
    for(int i = 1; i <= T; i++) {
        if(s == 0) { xx += x; yy += y; }
        if(s == 1) { xx += y; yy += -x; }
        if(s == 2) { xx += -x; yy += -y; }
        if(s == 3) { xx += -y; yy += x; }
        s = (s + dir) % 4;
    }
    return abs(xx) + abs(yy);
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
			int T                     = 1;
			int a[]                   = {1,2,3};
			long long expected__      = 2LL;

			clock_t start__           = clock();
			long long received__      = RobotHerb().getdist( T, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int T                     = 100;
			int a[]                   = {1};
			long long expected__      = 0LL;

			clock_t start__           = clock();
			long long received__      = RobotHerb().getdist( T, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int T                     = 5;
			int a[]                   = {1,1,2};
			long long expected__      = 10LL;

			clock_t start__           = clock();
			long long received__      = RobotHerb().getdist( T, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int T                     = 1000000000;
			int a[]                   = {100};
			long long expected__      = 100000000000LL;

			clock_t start__           = clock();
			long long received__      = RobotHerb().getdist( T, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int T                     = 570;
			int a[]                   = {2013,2,13,314,271,1414,1732};
			long long expected__      = 4112LL;

			clock_t start__           = clock();
			long long received__      = RobotHerb().getdist( T, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int T                     = ;
			int a[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = RobotHerb().getdist( T, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int T                     = ;
			int a[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = RobotHerb().getdist( T, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int T                     = ;
			int a[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = RobotHerb().getdist( T, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
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
