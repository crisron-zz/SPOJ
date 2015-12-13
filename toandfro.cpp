#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int col, rows, j, k;
    char encryptedMsg[ 201 ], decryptedMsg[ 11 ][ 21 ];
    while( 1 ) {
        scanf( "%d", &col );
        if( !col ) {
            return 0;
        }
        k = 0;
        scanf( "%s", encryptedMsg );
        rows = strlen( encryptedMsg ) / col;
        for( int i = 0; i < rows; ++i ) {
            // If the row number is even, move left to right
            if( !(i % 2 ) ) {
                for( j = 0; j < col; ++j ) {
                    decryptedMsg[ i ][ j ] = encryptedMsg[ k++ ];
                }
            } else {
                for( j = col - 1; j > -1; --j ) {
                    decryptedMsg[ i ][ j ] = encryptedMsg[ k++ ];
                }
            }
        }
        for( int i = 0; i < col; ++i ) {
            for( j = 0; j < rows; ++j ) {
                printf( "%c", decryptedMsg[ j ][ i ] );
            }
        }
        printf( "\n" );
    }
    return 0;
}


