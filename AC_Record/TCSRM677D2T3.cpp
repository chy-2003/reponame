//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class PalindromePath {
public:
    int shortestLength( int n, vector <int> a, vector <int> b, string c );
};
int A[30][30][30];
int l, r, q[1000010][5];
int x, y;
int PalindromePath::shortestLength(int n, vector <int> a, vector <int> b, string c) {
    memset(A, 0, sizeof(A));
//	printf("%d\n", a.size());
    for(int i = 0; i < a.size(); i++) {
//        printf("%d %d %d\n", a[i] + 1, b[i] + 1, c[i] - 'a' + 1);
        A[a[i] + 1][b[i] + 1][c[i] + 1 - 'a'] = 1, A[b[i] + 1][a[i] + 1][c[i] + 1 - 'a'] = 1;
    }
//    cout << "ddd" << endl;
    for(int i = 1; i <= 26; i++) if(A[1][2][i]) return 1;
//    cout << "ff" << endl;
    l = 0; r = 1;
    q[1][0] = 0; q[1][1] = 1; q[1][2] = 2; q[1][3] = 0; q[1][4] = 0;
//    printf("*\n");
    while(l < r) {
        if(r > 1000010 - 20 * 20 * 26) break;
        l++;
//        printf("l=%d %d\n", l, r);
        x = q[l][1]; y = q[l][2];
		int ttt = 10000010;
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++) {
        		for(int i = 1; i <= 26; i++) {
                    if(A[x][j][i] == 0 || A[y][k][i] == 0) continue;
                    if(j == q[l][3] && k == q[l][4]) continue;
//                    printf("%d %d\n", l, r);
                    r++; q[r][0] = q[l][0] + 1; q[r][1] = j; q[r][2] = k; q[r][3] = x; q[r][4] = y;
//                    printf("%d\n", r);
                    if(j == k) ttt = min(ttt, q[r][0] * 2);
                    for(int l = 1; l <= 26; l++)
                        if(A[j][k][l]) ttt = min(ttt, q[r][0] * 2 + 1);
                }
			}
		if(ttt != 10000010) return ttt;
    }
    return -1;
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
			int n                     = 5;
			int a[]                   = {2,2,0,3,4};
			int b[]                   = {0,1,3,4,1};
			string c                  = "abxyx";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = PalindromePath().shortestLength( n, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), c );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int n                     = 5;
			int a[]                   = {2,2,0,3,4};
			int b[]                   = {0,1,3,4,1};
			string c                  = "abxyz";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = PalindromePath().shortestLength( n, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), c );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int n                     = 7;
			int a[]                   = {0,0,3,4,5,6};
			int b[]                   = {2,3,4,5,6,1};
			string c                  = "abaaaa";
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = PalindromePath().shortestLength( n, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), c );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int n                     = 6;
			int a[]                   = {0,0,3,4,5};
			int b[]                   = {2,3,4,5,1};
			string c                  = "abaaa";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = PalindromePath().shortestLength( n, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), c );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int n                     = 2;
			int a[]                   = {0};
			int b[]                   = {1};
			string c                  = "x";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PalindromePath().shortestLength( n, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), c );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int n                     = 20;
			int a[]                   = {18};
			int b[]                   = {19};
			string c                  = "z";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = PalindromePath().shortestLength( n, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), c );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 6: {
			int n                     = 14;
;
			int a[]                   = {11, 1,  9,  1,  9,  1, 10, 0,  5, 11, 8, 12, 11, 10,  5, 12,  4, 0, 13, 2,  7, 4, 10, 6, 13,  3, 7, 7, 9, 5, 6,  5,  3, 0, 8, 9, 9, 11,  4, 0, 13, 3,  2, 10, 4, 10, 10, 11};
			int b[]                   = { 1, 5, 12, 13, 10, 12, 13, 8, 12,  8, 9,  6,  3,  6, 13,  0, 12, 9, 12, 5, 13, 5, 11, 0, 11, 13, 0, 2, 3, 6, 4, 10, 12, 2, 1, 4, 2,  7, 10, 4,  8, 6, 10,  0, 1, 12,  1,  4};
			string c                  = "lqjtapexxljligpptlcwrudipippjofmrdbiooqnjaeljqge";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PalindromePath().shortestLength( n, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), c );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 7: {
			int n                     = ;
			int a[]                   = ;
			int b[]                   = ;
			string c                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PalindromePath().shortestLength( n, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), c );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int n                     = ;
			int a[]                   = ;
			int b[]                   = ;
			string c                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PalindromePath().shortestLength( n, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), c );
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
