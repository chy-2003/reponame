//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class LengthUnitCalculator {
public:
    double calc( int amount, string fromUnit, string toUnit );
};
double d[3] = {1760.0, 3.0, 12.0};
double LengthUnitCalculator::calc(int amount, string fromUnit, string toUnit) {
    int t1, t2;
	if(fromUnit == "mi") t1 = 0; else
	if(fromUnit == "yd") t1 = 1; else
	if(fromUnit == "ft") t1 = 2; else
	if(fromUnit == "in") t1 = 3;
	if(toUnit == "mi") t2 = 0; else
	if(toUnit == "yd") t2 = 1; else
	if(toUnit == "ft") t2 = 2; else
	if(toUnit == "in") t2 = 3;
	double ans = amount;
//	printf("%d %d\n", t1, t2);
	if(t1 < t2) 
		for(int i = t1; i < t2; i++) ans = ans * d[i];
	else
		for(int i = t1 - 1; i >= t2; i--) ans = ans / d[i];
//	cout << ans << endl;
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
			int amount                = 1;
			string fromUnit           = "mi";
			string toUnit             = "ft";
			double expected__         = 5280.0;

			clock_t start__           = clock();
			double received__         = LengthUnitCalculator().calc( amount, fromUnit, toUnit );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int amount                = 1;
			string fromUnit           = "ft";
			string toUnit             = "mi";
			double expected__         = 1.893939393939394E-4;

			clock_t start__           = clock();
			double received__         = LengthUnitCalculator().calc( amount, fromUnit, toUnit );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int amount                = 123;
			string fromUnit           = "ft";
			string toUnit             = "yd";
			double expected__         = 41.0;

			clock_t start__           = clock();
			double received__         = LengthUnitCalculator().calc( amount, fromUnit, toUnit );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int amount                = 1000;
			string fromUnit           = "mi";
			string toUnit             = "in";
			double expected__         = 6.336E7;

			clock_t start__           = clock();
			double received__         = LengthUnitCalculator().calc( amount, fromUnit, toUnit );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int amount                = 1;
			string fromUnit           = "in";
			string toUnit             = "mi";
			double expected__         = 1.5782828282828283E-5;

			clock_t start__           = clock();
			double received__         = LengthUnitCalculator().calc( amount, fromUnit, toUnit );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int amount                = 47;
			string fromUnit           = "mi";
			string toUnit             = "mi";
			double expected__         = 47.0;

			clock_t start__           = clock();
			double received__         = LengthUnitCalculator().calc( amount, fromUnit, toUnit );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int amount                = ;
			string fromUnit           = ;
			string toUnit             = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = LengthUnitCalculator().calc( amount, fromUnit, toUnit );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int amount                = ;
			string fromUnit           = ;
			string toUnit             = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = LengthUnitCalculator().calc( amount, fromUnit, toUnit );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int amount                = ;
			string fromUnit           = ;
			string toUnit             = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = LengthUnitCalculator().calc( amount, fromUnit, toUnit );
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
