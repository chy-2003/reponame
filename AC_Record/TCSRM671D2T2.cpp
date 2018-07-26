//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class BearDartsDiv2 {
public:
    long long count( vector <int> w );
};
map<int, int> Map;
long long BearDartsDiv2::count(vector <int> w) {
	int n = w.size();
	Map.clear();
	long long ans = 0;
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			Map[w[i] * w[j]]++;
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < i; j++) Map[w[i] * w[j]]--;
		for(int j = n - 1; j > i; j--)
			if(w[j] % w[i] == 0){
				ans += Map[w[j] / w[i]];
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
			int w[]                   = {10,2,2,7,40,160};
			long long expected__      = 2LL;

			clock_t start__           = clock();
			long long received__      = BearDartsDiv2().count( vector <int>( w, w + ( sizeof w / sizeof w[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int w[]                   = {128,64,32,16,8,4,2,1};
			long long expected__      = 0LL;

			clock_t start__           = clock();
			long long received__      = BearDartsDiv2().count( vector <int>( w, w + ( sizeof w / sizeof w[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int w[]                   = {2,3,4,5,6,8,12,16,20,24,40,24,20,16,12,8,6,5,4,3,2};
			long long expected__      = 3LL;

			clock_t start__           = clock();
			long long received__      = BearDartsDiv2().count( vector <int>( w, w + ( sizeof w / sizeof w[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int w[]                   = {100,100,100,1000000,1000000,1000000,1000000,1000000};
			long long expected__      = 5LL;

			clock_t start__           = clock();
			long long received__      = BearDartsDiv2().count( vector <int>( w, w + ( sizeof w / sizeof w[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int w[]                   = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			long long expected__      = 2573031125LL;

			clock_t start__           = clock();
			long long received__      = BearDartsDiv2().count( vector <int>( w, w + ( sizeof w / sizeof w[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int w[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = BearDartsDiv2().count( vector <int>( w, w + ( sizeof w / sizeof w[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int w[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = BearDartsDiv2().count( vector <int>( w, w + ( sizeof w / sizeof w[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int w[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = BearDartsDiv2().count( vector <int>( w, w + ( sizeof w / sizeof w[0] ) ) );
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
