//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class IsItASquare {
public:
	string isSquare( vector <int> x, vector <int> y );
};
struct point{
	int x, y;
	point(int x_ = 0, int y_ = 0) { x = x_; y = y_; return; }
};
point a[4];
bool cmp(point x, point y){
	return x.y < y.y;
}
int sqr(int x) { return x * x; }
int dis(int x, int y){
	return sqr(a[x].x - a[y].x) + sqr(a[x].y - a[y].y);
}
string IsItASquare::isSquare(vector <int> x, vector <int> y) {
	for(int i = 0; i < 4; i++) a[i] = point(x[i], y[i]);
	sort(a, a + 4, cmp);
	int dis1 = dis(0, 1);
	int dis2 = dis(0, 2);
	int dis3 = dis(1, 3);
	int dis4 = dis(2, 3);
	if(dis1 == dis2 && dis2 == dis3 && dis3 == dis4){
		int x1 = a[0].x - a[1].x;
		int x2 = a[0].x - a[2].x;
		int y1 = a[0].y - a[1].y;
		int y2 = a[0].y - a[2].y;
		if(x1 * x2 + y1 * y2 == 0) return "It's a square"; else return "Not a square";
	} else return "Not a square";
	return "Not a square";
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
			int x[]                   = {0, 0, 2, 2};
			int y[]                   = {0, 2, 0, 2};
			string expected__         = "It's a square";

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int x[]                   = {0, 1, 5, 6};
			int y[]                   = {1, 6, 0, 5};
			string expected__         = "It's a square";

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int x[]                   = {0, 0, 7, 7};
			int y[]                   = {0, 3, 0, 3};
			string expected__         = "Not a square";

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int x[]                   = {0, 5000, 5000, 10000};
			int y[]                   = {5000, 0, 10000, 5000};
			string expected__         = "It's a square";

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int x[]                   = {1, 2, 3, 4};
			int y[]                   = {4, 3, 2, 1};
			string expected__         = "Not a square";

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int x[]                   = {0, 5, 3, 8};
			int y[]                   = {0, 0, 4, 4};
			string expected__         = "Not a square";

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int x[]                   = ;
			int y[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = IsItASquare().isSquare( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
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
