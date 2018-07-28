//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class VampireTreeDiv2 {
public:
    int countMinSamples( vector <int> A, vector <int> B );
};
const long long mod = 1000000007;
long long n, cnt;
long long lp, f[1010], lin[2010], nxt[2010], deep[1010];
inline void add(long long x, long long y) { lin[++lp] = y; nxt[lp] = f[x]; f[x] = lp; return; }
void get_deep(long long pos, long long father){
    deep[pos] = deep[father] + 1;
    for(long long t = f[pos]; t; t = nxt[t])
        if(deep[lin[t]] < deep[pos] + 1 && lin[t] != father) get_deep(lin[t], pos);
    return;
}
struct Node{
    long long deep, pos;
    Node(long long deep_ = 0, long long pos_ = 0) { deep = deep_; pos = pos_; return; }
};
Node aa[1010];
bool cmp(Node x, Node y){
    return x.deep > y.deep;
}
long long rec[1010], recc[1010];
long long caculated[1010];
long long dp[1010][2], c[1010][2];
long long t;
long long ans, minnum;
int VampireTreeDiv2::countMinSamples(vector <int> A, vector <int> B) {
    n = A.size();
    cnt = 0;
    memset(f, 0, sizeof(f));
    lp = 0;
    for(long long i = 0; i < n; i++){
        add(A[i], i + 1);
        if(B[i] != -1){
            add(B[i], i + 1);
            rec[++cnt] = i + 1;
        }
    }
    ans = 0; minnum = 100010;
    memset(deep, 0, sizeof(deep));
    get_deep(0, 0);
    for(long long i = 0; i <= n; i++) aa[i] = Node(deep[i], i);
    sort(aa, aa + n + 1, cmp);
//    for(long long i = 0; i <= n; i++) printf("%lld ", aa[i].pos); printf("\n");
    for(long long i = 0; i < (1 << cnt); i++){
        memset(recc, 0, sizeof(recc));
        memset(caculated, 0, sizeof(caculated));
        for(long long j = 1; j <= cnt; j++)
            if((i >> (j - 1)) & 1)
                recc[rec[j]] = 1; else recc[rec[j]] = 2;
        for(long long j = 0; j <= n; j++){
            t = aa[j].pos;
            dp[t][0] = 0; dp[t][1] = 1;
            c[t][0] = 1; c[t][1] = 1;
            for(long long k = f[t]; k; k = nxt[k]){
                if(caculated[lin[k]]){
                    if(dp[lin[k]][1] > 100000){
                        dp[t][0] = 100010;
                        c[t][0] = 0;
                    }
                    continue;
                }
                if(recc[lin[k]] != 0) caculated[lin[k]] = 1;
                dp[t][0] += dp[lin[k]][1];
                c[t][0] = (c[t][0] * c[lin[k]][1]) % mod;
                if(dp[lin[k]][0] < dp[lin[k]][1]){
                    dp[t][1] += dp[lin[k]][0];
                    c[t][1] = (c[t][1] * c[lin[k]][0]) % mod;
                }
                if(dp[lin[k]][0] > dp[lin[k]][1]){
                    dp[t][1] += dp[lin[k]][1];
                    c[t][1] = (c[t][1] * c[lin[k]][1]) % mod;
                }
                if(dp[lin[k]][0] == dp[lin[k]][1]){
                    dp[t][1] += dp[lin[k]][1];
                    c[t][1] = (c[t][1] * ((c[lin[k]][0] + c[lin[k]][1]) % mod)) % mod;
                }
            }
            if(recc[t] == 1) dp[t][0] = 100010, c[t][0] = 0;
            if(recc[t] == 2) dp[t][1] = 100010, c[t][1] = 0;
        }
//        printf("DP arr:\n");
//        for(long long j = 0; j <= n; j++) printf("0:%lld 1:%lld\n", dp[j][0], dp[j][1]);
//        printf("C arr:\n");
//        for(long long j = 0; j <= n; j++) printf("0:%lld 1:%lld\n", c[j][0], c[j][1]);
        if(dp[0][0] < minnum){
            minnum = dp[0][0];
            ans = c[0][0];
        } else
            if(dp[0][0] == minnum) ans = (ans + c[0][0]) % mod;
        if(dp[0][1] < minnum){
            minnum = dp[0][1];
            ans = c[0][1];
        } else
            if(dp[0][1] == minnum) ans = (ans + c[0][1]) % mod;
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
			int A[]                   = {0};
			int B[]                   = {-1};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = VampireTreeDiv2().countMinSamples( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int A[]                   = {0, 1};
			int B[]                   = {-1, 0};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = VampireTreeDiv2().countMinSamples( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int A[]                   = {0, 0, 2, 2};
			int B[]                   = {-1, -1, -1, -1};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = VampireTreeDiv2().countMinSamples( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int A[]                   = {0, 1, 2, 3};
			int B[]                   = {-1, -1, -1, -1};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = VampireTreeDiv2().countMinSamples( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int A[]                   = {0, 1, 1, 2, 1, 2, 2, 5, 7, 6, 5, 10, 6, 6, 12, 6, 6, 2, 8, 0, 16, 5, 8, 2, 14};
			int B[]                   = {-1, -1, -1, -1, 0, -1, -1, -1, 2, 7, 10, 11, 7, 9, -1, 5, -1, 15, 4, 7, 9, -1, 13, 6, 24};
			int expected__            = 78;

			clock_t start__           = clock();
			int received__            = VampireTreeDiv2().countMinSamples( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int A[]                   = {0,1,0,3,0,5,0,7,0,9,0,11,0,13,0,15,0,17,0,19,0,21,0,23,0,25,0,27,0,29,0,31,0,33,0,35,0,37,0,39,0,41,0,43,0,45,0,47,0,49,0,51,0,53,0,55,0,57,0,59,0};
			int B[]                   = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
			int expected__            = 73741818;

			clock_t start__           = clock();
			int received__            = VampireTreeDiv2().countMinSamples( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = VampireTreeDiv2().countMinSamples( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = VampireTreeDiv2().countMinSamples( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = VampireTreeDiv2().countMinSamples( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
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
