//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class ShopPositions {
public:
    int maxProfit( int n, int m, vector <int> c );
};
int f[40][40][40];
int ShopPositions::maxProfit(int n, int m, vector <int> c) {
    memset(f, 0, sizeof(f));
	int ans = 0;
	for(int j = 0; j <= m; j++)
		for(int k = 0; k <= m; k++){
			if(j + k == 0) continue;
			f[0][j][k] = max(f[0][j][k], j * c[0 * 3 * m + (j + k) - 1]);
			ans = max(ans, f[0][j][k]);
		}
//	printf("*\n");
	for(int i = 1; i < n - 1; i++)
		for(int j = 0; j <= m; j++)
			for(int k = 0; k <= m; k++)
				for(int l = 0; l <= m; l++){
					if(j + k + l == 0) continue;
					f[i][j][k] = max(f[i][j][k], f[i - 1][l][j] + j * c[i * 3 * m + (j + k + l) - 1]);
					ans = max(ans, f[i][j][k]);
				}
//	printf("*\n");
	if(n > 1)
	for(int j = 0; j <= m; j++)
		for(int l = 0; l <= m; l++){
			if(j + l == 0) continue;
			f[n - 1][j][0] = max(f[n - 1][j][0], f[n - 2][l][j] + j * c[(n - 1) * 3 * m + (j + l) - 1]);
			ans = max(ans, f[n - 1][j][0]);
		}
//	printf("*\n");
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
			int n                     = 1;
			int m                     = 5;
			int c[]                   = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 1, 1, 1, 1, 1};
			int expected__            = 300;

			clock_t start__           = clock();
			int received__            = ShopPositions().maxProfit( n, m, vector <int>( c, c + ( sizeof c / sizeof c[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int n                     = 1;
			int m                     = 5;
			int c[]                   = {1000, 5, 4, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			int expected__            = 1000;

			clock_t start__           = clock();
			int received__            = ShopPositions().maxProfit( n, m, vector <int>( c, c + ( sizeof c / sizeof c[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int n                     = 3;
			int m                     = 1;
			int c[]                   = {   7,6,1,   10,4,1,   7,6,3 };
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = ShopPositions().maxProfit( n, m, vector <int>( c, c + ( sizeof c / sizeof c[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int n                     = 2;
			int m                     = 2;
			int c[]                   = {  12,11,10,9,8,7,  6,5,4,3,2,1 };
			int expected__            = 24;

			clock_t start__           = clock();
			int received__            = ShopPositions().maxProfit( n, m, vector <int>( c, c + ( sizeof c / sizeof c[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int n                     = 3;
			int m                     = 3;
			int c[]                   = {   30,28,25,15,14,10,5,4,2,   50,40,30,28,17,13,8,6,3,   45,26,14,14,13,13,2,1,1 };
			int expected__            = 127;

			clock_t start__           = clock();
			int received__            = ShopPositions().maxProfit( n, m, vector <int>( c, c + ( sizeof c / sizeof c[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int m                     = ;
			int c[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ShopPositions().maxProfit( n, m, vector <int>( c, c + ( sizeof c / sizeof c[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int n                     = ;
			int m                     = ;
			int c[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ShopPositions().maxProfit( n, m, vector <int>( c, c + ( sizeof c / sizeof c[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int n                     = ;
			int m                     = ;
			int c[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ShopPositions().maxProfit( n, m, vector <int>( c, c + ( sizeof c / sizeof c[0] ) ) );
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
