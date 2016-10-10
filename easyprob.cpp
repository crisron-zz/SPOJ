#include <iostream>

#define BITS 32

using namespace std;

void findOneBitPositions( int n, bool oneBitPositions[ BITS ], int& oneBitsRemaining ) {
    int i = 0;
    while( n ) {
        if( n & 1 ) { // LSB is 1
            oneBitPositions[ i ] = 1;
            oneBitsRemaining++;
        }
        i++;
        n >>= 1;
    }
}

void printAnswer( int n ) {
    if( n < 1 ) {
        return;
    }
    // oneBitPositions[ i ] = 1 if i-th bit of n from LSB is 1
    bool oneBitPositions[ BITS ] = { 0 };
    int oneBitsRemaining = 0;
    findOneBitPositions( n, oneBitPositions, oneBitsRemaining );

    // Consider higher powers first
    for( int i = BITS - 1; i >= 0; --i ) {
        if( oneBitPositions[ i ] ) {
            oneBitsRemaining--;
            bool printClosingParen = true;
            if( i > 1 ) {
                cout << "2(";
                printAnswer( i );
                cout << ")";
            } else if( i == 1 ) {
                cout << "2";
            } else { // i == 0
                cout << "2(0)";
            }
            if( oneBitsRemaining ) {
                cout << "+";
            }
        }
    }
}

void printAnswerWrapper( int n ) {
    cout << n << "=";
    printAnswer( n );
    cout << endl;
}

int main() {
    printAnswerWrapper( 137 );
    printAnswerWrapper( 1315 );
    printAnswerWrapper( 73 );
    printAnswerWrapper( 136 );
    printAnswerWrapper( 255 );
    printAnswerWrapper( 1384 );
    printAnswerWrapper( 16385 );

    return 0;
}

