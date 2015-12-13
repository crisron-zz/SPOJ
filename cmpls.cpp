#include <iostream>
#include <cstdio>

using namespace std;

int isDifferenceConstant( int differences[][ 101 ], int i, int lenOfSeq ) {

	int j;
	for( j = 1; j < ( lenOfSeq - i - 1 ); ++j ) {
		
		if ( differences[ i ][ j ] != differences[ i ][ 0 ] ) {

			cout << "j = " << j << " Difference not constant" << endl;
			return 0;
		}
	}
	return 1;
}

void calculateDifferences( int differences[][ 101 ], int i, int lenOfSeq ) {
	
	int j;
	for( j = 0; j < ( lenOfSeq - i ); ++j ) {

		differences[ i ][ j ] = differences[ i - 1 ][ j + 1 ] - differences[ i - 1 ][ j ];
	}
}

int main() {

	int t, lenOfSeq, noOfTermsToFind, seq[ 101 ], i, j, k, c;

	cin >> t;

	while( t-- ) {

		int differences[ 101 ][ 101 ] = { 0, 0 };

		cin >> lenOfSeq  >> noOfTermsToFind;
		
		for( i = 0; i < lenOfSeq; ++i ) {
		      
		       	cin >> seq[ i ];
		}
		
		// If only one term
		if( lenOfSeq == 1 ) {
			
			for( j = lenOfSeq; j < ( lenOfSeq + noOfTermsToFind ); ++j ) {
				
				seq[ j ] = seq[ 0 ];
			}
		}
		else {
			
			for( j = 0; j < ( lenOfSeq - 1 ); ++j ) {
				
				differences[ 0 ][ j ] = seq[ j + 1 ] - seq[ j ];
			}

			i = 0;
			
			if( j != 1 ) {
				
				while( !isDifferenceConstant( differences, i, lenOfSeq ) ) {
				
					i++;
					calculateDifferences( differences, i, lenOfSeq );
				}
			}
			
			for( j = 0; j < noOfTermsToFind; ++j ) {

				differences[ i ][ j + ( lenOfSeq - 1 ) - i ] = differences[ i ][ 0 ];	
			}
		}

		while( i-- ) {
			
			for( k = 0; k < noOfTermsToFind; ++k ) {

				differences[ i ][ k + lenOfSeq - i ] = differences[ i ][ k + lenOfSeq - i - 1 ] + differences[ i + 1 ][ k + lenOfSeq - i - 2 ];
			}
		}	
		for( k = 0; k < noOfTermsToFind; ++k) {

			seq[ k + lenOfSeq ] = seq[ k + lenOfSeq - 1 ] + differences[ 0 ][ k + lenOfSeq - i - 2 ];
		}

		for( i = lenOfSeq; i < ( lenOfSeq + noOfTermsToFind ); ++i ) {

			cout << seq[ i ];
			if( i == ( lenOfSeq + noOfTermsToFind - 1 ) ) {
				cout << endl;
			}
			else {
				cout << " ";
			}
		}
	}
}
