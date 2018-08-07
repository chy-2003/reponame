//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class XorLists {
public:
    int countLists( vector <int> s, int m );
};
const int MAXN = 10, MAXLOG = 32;
int n;
int dp[MAXLOG][2][1 << MAXN];
int XorLists::countLists(vector <int> s, int m) {
    n = 0;
	for(;n * n < s.size(); n++);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				if((s[i * n + j] ^ s[j * n + k]) != s[i * n + k]) {
//					printf("%d %d %d\n", i, j, k);
//					printf("%d %d %d\n", s[i * n + j], s[j * n + k], s[i * n + k]);
					return 0;
				}
//	printf("*\n");
	memset(dp, 0, sizeof(dp));
	dp[31][0][(1 << n) - 1] = 1;
	for(int i = 31; i > 0; i--) 
		for(int j = 0; j <= 1; j++) 
			for(int k = 0; k < 1 << n; k++) {
				if(dp[i][j][k] == 0) continue;
				for(int i1 = 0; i1 <= 1; i1++) {
					int b = 0;
					for(int l = 0; l < n; l++)
						if((k >> l) & 1) 
						if((((m >> (i - 1)) & 1) == 0) && (((s[l] >> (i - 1)) & 1 ^ i1) == 1)) {
							b = 1;
							break;
						}
					if(b == 1) continue;
					int t = k;
//					printf("%d\n", t);
					for(int l = 0; l < n; l++)
						if((k >> l) & 1)
						if((((m >> (i - 1)) & 1) == 1) && (((s[l] >> (i - 1)) & 1 ^ i1) == 0)) t -= 1 << l;
					dp[i - 1][i1][t] += dp[i][j][k];
//					printf("%d %d %d %d\n", i - 1, i1, t, dp[i - 1][i1][t]);
				}
			}
	int ans = 0;
	for(int i = 0; i <= 1; i++)
		for(int j = 0; j < 1 << n; j++) ans += dp[0][i][j];
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
			int s[]                   = {0};
			int m                     = 10000;
			int expected__            = 10001;

			clock_t start__           = clock();
			int received__            = XorLists().countLists( vector <int>( s, s + ( sizeof s / sizeof s[0] ) ), m );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int s[]                   = {1};
			int m                     = 10000;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = XorLists().countLists( vector <int>( s, s + ( sizeof s / sizeof s[0] ) ), m );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int s[]                   = {0,1,2,  1,0,3,  2,3,0};
			int m                     = 5;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = XorLists().countLists( vector <int>( s, s + ( sizeof s / sizeof s[0] ) ), m );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int s[]                   = {0,3,  3,0};
			int m                     = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = XorLists().countLists( vector <int>( s, s + ( sizeof s / sizeof s[0] ) ), m );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int s[]                   = { 0,18955782,19774078,15197314,10559559,9167552,1059865,10395923,23165910,45583720, 18955782,0,820344,29809284,25173569,27974854,19993119,29335317,4212176,60207982, 19774078,820344,0,30039804,25991737,27678910,20813415,28515181,5030312,60438294, 15197314,29809284,30039804,0,4637893,7079490,16238747,7947665,25599828,38824426, 10559559,25173569,25991737,4637893,0,2802311,11603038,4161876,29383569,35040559, 9167552,27974854,27678910,7079490,2802311,0,10211033,1393619,32151830,37515176, 1059865,19993119,20813415,16238747,11603038,10211033,0,9342218,24205263,44540273, 10395923,29335317,28515181,7947665,4161876,1393619,9342218,0,33544901,36252795, 23165910,4212176,5030312,25599828,29383569,32151830,24205263,33544901,0,64419518, 45583720,60207982,60438294,38824426,35040559,37515176,44540273,36252795,64419518,0 };
			int m                     = 1000000000;
			int expected__            = 976248323;

			clock_t start__           = clock();
			int received__            = XorLists().countLists( vector <int>( s, s + ( sizeof s / sizeof s[0] ) ), m );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

        case 5: {
			int s[]                   = {0};
			int m                     = 4;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = XorLists().countLists( vector <int>( s, s + ( sizeof s / sizeof s[0] ) ), m );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 6: {
			int s[]                   = ;
			int m                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = XorLists().countLists( vector <int>( s, s + ( sizeof s / sizeof s[0] ) ), m );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int s[]                   = ;
			int m                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = XorLists().countLists( vector <int>( s, s + ( sizeof s / sizeof s[0] ) ), m );
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
