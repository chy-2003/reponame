//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class CentaurCompany {
public:
    double getvalue( vector <int> a, vector <int> b );
};
const long long MAXN = 100;
long long used_space, f[MAXN], lin[MAXN], nxt[MAXN];
long long dp1[MAXN][MAXN][MAXN][2], dp2[MAXN][MAXN][2];
long long n, size[MAXN];
inline void init() {
    used_space = 0;
    memset(f, 0, sizeof(f));
    memset(dp1, 0, sizeof(dp1));
    memset(size, 0, sizeof(size));
    return;
}
inline void add(long long x, long long y) {
    used_space++;
    lin[used_space] = y;
    nxt[used_space] = f[x];
    f[x] = used_space;
    return;
}
void dfs(int pos, int fa) {
    size[pos] = 1;
    dp1[pos][0][0][0] = dp1[pos][1][1][1] = 1;
    for(int t = f[pos]; t; t = nxt[t]) {
        if(lin[t] == fa) continue;
        dfs(lin[t], pos);
        memset(dp2, 0, sizeof(dp2));
        for(int i = 0; i <= size[lin[t]]; i++) 
            for(int j = 0; j <= size[lin[t]]; j++)
                for(int ii = 0; ii <= size[pos]; ii++)
                    for(int jj = 0; jj <= size[pos]; jj++) {
                        dp2[i + ii][j + jj][0] += dp1[pos][ii][jj][0] * (dp1[lin[t]][i][j][0] + dp1[lin[t]][i][j][1]);
                        dp2[i + ii][j + jj][1] += dp1[pos][ii][jj][1] * dp1[lin[t]][i][j][0];
                        dp2[i + ii][j + jj - 1][1] += dp1[pos][ii][jj][1] * dp1[lin[t]][i][j][1];
                    }
        size[pos] += size[lin[t]];
        for(int i = 0; i <= size[pos]; i++) 
            for(int j = 0; j <= size[pos]; j++) {
                dp1[pos][i][j][0] = dp2[i][j][0];
                dp1[pos][i][j][1] = dp2[i][j][1];
            }
    }
    return;
}
double CentaurCompany::getvalue(vector <int> a, vector <int> b) {
    init();
    n = a.size() + 1;
    for(int i = 0; i < n - 1; i++) add(a[i], b[i]), add(b[i], a[i]);
    dfs(1, 0);
    long long cnt = 0LL;
    for(int x = 0; x <= n; x++)
        for(int y = 0; y <= n; y++) 
            cnt += max(0LL, 2LL * (y - 1) - x) * (dp1[1][x][y][0] + dp1[1][x][y][1]);
    return 2.0 * cnt / (1.0 * (1LL << n));
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 ) return 0; return fabs( result-expected ) / fabs( expected ); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( topcoder_fequ( expected, received ) ) {
			verdict = "PASSED";
			double rerr = moj_relative_error( expected, received ); 
			if ( rerr > 0 ) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int a[]                   = {1};
			int b[]                   = {2};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int a[]                   = {1,1,1};
			int b[]                   = {2,3,4};
			double expected__         = 0.125;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int a[]                   = {1,2,3,2,2};
			int b[]                   = {2,3,4,5,6};
			double expected__         = 0.375;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int a[]                   = {1,2,3,4,5,6,7,8,9};
			int b[]                   = {2,3,4,5,6,7,8,9,10};
			double expected__         = 0.41796875;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int a[]                   = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int b[]                   = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
			double expected__         = 15.500000001076842;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int a[]                   = {10, 7, 2, 5, 6, 2, 4, 9, 7};
			int b[]                   = {8, 10, 10, 4, 1, 6, 2, 2, 3};
			double expected__         = 0.646484375;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int a[]                   = ;
			int b[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int a[]                   = ;
			int b[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int a[]                   = ;
			int b[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
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
