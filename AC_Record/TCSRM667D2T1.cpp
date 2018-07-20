//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class PointDistance {
public:
    vector <int> findPoint( int x1, int y1, int x2, int y2 );
};
int sqr(int x){ return x * x; }
vector<int> ans;
vector <int> PointDistance::findPoint(int x1, int y1, int x2, int y2) {
	ans.clear();
	for(int x = -100; x <= 100; x++)
		for(int y = -100; y <= 100; y++)
			if(sqr(x1 - x) + sqr(y1 - y) > sqr(x2 - x) + sqr(y2 - y)){
				ans.push_back(x);
				ans.push_back(y);
				return ans;
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
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			int x1                    = -1;
			int y1                    = 0;
			int x2                    = 1;
			int y2                    = 0;
			int expected__[]          = {8, 48 };

			clock_t start__           = clock();
			vector <int> received__   = PointDistance().findPoint( x1, y1, x2, y2 );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 1: {
			int x1                    = 1;
			int y1                    = 1;
			int x2                    = -1;
			int y2                    = -1;
			int expected__[]          = {25, -63 };

			clock_t start__           = clock();
			vector <int> received__   = PointDistance().findPoint( x1, y1, x2, y2 );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 2: {
			int x1                    = 0;
			int y1                    = 1;
			int x2                    = 2;
			int y2                    = 3;
			int expected__[]          = {41, 65 };

			clock_t start__           = clock();
			vector <int> received__   = PointDistance().findPoint( x1, y1, x2, y2 );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 3: {
			int x1                    = 5;
			int y1                    = -4;
			int x2                    = -2;
			int y2                    = 5;
			int expected__[]          = {68, 70 };

			clock_t start__           = clock();
			vector <int> received__   = PointDistance().findPoint( x1, y1, x2, y2 );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 4: {
			int x1                    = -50;
			int y1                    = -50;
			int x2                    = 50;
			int y2                    = -50;
			int expected__[]          = {67, 4 };

			clock_t start__           = clock();
			vector <int> received__   = PointDistance().findPoint( x1, y1, x2, y2 );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 5: {
			int x1                    = -50;
			int y1                    = 50;
			int x2                    = -49;
			int y2                    = 49;
			int expected__[]          = {73, -25 };

			clock_t start__           = clock();
			vector <int> received__   = PointDistance().findPoint( x1, y1, x2, y2 );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = PointDistance().findPoint( x1, y1, x2, y2 );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}*/
/*      case 7: {
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = PointDistance().findPoint( x1, y1, x2, y2 );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}*/
/*      case 8: {
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = PointDistance().findPoint( x1, y1, x2, y2 );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
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
