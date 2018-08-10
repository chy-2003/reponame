//tc is healthy, just do it
#include <bits/stdc++.h>
using namespace std;

class FencingPenguinsEasy {
public:
    double calculateMinArea( int numPosts, int radius, vector <int> x, vector <int> y );
};
const double Pi = 3.14159265358979323846264;
const double INF = 100000.0 * 100000.0 * Pi;
struct Point {
	double X, Y;
	Point(double X_ = 0.0, double Y_ = 0.0) { X = X_; Y = Y_; return; }
};
struct Vector {
	double X, Y;
	Vector(double X_ = 0.0, double Y_ = 0.0) { X = X_; Y = Y_; return; }
};
Point Post[310], Penguins[60];
int NPost, NPenguins;
void get_Post(int num, double r) {
	double pre_degree = 2.0 * Pi / num;
	for(int i = 0; i < num; ++i) Post[i + 1] = Point(cos(pre_degree * i) * r, sin(pre_degree * i) * r);
	return;
}
double relation[310][310];
double sqr(double x) { return x * x; }
double Get_dis(Point x, Point y) {
	return sqrt(sqr(x.X - y.X) + sqr(x.Y - y.Y));
}
double Cross(Vector x, Vector y) { return x.X * y.Y - x.Y * y.X; }
double Cross_(Point x, Point y, Point z) {
	return Cross(Vector(y.X - x.X, y.Y - x.Y), Vector(z.X - x.X, z.Y - x.Y));
}
void Get_Map() {
	double dis;
	for(int i = 1; i <= NPost; ++i) 
		for(int j = 1; j <= NPost; ++j) 
			if(i != j) {
				dis = Get_dis(Post[i], Post[j]);
				for(int k = 1; k <= NPenguins; ++k)
					if(Cross_(Post[i], Post[j], Penguins[k]) < 0) {
						dis = INF; break;
					}
				if(INF - dis <= 1e-6) relation[i][j] = INF; else relation[i][j] = Cross_(Point(0.0, 0.0), Post[i], Post[j]) / 2.0;
			} else relation[i][j] = 0;
	return;
}
double Distance[310];
int vis[310];
double dij(int start) {
//	printf("In Function dij %d\n", start);
	for(int i = 1; i <= NPost + 1; ++i) Distance[i] = INF;
	memset(vis, 0, sizeof(vis));
	Distance[start] = 0;
	double minnum;
	int id;
	for(int i = 1; i <= NPost; ++i) {
		minnum = INF;
		for(int j = 1; j <= NPost + 1; ++j) 
			if(!vis[j] && Distance[j] < minnum) {
				minnum = Distance[j];
				id = j;
			}
//		printf("%dth Choosed %d\n", i, id);
		vis[id] = 1;
		for(int j = 1; j <= NPost + 1; ++j) 
			if(!vis[j] && Distance[j] > Distance[id] + relation[id][j]) 
				Distance[j] = Distance[id] + relation[id][j];
	}
	return Distance[NPost + 1];
}
bool No_Ans() {
	for(int i = 1; i < NPost; ++i) 
		for(int j = 1; j <= NPenguins; ++j) 
			if(Cross_(Post[i], Post[i + 1], Penguins[j]) < 0) return true;
	for(int j = 1; j <= NPenguins; ++j) 
		if(Cross_(Post[NPost], Post[1], Penguins[j]) < 0) return true;
	return false;
}
double FencingPenguinsEasy::calculateMinArea(int numPosts, int radius, vector <int> x, vector <int> y) {
	NPost = numPosts; NPenguins = x.size();
    get_Post(numPosts, radius * 1.0);
//	printf("Posts Possition:\n");
//	for(int i = 1; i <= NPost; ++i) printf("%.2lf %.2lf\n", Post[i].X, Post[i].Y);
	for(int i = 0; i < NPenguins; ++i) Penguins[i + 1] = Point(x[i], y[i]);
//	printf("Penguins Possition:\n");
//	for(int i = 1; i <= NPenguins; ++i) printf("%8.2lf %8.2lf\n", Penguins[i].X, Penguins[i].Y);
	if(No_Ans()) return -1;
	Get_Map();
//	printf("Map set:\n");
//	for(int i = 1; i <= NPost; ++i) {
//		for(int j = 1; j <= NPost; ++j) printf("%10.2lf ", relation[i][j]);
//		printf("\n");
//	}
	double ans = INF;
	for(int i = 1; i <= NPost; ++i) {
		for(int j = 1; j <= NPost; j++) {
			relation[j][NPost + 1] = relation[j][i];
			relation[NPost + 1][j] = relation[i][j];
		}
		relation[i][NPost + 1] = INF;
		relation[NPost + 1][i] = INF;
//		printf("\nMap set with %d:\n", i);
//		for(int k = 1; k <= NPost + 1; ++k) {
//			for(int j = 1; j <= NPost + 1; ++j) printf("%10.2lf ", relation[k][j]);
//			printf("\n");
//		}
		ans = min(ans, dij(i));
//		printf("ans = %.2lf\n", ans);
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
			int numPosts              = 3;
			int radius                = 5;
			int x[]                   = {-1};
			int y[]                   = {0};
			double expected__         = 32.47595264191645;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea( numPosts, radius, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int numPosts              = 30;
			int radius                = 5;
			int x[]                   = {6};
			int y[]                   = {0};
			double expected__         = -1.0;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea( numPosts, radius, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int numPosts              = 4;
			int radius                = 5;
			int x[]                   = {2};
			int y[]                   = {1};
			double expected__         = 25.0;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea( numPosts, radius, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int numPosts              = 4;
			int radius                = 5;
			int x[]                   = {2,-2};
			int y[]                   = {1,-1};
			double expected__         = 50.0;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea( numPosts, radius, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int numPosts              = 8;
			int radius                = 5;
			int x[]                   = {8};
			int y[]                   = {8};
			double expected__         = -1.0;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea( numPosts, radius, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int numPosts              = 7;
			int radius                = 10;
			int x[]                   = {9};
			int y[]                   = {1};
			double expected__         = 29.436752637711805;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea( numPosts, radius, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			int numPosts              = 30;
			int radius                = 800;
			int x[]                   = {8,2,100,120,52,67,19,-36};
			int y[]                   = {-19,12,88,-22,53,66,-140,99} ;
			double expected__         = 384778.74757953023;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea( numPosts, radius, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 7: {
			int numPosts              = ;
			int radius                = ;
			int x[]                   = ;
			int y[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea( numPosts, radius, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int numPosts              = ;
			int radius                = ;
			int x[]                   = ;
			int y[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea( numPosts, radius, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 9: {
			int numPosts              = ;
			int radius                = ;
			int x[]                   = ;
			int y[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea( numPosts, radius, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
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
