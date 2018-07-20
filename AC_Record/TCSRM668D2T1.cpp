//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class VerySecureEncryption {
public:
    string encrypt( string message, vector <int> key, int K );
};
string VerySecureEncryption::encrypt(string message, vector <int> key, int K) {
    string ch1 = message;
	int l = message.size();
	string ch2 = "";
	for(int i = 1; i <= l; i++) ch2 += " ";
	for(int i = 0; i < l; i++) ch1[i] = message[i];
	for(int i = 1; i <= K; i++){
		for(int j = 0; j < l; j++)
			ch2[key[j]] = ch1[j];
		for(int j = 0; j < l; j++) ch1[j] = ch2[j];
	}
	return ch1;
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
			string message            = "abc";
			int key[]                 = {1,2,0};
			int K                     = 1;
			string expected__         = "cab";

			clock_t start__           = clock();
			string received__         = VerySecureEncryption().encrypt( message, vector <int>( key, key + ( sizeof key / sizeof key[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string message            = "abcde";
			int key[]                 = {4, 3, 2, 1, 0};
			int K                     = 1;
			string expected__         = "edcba";

			clock_t start__           = clock();
			string received__         = VerySecureEncryption().encrypt( message, vector <int>( key, key + ( sizeof key / sizeof key[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string message            = "abcde";
			int key[]                 = {4, 3, 2, 1, 0};
			int K                     = 2;
			string expected__         = "abcde";

			clock_t start__           = clock();
			string received__         = VerySecureEncryption().encrypt( message, vector <int>( key, key + ( sizeof key / sizeof key[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string message            = "uogcodlk";
			int key[]                 = {4, 3, 6, 2, 5, 1, 0, 7};
			int K                     = 44;
			string expected__         = "goodluck";

			clock_t start__           = clock();
			string received__         = VerySecureEncryption().encrypt( message, vector <int>( key, key + ( sizeof key / sizeof key[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			string message            = ;
			int key[]                 = ;
			int K                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = VerySecureEncryption().encrypt( message, vector <int>( key, key + ( sizeof key / sizeof key[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			string message            = ;
			int key[]                 = ;
			int K                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = VerySecureEncryption().encrypt( message, vector <int>( key, key + ( sizeof key / sizeof key[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string message            = ;
			int key[]                 = ;
			int K                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = VerySecureEncryption().encrypt( message, vector <int>( key, key + ( sizeof key / sizeof key[0] ) ), K );
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
