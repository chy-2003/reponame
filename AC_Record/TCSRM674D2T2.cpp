//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class PlaneGame {
public:
    int bestShot( vector <int> x, vector <int> y );
};
long double k1, b1, k2, b2;
int t, ans;
int PlaneGame::bestShot(vector <int> x, vector <int> y) {
    int n = x.size();
    if(n <= 2) return n;
    ans = 0;
    for(int i = 0; i < n - 1; i++)
       for(int j = i + 1; j < n; j++)
           for(int k = 0; k < n; k++){
               if(i == k || j == k) continue;
               if(x[i] != x[j] && y[i] != y[j]){
                   k1 = (long double)(y[j] - y[i]) / (long double)(x[j] - x[i]);
                   b1 = (long double)y[i] - k1 * (long double)x[i];
                   k2 = -1.0/k1;
                   b2 = (long double)y[k] - k2 * (long double)x[k];
                   t = 0;
                   for(int l = 0; l < n; l++)
                       if(abs((long double)y[l] - (k1 * x[l] + b1)) <= 0.0001 || abs((long double)y[l] - (k2 * x[l] + b2)) <= 0.0001) t++;
                   ans = max(ans, t);
                   continue;
               }
               if(y[i] == y[j]){
                   t = 0;
                   for(int l = 0; l < n; l++)
                       if(y[l] == y[i] || x[l] == x[k]) t++;
                   ans = max(ans, t);
                   continue;
               }
               if(x[i] == x[j]){
                   t = 0;
                   for(int l = 0; l < n; l++)
                       if(x[l] == x[i] || y[l] == y[k]) t++;
                   ans = max(ans, t);
                   continue;
               }
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
			int x[]                   = {0, 5};
			int y[]                   = {0, 5};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PlaneGame().bestShot( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int x[]                   = {0, -1, 1, 1, -1};
			int y[]                   = {0, -1, -1, 1, 1};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = PlaneGame().bestShot( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int x[]                   = {0, 0, 0, 1, -1};
			int y[]                   = {0, 1, -1, 0, 0};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = PlaneGame().bestShot( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int x[]                   = {0, -3, 3, 3, -3, 0, 0, 3, -3};
			int y[]                   = {0, -3, -3, 3, 3, 3, -3, 0, 0};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = PlaneGame().bestShot( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int x[]                   = {0};
			int y[]                   = {0};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PlaneGame().bestShot( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int x[]                   = {-1000000, -1, 999998, 1, -1001, 1000000, -999999, 999999, 0, 0};
			int y[]                   = {1000000, 1, 1000000, -1, -999, 1000000, 0, 0, -999999, 999999};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = PlaneGame().bestShot( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 6: {
			int x[]                   = {0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 8, 0, 9, 0, 10, 0, 11, 0, 12, 0, 13, 0, 14, 0, 15, 0, 16, 0, 17, 0, 18, 0, 19, 0, 20, 0, 21, 0, 22, 0, 23, 0, 24, 0, 25}; 
            int y[]                   = {0, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 8, 0, 9, 0, 10, 0, 11, 0, 12, 0, 13, 0, 14, 0, 15, 0, 16, 0, 17, 0, 18, 0, 19, 0, 20, 0, 21, 0, 22, 0, 23, 0, 24, 0};
			int expected__            = 50;

			clock_t start__           = clock();
			int received__            = PlaneGame().bestShot( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
      case 7: {
			int x[]                   = {5, 8, 9, 1000, 754, 123, 256, 148, 36, 254, -12, -18, -254, -36, -1800};
            int y[]                   = {0, 0, -12, 1, 2, 3, 4, 5, -810, -1, 2541, -2, 658, -952, -12000};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = PlaneGame().bestShot( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 8: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PlaneGame().bestShot( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
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
