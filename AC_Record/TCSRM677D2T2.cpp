#include <bits/stdc++.h>
using namespace std;

class FourStrings {
public:
    int shortestLength( string a, string b, string c, string d );
};
string ss[4];
char ch[50];
int doit(string a, string b, string c, string d) {
    int l1 = a.size(), l2 = b.size(), l3 = c.size(), l4 = d.size();
    int ttt;
    ch[0] = '\0';
    int L = strlen(ch);
    for(int i = 0; i < l1; i++) ch[i] = a[i];
    ch[l1] = '\0';
    L = strlen(ch);
    ttt = 0;
    if(L >= l2) {
        for(int i = 0; i <= L - l2; i++) {
            ttt = 1;
            for(int j = i; j <= i + l2 - 1; j++) {
                if(ch[j] != b[j - i]) { ttt = 0; break; }
            }
            if(ttt) break;
        }
    }
    if(ttt == 0)
    for(int i = min(L, l2); i >= 0; i--) {
        int bb = 1;
        for(int j = 1; j <= i; j++) if(ch[L - i + j - 1] != b[j - 1]) { bb = 0; break; }
        if(bb) {
            for(int j = 0; j < l2; j++) ch[L - i + j] = b[j];
            ch[L - i + l2] = '\0';
            break;
        }
    }
    L = strlen(ch);
    ttt = 0;
    if(L >= l3) {
        for(int i = 0; i <= L - l3; i++) {
            ttt = 1;
            for(int j = i; j <= i + l3 - 1; j++) {
                if(ch[j] != c[j - i]) { ttt = 0; break; }
            }
            if(ttt) break;
        }
    }
    if(ttt == 0)
    for(int i = min(L, l3); i >= 0; i--) {
        int bb = 1;
        for(int j = 1; j <= i; j++) {
            if(ch[L - i + j - 1] != c[j - 1]) { bb = 0; break; }
        }
        if(bb) {
            for(int j = 0; j < l3; j++) ch[L - i + j] = c[j];
            ch[L - i + l3] = '\0';
            break;
        }
    }
    L = strlen(ch);
    ttt = 0;
    if(L >= l4) {
        for(int i = 0; i <= L - l4; i++) {
            ttt = 1;
            for(int j = i; j <= i + l4 - 1; j++) {
                if(ch[j] != d[j - i]) { ttt = 0; break; }
            }
            if(ttt) break;
        }
    }
    if(ttt == 0)
    for(int i = min(L, l4); i >= 0; i--) {
        int bb = 1;
        for(int j = 1; j <= i; j++) if(ch[L - i + j - 1] != d[j - 1]) { bb = 0; break; }
        if(bb) {
            for(int j = 0; j < l4; j++) ch[L - i + j] = d[j];
            ch[L - i + l4] = '\0';
            break;
        }
    }
    L = strlen(ch);
    return L;
}
int FourStrings::shortestLength(string a, string b, string c, string d) {
    ss[0] = a; ss[1] = b; ss[2] = c; ss[3] = d;
    int ans = 1000010;
    for(int i = 0; i <= 3; i++) {
        for(int j = 0; j <= 3; j++) {
            if(i == j) continue;
            for(int k = 0; k <= 3; k++) {
                if(k == i || k == j) continue;
                for(int l = 0; l <= 3; l++) {
                    if(l == i || l == j || l == k) continue;
                    ans = min(ans, doit(ss[i], ss[j], ss[k], ss[l]));
                }
            }
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
			string a                  = "abc";
			string b                  = "ab";
			string c                  = "bc";
			string d                  = "b";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = FourStrings().shortestLength( a, b, c, d );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string a                  = "a";
			string b                  = "bc";
			string c                  = "def";
			string d                  = "ghij";
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = FourStrings().shortestLength( a, b, c, d );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string a                  = "top";
			string b                  = "coder";
			string c                  = "opco";
			string d                  = "pcode";
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = FourStrings().shortestLength( a, b, c, d );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string a                  = "thereare";
			string b                  = "arelots";
			string c                  = "lotsof";
			string d                  = "ofcases";
			int expected__            = 19;

			clock_t start__           = clock();
			int received__            = FourStrings().shortestLength( a, b, c, d );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string a                  = "aba";
			string b                  = "b";
			string c                  = "b";
			string d                  = "b";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = FourStrings().shortestLength( a, b, c, d );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string a                  = "x";
			string b                  = "x";
			string c                  = "x";
			string d                  = "x";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FourStrings().shortestLength( a, b, c, d );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			string a                  = ;
			string b                  = ;
			string c                  = ;
			string d                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FourStrings().shortestLength( a, b, c, d );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string a                  = ;
			string b                  = ;
			string c                  = ;
			string d                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FourStrings().shortestLength( a, b, c, d );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			string a                  = ;
			string b                  = ;
			string c                  = ;
			string d                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FourStrings().shortestLength( a, b, c, d );
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
