//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class LiveConcert {
public:
    int maxHappiness( vector <int> h, vector <string> s );
};
map<string, int> MMP;
int LiveConcert::maxHappiness(vector <int> h, vector <string> s) {
    MMP.clear();
	int ans = 0;
	int n = h.size();
	for(int i = 0; i < n; i++){
		int t = MMP[s[i]];
		ans += max(0, h[i] - t);
		MMP[s[i]] += max(0, h[i] - t);
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
			int h[]                   = {10,5,6,7,1,2};
			string s[]                = {"ciel","bessie","john","bessie","bessie","john"};
			int expected__            = 23;

			clock_t start__           = clock();
			int received__            = LiveConcert().maxHappiness( vector <int>( h, h + ( sizeof h / sizeof h[0] ) ), vector <string>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int h[]                   = {3,3,4,3,3};
			string s[]                = {"a","a","a","a","a"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = LiveConcert().maxHappiness( vector <int>( h, h + ( sizeof h / sizeof h[0] ) ), vector <string>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int h[]                   = {1,2,3,4,5,6,7,8,9,10,100};
			string s[]                = {"a","b","c","d","e","e","d","c","b","a","abcde"};
			int expected__            = 140;

			clock_t start__           = clock();
			int received__            = LiveConcert().maxHappiness( vector <int>( h, h + ( sizeof h / sizeof h[0] ) ), vector <string>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int h[]                   = {100};
			string s[]                = {"oyusop"};
			int expected__            = 100;

			clock_t start__           = clock();
			int received__            = LiveConcert().maxHappiness( vector <int>( h, h + ( sizeof h / sizeof h[0] ) ), vector <string>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int h[]                   = {100,100,100,100,100,100,100,100,100,100,100,100,100};
			string s[]                = {"haruka","chihaya","yayoi","iori","yukiho","makoto","ami","mami","azusa","miki","hibiki","takane","ritsuko"};
			int expected__            = 1300;

			clock_t start__           = clock();
			int received__            = LiveConcert().maxHappiness( vector <int>( h, h + ( sizeof h / sizeof h[0] ) ), vector <string>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int h[]                   = ;
			string s[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LiveConcert().maxHappiness( vector <int>( h, h + ( sizeof h / sizeof h[0] ) ), vector <string>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int h[]                   = ;
			string s[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LiveConcert().maxHappiness( vector <int>( h, h + ( sizeof h / sizeof h[0] ) ), vector <string>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int h[]                   = ;
			string s[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LiveConcert().maxHappiness( vector <int>( h, h + ( sizeof h / sizeof h[0] ) ), vector <string>( s, s + ( sizeof s / sizeof s[0] ) ) );
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
