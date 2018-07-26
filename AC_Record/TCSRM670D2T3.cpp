//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class Treestrat {
public:
    int roundcnt( vector <int> tree, vector <int> A, vector <int> B );
};
int lp, f[60], lin[110], nxt[110];
inline void add(int x, int y) {lin[++lp] = y; nxt[lp] = f[x]; f[x] = lp; return; }
int step[60], n, ans, step2[60];
int lq, rq, q[110];
void bfs(int x){
	lq = 0;
	rq = 1;
	q[1] = x;
	step[x] = 0;
	while(lq < rq){
		lq++;
		int t = q[lq];
		for(int i = f[t]; i; i = nxt[i]){
			if(step[lin[i]] <= step[t] + 1) continue;
			step[lin[i]] = step[t] + 1;
			rq++;
			q[rq] = lin[i];
		}
	}
	return;
}
int bfs2(int x){
	for(int i = 0; i < n; i++) step2[i] = 10010;
	lq = 0;
	rq = 1;
	q[1] = x;
	step2[x] = 0;
	while(lq < rq){
		lq++;
		int t = q[lq];
		for(int i = f[t]; i; i = nxt[i]){
			if(step2[lin[i]] <= step2[t] + 1) continue;
			step2[lin[i]] = step2[t] + 1;
			rq++;
			q[rq] = lin[i];
		}
	}
	int re = 0;
	for(int i = 0; i < n; i++){
		if(step2[i] < step[i]) re = max(re, step[i]);
	}
	return re;
}
int Treestrat::roundcnt(vector <int> tree, vector <int> A, vector <int> B) {
    lp = 0;
	memset(f, 0, sizeof(f));
	n = tree.size() + 1;
	for(int i = 1; i < n; i++){
		add(i, tree[i - 1]);
		add(tree[i - 1], i);
	}
	for(int i = 0; i < n; i++) step[i] = 10010;
	int nb = B.size();
	for(int i = 0; i < nb; i++) bfs(B[i]);
	ans = 10010;
	int na = A.size();
	for(int i = 0; i < na; i++) ans = min(ans, bfs2(A[i]));
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
			int tree[]                = {0};
			int A[]                   = {0};
			int B[]                   = {1};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int tree[]                = {0,1};
			int A[]                   = {1};
			int B[]                   = {2};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int tree[]                = {0,0,0,3,4};
			int A[]                   = {2};
			int B[]                   = {1};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int tree[]                = {0,0,0,3,4,2};
			int A[]                   = {1};
			int B[]                   = {6};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int tree[]                = {0,0,0,3,4,2};
			int A[]                   = {1};
			int B[]                   = {6,5};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int tree[]                = {0,0,0,3,4,2};
			int A[]                   = {4,1};
			int B[]                   = {3,6};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int tree[]                = ;
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int tree[]                = ;
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int tree[]                = ;
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
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
