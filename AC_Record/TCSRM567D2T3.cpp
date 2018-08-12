//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class MountainsEasy {
public:
    int countPlacements( vector <string> picture, int N );
};
const long long mod = 1000000009;
long long n, m;
long long hight[60];
long long C[60][60];
long long sum, num;
long long fac[60];
long long f[60][60];
int MountainsEasy::countPlacements(vector <string> picture, int N) {
    n = picture.size(); m = picture[0].size();
    memset(hight, 0, sizeof(hight));
    memset(C, 0, sizeof(C));
    C[0][0] =1;
    for(int i = 1; i <= N; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
    
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            if(picture[i][j] == 'X')
                hight[j] = max(hight[j], n - i);

    sum = 0; num = 0;
    for(int i = 0; i < m; i++) sum += hight[i];

    fac[0] = 1;
    for(int i = 1; i <= N; i++) fac[i] = (fac[i - 1] * sum) % mod;

    if(m == 1) {
		if(hight[0] > 0) num = 1; 
	} else {
        if(hight[0] >= hight[1] && hight[0] > 0) num++;
        for(int i = 1; i < m - 1; i++) 
            if(hight[i] >= hight[i - 1] && hight[i] >= hight[i + 1] && hight[i] > 0) num++;
        if(hight[m - 1] >= hight[m - 2] && hight[m - 1] > 0) num++;
    }

    memset(f, 0, sizeof(f));
    for(int i = 1; i <= N; i++) f[i][1] = 1;
    for(int j = 2; j <= num; j++)
        for(int i = 1; i <= N; i++) 
            f[i][j] = ((f[i - 1][j - 1] + f[i - 1][j]) % mod * j) % mod;

    long long ans = 0, t;
    for(int i = num; i <= N; i++) {
       t = C[N][i] * f[i][num] % mod * fac[N - i] % mod; 
       if((i - num) % 2 == 0) ans = (ans + t) % mod; else ans = ((ans - t) % mod + mod) % mod;
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
			string picture[]          = {"X.",  "XX"};
			int N                     = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string picture[]          = {"X.",  "XX"};
			int N                     = 2;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string picture[]          = {"X.X",  "XXX"};
			int N                     = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string picture[]          = {"X.X",  "XXX"};
			int N                     = 3;
			int expected__            = 24;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string picture[]          = {"......",  "X..X..",  "XXXXXX",  "XXXXXX"};
			int N                     = 3;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string picture[]          = {"......",  "X..X..",  "XXXXXX",  "XXXXXX"};
			int N                     = 4;
			int expected__            = 300;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			string picture[]          = {"....X...X..",  "...XXX.XXX.",  "XXXXXXXXXXX"};
			int N                     = 10;
			int expected__            = 764632413;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

        case 7: {
			string picture[]          = {"X"};
			int N                     = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
        case 8: {
			string picture[]          = {"...X....X", "..XXX..XX"};
			int N                     = 3;
			int expected__            = 36;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 9: {
			string picture[]          = ;
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MountainsEasy().countPlacements( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), N );
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
