#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 2147483647;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	int ans = INF, result;
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        if( abs( t ) < ans ) {
        	ans = abs( t );
        	result = t;
        } else 
        if( abs( t ) == ans && t > result ) result = t;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << ( ( ans == INF ) ? 0 : result ) << endl;
}
