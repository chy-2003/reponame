//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

template<class T> void checkmin(T &a,const T &b) { if (b<a) a=b; } 
template<class T> void checkmax(T &a,const T &b) { if (b>a) a=b; }

class MazeWithKeys {
public:
    int startingPoints( vector <string> a ) ;
};
const int bz[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int n, m, ans;
char ma[60][60];
int endx, endy;
int l, r, q[5100][2];
int key, door;
int touch[50][2];
char ma2[60][60];
void pre_bfs() {
    l = 0;
    r = 1;
    q[1][0] = endx;
    q[1][1] = endy;
    while(l < r) {
        l++;
        for(int i = 0; i < 4; ++i) {
            endx = q[l][0] + bz[i][0];
            endy = q[l][1] + bz[i][1];
            if(ma[endx][endy] == '#' || ma[endx][endy] == '*') continue;
            if(ma[endx][endy] >= 'A' && ma[endx][endy] <= 'Z') continue;
            ma[endx][endy] = '*';
            r++;
            q[r][0] = endx; q[r][1] = endy;
        }
    }
    return;
}
inline void clone() {
    for(int i = 0; i <= n + 1; ++i) 
        for(int j = 0; j <= m + 1; ++j) 
            ma2[i][j] = ma[i][j];
    return;
}
bool bfs(int x, int y) {
    clone();
    ma2[x][y] = '#';
    l = r = 0;
    key = door = 0;
    r = 1;
    q[1][0] = x; q[1][1] = y;
    while(l < r) {
        l++;
        for(int i = 0; i < 4; ++i) {
            x = q[l][0] + bz[i][0];
            y = q[l][1] + bz[i][1];
            if(ma2[x][y] == '#') continue; else
            if(ma2[x][y] == '*') return true; else
            if(ma2[x][y] >= 'a' && ma2[x][y] <= 'z') {
                key |= 1 << (ma2[x][y] - 'a');
                if(door & (1 << (ma2[x][y] - 'a'))) {
                    door ^= (1 << (ma2[x][y] - 'a'));
                    ++r;
                    q[r][0] = touch[ma2[x][y] - 'a'][0];
                    q[r][1] = touch[ma2[x][y] - 'a'][1];
                }
                ++r;
                q[r][0] = x; q[r][1] = y;
                ma2[x][y] = '#';
            } else
            if(ma2[x][y] >= 'A' && ma2[x][y] <= 'Z') {
                if(key & (1 << (ma2[x][y] - 'A'))) {
            	    ++r;
                	q[r][0] = x; q[r][1] = y;
                	ma2[x][y] = '#';
                } else {
                    door |= (1 << (ma2[x][y] - 'A'));
                    touch[ma2[x][y] - 'A'][0] = x; touch[ma[x][y] - 'A'][1] = y;
                    ma2[x][y] = '#';
                }
            } else
            if(ma2[x][y] == '.') {
                ++r;
                q[r][0] = x; q[r][1] = y;
                ma2[x][y] = '#';
            }
        }
    }
    return false;
}
void init() {
    for(int i = 1; i <= n; ++i)
    	for(int j = 1; j <= m; ++j)
    		if(ma[i][j] == '*') {
    			endx = i;
    			endy = j;
    			return;
    		}
    return;
}
int MazeWithKeys::startingPoints(vector <string> a) {
    n = a.size();
    m = a[0].size();
    for(int i = 1; i <= n; ++i) {
    	for(int j = 1; j <= m; ++j) ma[i][j] = a[i - 1][j - 1];
    	ma[i][m + 1] = '#';
    	ma[i][0] = '#';
    }
    for(int i = 1; i <= m; ++i) {
        ma[0][i] = '#';
        ma[n + 1][i] = '#';
    }
    ma[0][0] = ma[n + 1][0] = ma[0][m + 1] = ma[n + 1][m + 1] = '#';
    init();
    pre_bfs();
    ans = 0;
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= m; ++j) {
            if(ma[i][j] != '.') continue;
            if(bfs(i, j)) ans++;
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
			string a[]                = {"...#.A.",  ".#B#.#.",  ".#.#.#.",  ".#.#.#.",  ".#b#.#.",  "a#...#*"} ;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = MazeWithKeys().startingPoints( vector <string>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string a[]                = {"..*",  ".a.",  "A.."} ;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MazeWithKeys().startingPoints( vector <string>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string a[]                = {".A*C.",  ".#B#.",  ".#.#.",  "a..b."} ;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = MazeWithKeys().startingPoints( vector <string>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string a[]                = {"a#a#*",  "#..#.",  "a..A."} ;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = MazeWithKeys().startingPoints( vector <string>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			string a[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MazeWithKeys().startingPoints( vector <string>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			string a[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MazeWithKeys().startingPoints( vector <string>( a, a + ( sizeof a / sizeof a[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string a[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MazeWithKeys().startingPoints( vector <string>( a, a + ( sizeof a / sizeof a[0] ) ) );
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
