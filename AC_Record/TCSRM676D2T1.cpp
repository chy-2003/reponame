//tc is healthy, just do it
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class FarmvilleDiv2 {
public:
    int minTime( vector <int> time, vector <int> cost, int budget );
};
struct Node{
	int x, y;
	Node (int x_ = 0, int y_ = 0) { x = x_; y = y_; return; }
};
Node a[60];
int n;
bool cmp(Node x, Node y) { return x.y < y.y; }
int FarmvilleDiv2::minTime(vector <int> time, vector <int> cost, int budget) {
    n = time.size();
	for(int i = 0; i < n; i++) a[i + 1] = Node (time[i], cost[i]);
	sort(a + 1, a + n + 1, cmp);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += (a[i].x - min(a[i].x, budget / a[i].y));
		budget -= a[i].y * min(a[i].x, budget / a[i].y);
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
			int time[]                = {100};
			int cost[]                = {1};
			int budget                = 26;
			int expected__            = 74;

			clock_t start__           = clock();
			int received__            = FarmvilleDiv2().minTime( vector <int>( time, time + ( sizeof time / sizeof time[0] ) ), vector <int>( cost, cost + ( sizeof cost / sizeof cost[0] ) ), budget );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int time[]                = {100};
			int cost[]                = {1};
			int budget                = 101;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FarmvilleDiv2().minTime( vector <int>( time, time + ( sizeof time / sizeof time[0] ) ), vector <int>( cost, cost + ( sizeof cost / sizeof cost[0] ) ), budget );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int time[]                = {2,1};
			int cost[]                = {1,1};
			int budget                = 3;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FarmvilleDiv2().minTime( vector <int>( time, time + ( sizeof time / sizeof time[0] ) ), vector <int>( cost, cost + ( sizeof cost / sizeof cost[0] ) ), budget );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int time[]                = {1,2,3,4,5};
			int cost[]                = {5,4,3,2,1};
			int budget                = 15;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = FarmvilleDiv2().minTime( vector <int>( time, time + ( sizeof time / sizeof time[0] ) ), vector <int>( cost, cost + ( sizeof cost / sizeof cost[0] ) ), budget );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int time[]                = {100,100,100,100,100,100,100,100,100,100};
			int cost[]                = {2,4,6,8,10,1,3,5,7,9};
			int budget                = 5000;
			int expected__            = 50;

			clock_t start__           = clock();
			int received__            = FarmvilleDiv2().minTime( vector <int>( time, time + ( sizeof time / sizeof time[0] ) ), vector <int>( cost, cost + ( sizeof cost / sizeof cost[0] ) ), budget );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int time[]                = {30,40,20,10};
			int cost[]                = {10,20,30,40};
			int budget                = 5;
			int expected__            = 100;

			clock_t start__           = clock();
			int received__            = FarmvilleDiv2().minTime( vector <int>( time, time + ( sizeof time / sizeof time[0] ) ), vector <int>( cost, cost + ( sizeof cost / sizeof cost[0] ) ), budget );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int time[]                = ;
			int cost[]                = ;
			int budget                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FarmvilleDiv2().minTime( vector <int>( time, time + ( sizeof time / sizeof time[0] ) ), vector <int>( cost, cost + ( sizeof cost / sizeof cost[0] ) ), budget );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int time[]                = ;
			int cost[]                = ;
			int budget                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FarmvilleDiv2().minTime( vector <int>( time, time + ( sizeof time / sizeof time[0] ) ), vector <int>( cost, cost + ( sizeof cost / sizeof cost[0] ) ), budget );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int time[]                = ;
			int cost[]                = ;
			int budget                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FarmvilleDiv2().minTime( vector <int>( time, time + ( sizeof time / sizeof time[0] ) ), vector <int>( cost, cost + ( sizeof cost / sizeof cost[0] ) ), budget );
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
