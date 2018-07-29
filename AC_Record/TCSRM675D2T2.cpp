//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class ShortestPathWithMagic {
public:
    double getTime( vector <string> dist, int k );
};
double d[60][60];
int n;
int l, q[1000010][2], r;
double ShortestPathWithMagic::getTime(vector <string> dist, int k) {
	n = dist.size();
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= k; j++) d[i][j] = 1000000000;
	d[0][0] = 0;
	l = 0; r = 1;
	while(l < r) {
		l++;
		for(int i = 0; i < n; i++) {
			if(d[q[l][0]][q[l][1]] + dist[q[l][0]][i] - '0' < d[i][q[l][1]]){
				d[i][q[l][1]] = d[q[l][0]][q[l][1]] + dist[q[l][0]][i] - '0';
				r++;
				q[r][0] = i; q[r][1] = q[l][1];
			}
			if(q[l][1] < k)
			if(d[q[l][0]][q[l][1]] + (double)(dist[q[l][0]][i] - '0') / 2 < d[i][q[l][1] + 1]){
				d[i][q[l][1] + 1] = d[q[l][0]][q[l][1]] + (double)(dist[q[l][0]][i] - '0') / 2;
				r++;
				q[r][0] = i; q[r][1] = q[l][1] + 1;
			}
		}
	}
	double ans = 1000000000;
	for(int i = 0; i <= k; i++) ans = min(ans, d[1][i]);
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
			string dist[]             = {"094",  "904",  "440"};
			int k                     = 1;
			double expected__         = 4.5;

			clock_t start__           = clock();
			double received__         = ShortestPathWithMagic().getTime( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string dist[]             = {"094",  "904",  "440"};
			int k                     = 2;
			double expected__         = 4.0;

			clock_t start__           = clock();
			double received__         = ShortestPathWithMagic().getTime( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string dist[]             = {"094",  "904",  "440"};
			int k                     = 50;
			double expected__         = 4.0;

			clock_t start__           = clock();
			double received__         = ShortestPathWithMagic().getTime( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string dist[]             = {"094",  "904",  "440"};
			int k                     = 0;
			double expected__         = 8.0;

			clock_t start__           = clock();
			double received__         = ShortestPathWithMagic().getTime( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string dist[]             = {"076237",  "708937",  "680641",  "296059",  "334508",  "771980"};
			int k                     = 1;
			double expected__         = 3.5;

			clock_t start__           = clock();
			double received__         = ShortestPathWithMagic().getTime( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string dist[]             = {"00",  "00"};
			int k                     = 50;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = ShortestPathWithMagic().getTime( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

     case 6: {
			string dist[]             = {"0174094882455171152761423221685761892795431233411", "1038742779319865028602486509006138934460661849637", "7308829135984076361542097372601657541200146071777", "4880733599818266038012509478351201640618984143988", "0787008778383710734965109968348499255333743808806", "9423008198972282890781586124258626539246182119762", "4293880952003918195325258677229419698255491250839", "8715719039679976935766582544161633553282536186214", "8739795306291503649293440596342887581257444442930", "2959882960778730382520372975343211325351222640703", "4398390627040053106750045495648216831484920706070", "5181870797405673849265774579830223671554026061117", "5948323918050300483012903885770893074783710083450", "1802729957063014562035666767719162727651399592653", "7676181703570102444279237315785832411595106453089", "1566028630330420134746365281031552217482363035280", "1030781963184541072259108507905341048592541395827", "5263399348048643709617719034175332412908745680774", "2818405592693244290313630190429314820559328748143", "7650973725720027263055268929594505880132227031337", "6041682692561374511500955837837939182801848609300", "1222515630052596973500876356583948397645861551964", "4405152543079623176298054253268266394562535661446", "2890085847470636013657502682551015176002433628234", "3679968202543675890856420343684739800880514363921", "2534916559458732501983263098234023198989135142538", "2077627497978618039235584909287014819359798014755", "1928847465595751740976323890509282450440511590838", "6063322133687770914585256225072693810338480154137", "8005452644437183072938658380703585690893606978941", "5611889123800951559473814479230566666714061214952", "7162464682228185333599207002655034152316882771260", "6350921381129635431034613218986304946036245881214", "1871969371633222124598659342356440982452998386986", "8956256553860742048813318184866199062382627578278", "9344539582377211412889970915196548600208928205527", "2410598315114717820027460890006262200678781609589", "7426322223457654595186508934387304326000072552148", "9601345855858598905304608854391135807006468983551", "5008365271443152289215220990834662288060558405472", "4619714542907313573288545175460829697045014990303", "3648489342221906442246331391806849228765105076783", "1164321642060963158781534581061258781288450644195", "2801812146700540367065663105192783526594906057473", "3474015844068953984305626419571788700580974504088", "3913890620613235508191183240484116859235064740152", "4679878297014602871339429578199229255154371401032", "1378063130715588274306432353345618728457089785304", "1778629403070390743704641858712046879812335382240"};
			int k                     = 49;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = ShortestPathWithMagic().getTime( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 7: {
			string dist[]             = ;
			int k                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = ShortestPathWithMagic().getTime( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			string dist[]             = ;
			int k                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = ShortestPathWithMagic().getTime( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), k );
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
