//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class StringGame {
public:
    vector <int> getWinningStrings( vector <string> S );
};
int cnt[60][26];
int n, m;
int vis[60], cho[26];
vector<int> ans;
vector <int> StringGame::getWinningStrings(vector <string> S) {
    n = S.size();
    m = S[0].size();
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++)
            cnt[i][S[i][j] - 'a']++;
    ans.clear();
    for(int i = 0; i < n; i++) {
        int bb = 1;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            int che = 1;
            for(int k = 0; k < 26; k++)
                if(cnt[i][k] != cnt[j][k]) {
                    che = 0;
                    break;
                }
            if(che) {
                bb = 0;
                break;
            }
        }
        if(bb == 0) continue;
        memset(vis, 0, sizeof(vis));
        vis[i] = 1;
        memset(cho, 0, sizeof(cho));
        bb = 1;
        for(int k = 0; k < 26; k++) {
            int suc = 0;
            for(int j = 0; j < 26; j++) {
                if(cho[j]) continue;
                int b = 1;
                for(int l = 0; l < n; l++) 
                    if(vis[l] == 0 && cnt[i][j] < cnt[l][j]) {
                        b = 0;
                        break;
                    }
                if(b == 0) continue;
                suc = 1;
                cho[j] = 1;
                for(int l = 0; l < n; l++)
                    if(vis[l] == 0 && cnt[i][j] > cnt[l][j])
                        vis[l] = 1;
                break;
            }
            if(suc == 0) {
                bb = 0;
                break;
            }
        }
        if(bb) ans.push_back(i);
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
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			string S[]                = {"a", "b", "c", "d"};
			int expected__[]          = {0, 1, 2, 3 };

			clock_t start__           = clock();
			vector <int> received__   = StringGame().getWinningStrings( vector <string>( S, S + ( sizeof S / sizeof S[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 1: {
			string S[]                = {"aabbcc", "aaabbb", "aaaccc"};
			int expected__[]          = {1, 2 };

			clock_t start__           = clock();
			vector <int> received__   = StringGame().getWinningStrings( vector <string>( S, S + ( sizeof S / sizeof S[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 2: {
			string S[]                = {"ab", "ba"};
			int expected__[]          = { };

			clock_t start__           = clock();
			vector <int> received__   = StringGame().getWinningStrings( vector <string>( S, S + ( sizeof S / sizeof S[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 3: {
			string S[]                = {"xaocxsss", "oooxsoas", "xaooosss", "xaocssss", "coxaosxx"};
			int expected__[]          = {1, 3, 4 };

			clock_t start__           = clock();
			vector <int> received__   = StringGame().getWinningStrings( vector <string>( S, S + ( sizeof S / sizeof S[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			string S[]                = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = StringGame().getWinningStrings( vector <string>( S, S + ( sizeof S / sizeof S[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}*/
/*      case 5: {
			string S[]                = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = StringGame().getWinningStrings( vector <string>( S, S + ( sizeof S / sizeof S[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}*/
/*      case 6: {
			string S[]                = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = StringGame().getWinningStrings( vector <string>( S, S + ( sizeof S / sizeof S[0] ) ) );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
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
