//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class RelationClassifier {
public:
    string isBijection( vector <int> domain, vector <int> range );
};
int reflect[110], used[110];
string RelationClassifier::isBijection(vector <int> domain, vector <int> range) {
    int n = domain.size();
    memset(reflect, 255, sizeof(reflect));
    memset(used, 255, sizeof(used));
    for(int i = 0; i < n; i++){
        if(reflect[domain[i]] != -1 && reflect[domain[i]] != range[i]) return "Not";
        if(used[range[i]] != -1 && reflect[domain[i]] != range[i]) return "Not";
        reflect[domain[i]] = range[i];
        used[range[i]] = 1;
    }
    return "Bijection";
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
			int domain[]              = {1, 1};
			int range[]               = {2, 3};
			string expected__         = "Not";

			clock_t start__           = clock();
			string received__         = RelationClassifier().isBijection( vector <int>( domain, domain + ( sizeof domain / sizeof domain[0] ) ), vector <int>( range, range + ( sizeof range / sizeof range[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int domain[]              = {4, 5};
			int range[]               = {2, 2};
			string expected__         = "Not";

			clock_t start__           = clock();
			string received__         = RelationClassifier().isBijection( vector <int>( domain, domain + ( sizeof domain / sizeof domain[0] ) ), vector <int>( range, range + ( sizeof range / sizeof range[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int domain[]              = {1};
			int range[]               = {2};
			string expected__         = "Bijection";

			clock_t start__           = clock();
			string received__         = RelationClassifier().isBijection( vector <int>( domain, domain + ( sizeof domain / sizeof domain[0] ) ), vector <int>( range, range + ( sizeof range / sizeof range[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int domain[]              = {1, 2, 3, 4, 5};
			int range[]               = {1, 2, 3, 4, 5};
			string expected__         = "Bijection";

			clock_t start__           = clock();
			string received__         = RelationClassifier().isBijection( vector <int>( domain, domain + ( sizeof domain / sizeof domain[0] ) ), vector <int>( range, range + ( sizeof range / sizeof range[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int domain[]              = {14, 12, 10, 13, 20, 18, 9, 17, 14, 9};
			int range[]               = {18, 6, 8, 15, 2, 14, 10, 13, 13, 15};
			string expected__         = "Not";

			clock_t start__           = clock();
			string received__         = RelationClassifier().isBijection( vector <int>( domain, domain + ( sizeof domain / sizeof domain[0] ) ), vector <int>( range, range + ( sizeof range / sizeof range[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int domain[]              = ;
			int range[]               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RelationClassifier().isBijection( vector <int>( domain, domain + ( sizeof domain / sizeof domain[0] ) ), vector <int>( range, range + ( sizeof range / sizeof range[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int domain[]              = ;
			int range[]               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RelationClassifier().isBijection( vector <int>( domain, domain + ( sizeof domain / sizeof domain[0] ) ), vector <int>( range, range + ( sizeof range / sizeof range[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int domain[]              = ;
			int range[]               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RelationClassifier().isBijection( vector <int>( domain, domain + ( sizeof domain / sizeof domain[0] ) ), vector <int>( range, range + ( sizeof range / sizeof range[0] ) ) );
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
