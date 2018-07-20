//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class OrderOfOperationsDiv2 {
public:
    int minTime( vector <string> s );
};
int n;
int rec[20];
int l, r, q[1 << 23], q_used[1 << 23];
int dp[1 << 21];
int len;
int OrderOfOperationsDiv2::minTime(vector <string> s) {  
	n = s.size();
	len = s[0].size();
	for(int i = 0; i < n; i++){
		rec[i] = 0;
		for(int j = 0; j < len; j++)
			if(s[i][j] == '1') rec[i] |= (1 << j);
	}
	memset(dp, 255, sizeof(dp));
	dp[0] = 0;
	l = 0; r = 1; q[1] = 0; q_used[1] = 0;
	while(l < r){
		l++;
		int rec_vis = q[l];
		int rec_used = q_used[l];
		for(int i = 0; i < n; i++){
			if((rec_vis >> i) & 1) continue;
			int x = rec_vis | (1 << i);
			int y = rec_used | rec[i];
			int tt = 0;
			for(int j = 0; j < len; j++)
				if(((y >> j) & 1) == 1 && ((rec_used >> j) & 1) == 0) tt++;
			tt = tt * tt;
			if(dp[x] == -1 || dp[x] > dp[rec_vis] + tt){
				dp[x] = dp[rec_vis] + tt;
				r++;
				q[r] = x;
				q_used[r] = y;
			}
		}
	}
	return dp[(1 << n) - 1];
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
			string s[]                = {  "111",  "001",  "010" };
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = OrderOfOperationsDiv2().minTime( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string s[]                = {  "11101",  "00111",  "10101",  "00000",  "11000" };
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = OrderOfOperationsDiv2().minTime( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string s[]                = {   "11111111111111111111" };
			int expected__            = 400;

			clock_t start__           = clock();
			int received__            = OrderOfOperationsDiv2().minTime( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string s[]                = {   "1000",   "1100",   "1110" };
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = OrderOfOperationsDiv2().minTime( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string s[]                = {   "111",   "111",   "110",   "100" };
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = OrderOfOperationsDiv2().minTime( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			string s[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = OrderOfOperationsDiv2().minTime( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string s[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = OrderOfOperationsDiv2().minTime( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string s[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = OrderOfOperationsDiv2().minTime( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ) );
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
