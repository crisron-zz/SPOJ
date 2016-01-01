#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 100

using namespace std;

int calMax( int dp[][ MAX + 2], int grid[][ MAX + 2 ], int col, int i, int j ) {
    if( dp[ i ][ j ] != -1 ) {
        return dp[ i ][ j ];
    }
    int left = 0, up = 0, right = 0;
    // Check if we can go one row up
    if( i ) {
        if( dp[ i - 1 ][ j ] != -1 ) {
            up = dp[ i - 1 ][ j ];
        } else {
            up = calMax( dp, grid, col, i - 1, j );
        }
        // Check if we can go one column left
        if( j ) {
            if( dp[ i - 1 ][ j - 1 ] != -1 ) {
                left = dp[ i - 1 ][ j - 1 ];
            } else {
                left = calMax( dp, grid, col, i - 1, j - 1 );
            }
        }
        // Check if we can go one column right
        if( j < ( col - 1 ) ) {
            if( dp[ i - 1 ][ j + 1 ] != -1 ) {
                right = dp[ i - 1 ][ j + 1 ];
            } else {
                right = calMax( dp, grid, col, i - 1, j + 1 );
            }
        }
    }
    dp[ i ][ j ] = grid[ i ][ j ] + max( left, max( up, right ) ); // max() is defined in algorithm
    return dp[ i ][ j ];
}

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        int row, col;
        scanf( "%d%d", &row, &col );
        int i, j;
        int grid[ MAX + 2 ][ MAX + 2 ];
        for( i = 0; i < row; ++i ) {
            for( j = 0; j < col; ++j ) {
                scanf( "%d", &grid[ i ][ j ] );
            }
        }
        int dp[ MAX + 2 ][ MAX + 2 ];
        for( i = 0; i < row; ++i ) {
            for( j = 0; j < col; ++j ) {
                dp[ i ][ j ] = -1;
            }
        }
        int maxAns = -1, ans;
        for( i = 0; i < col; ++i ) {
            ans = calMax( dp, grid, col, row - 1, i );
            if( ans > maxAns ) {
                maxAns = ans;
            }
        }
        printf( "%d\n", maxAns );
    }
    return 0;
}
