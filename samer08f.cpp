#include <iostream>

using namespace std;

int main() {
	int sideToSquares[ 101 ] = {}, numSquares = 0, side, testCases; 

	for( side = 0; side < 101; side++ ) {
		numSquares += side * side;
	    	sideToSquares[ side ] = numSquares;
	}
	
	cin >> testCases;
	while ( testCases-- ) {
		cin >> side;
		cout << sideToSquares[ side ] << "\n";
	}

	return 0;
}
