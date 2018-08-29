//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class EqualSums {
public:
    int count( vector <string> board );
};
const int MOD = 1000000007;
int line, relation[110][110];

int visited[110], rec[110], vis[110];
int MINNUM;
bool dfs(int x) {
    if(x >= line) {
        for(int i = 0; i < line; i++) {
            if(relation[x][i] == -1) continue;
            if(vis[i] && relation[x][i] - rec[x] != rec[i]) return false;
            if(vis[i]) continue;
            if(relation[x][i] - rec[x] < MINNUM) return false;
            vis[i] = 1;
            rec[i] = relation[x][i] - rec[x];
            if(!dfs(i)) return false;
        }
        return true;
    }
    if(x < line) {
        for(int i = line; i < line * 2; i++) {
            if(relation[x][i] == -1) continue;
            if(vis[i] && relation[x][i] - rec[x] != rec[i]) return false;
            if(vis[i]) continue;
            if(relation[x][i] - rec[x] < 0) return false;
            vis[i] = 1;
            rec[i] = relation[x][i] - rec[x];
            if(!dfs(i)) return false;
        }
        return true;
    }
    return false;
}
void dfs2(int x) {
    visited[x] = 1;
    for(int i = 0; i < 2 * line; i++) {
        if(visited[i]) continue;
        if(relation[x][i] == -1) continue;
        dfs2(i);
    }
    return;
}
int work(int tt) {
    int ans = 1;
    memset(visited, 0, sizeof(visited));
    memset(rec, 0, sizeof(rec));
    for(int i = 0; i < line; i++) {
        if(visited[i]) continue;
        int t = 0;
        for(int k = tt; k < 10; k++) {
			for(int ll = 0; ll < 2 * line; ll++) vis[ll] = visited[ll];
            vis[i] = 1;
            rec[i] = k;
            if(dfs(i)) {
				t++;
			}
            vis[i] = 0;
        }
        dfs2(i);
        ans = 1LL * ans * t % MOD;
    }
    return ans;
}


int EqualSums::count(vector <string> board) {
    line = board.size();
    memset(relation, 255, sizeof(relation));
    for(int i = 0; i < line; ++i)
        for(int j = 0; j < line; ++j)
            if(board[i][j] != '-') {
                relation[i][line + j] = board[i][j] - '0';
                relation[line + j][i] = board[i][j] - '0';
            }
    int _ = -1, ans = 0;
    for(int i = 0; i < 2; i++) {
        MINNUM = i;
        _ *= -1;
        ans = (0LL +  (ans  + (1LL * _ * work(i) % MOD) % MOD) % MOD + MOD) % MOD;
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
			string board[]            = {"1-",  "-2"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = EqualSums().count( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string board[]            = {"123",  "4--",  "--9"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = EqualSums().count( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string board[]            = {"9--",  "-9-",  "--9"};
			int expected__            = 271;

			clock_t start__           = clock();
			int received__            = EqualSums().count( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string board[]            = {"11",  "12"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EqualSums().count( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string board[]            = {"-4--",  "-0-2",  "--1-",  "4---"} ;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = EqualSums().count( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string board[]            = {"--2",  "02-",  "-10"} ;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EqualSums().count( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			string board[]            = {"----------1---------------0-----7-----------------",  "-----4--------------------------------------------",  "--------5-------------5-3---5---------------6-----",  "-------2----------1-------------------------------",  "-----4--------------------------------------------",  "-----3--------------------------------------------",  "-6----------5-------------------------------------",  "-------------------------------7---5----------6---",  "--------6-------------6-4---6---------------7-----",  "-------------4----------------5-------------------",  "3------------------------------------------6------",  "3------------------------------------------6------",  "-------------4----------------5-------------------",  "---------------2-------------------------3--------",  "--2------------------------------------------2----",  "---8---------------1-------------------3----------",  "---------------3----------------------------------",  "----7----------------5---0-----------------------5",  "----------------5-------------------------3-----1-",  "----------1---------------0-----7-----------------",  "-------------5----------------6-------------------",  "-7----------6-------------------------------------",  "---8---------------1-------------------3----------",  "-----------------------3--------------------------",  "----8----------------6---1-----------------------6",  "------------------------------------------4-----2-",  "-----------5---------------5----------------------",  "-----------------------------6--------------------",  "----8----------------6---1-----------------------6",  "----------------5-------------------------3-----1-",  "-------------------------------6---4--2-------5---",  "-6----------5-------------------------------------",  "--------5-------------5-3---5---------------6-----",  "-------------5----------------6-------------------",  "-----3--------------------------------------------",  "---------------2-------------------------3--------",  "---------4---------------------------6------------",  "-------------------------------6---4--2-------5---",  "------2-------------1------------22---------------",  "--------5-------------5-3---5---------------6-----",  "-----------5--3------------5----------------------",  "--2------------------------------------------2----",  "---------5---------------------------7------------",  "-------------4----------------5-------------------",  "-----------------5------------------4---6------2--",  "-------------------------------6---4--2-------5---",  "-----------------------2--------------------------",  "----------------6-------------------------4-----2-",   "-------------------------------6---4--2-------5---",  "--------5-------------5-3---5---------------6-----"};
			int expected__            = 45094393;

			clock_t start__           = clock();
			int received__            = EqualSums().count( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases
      case 7: {
			string board[]            = {"1-", "-1"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = EqualSums().count( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
          case 8: {
			string board[]            = {"2-", "-2"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = EqualSums().count( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 9: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EqualSums().count( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
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
