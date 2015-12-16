#include <cstdio>

int main() {
    int t, n, sum, i, j, termNum, termDen, pos;
    scanf( "%d", &t );
    while( t-- ) {
        i = 1;
        sum = 0;
        scanf( "%d", &n );
        while( sum < n ) {
            sum += i;
            i++;
        }
        // n is >= the sum of first j - 1 natural numbers
        // n is <= the sum of first j natural numbers
        j = i - 1;
        // Position = n - Sum of first j - 1 natural numbers
        pos = n - ( sum - j );
        if( j % 2 ) {
            // Going up
            termNum = j - ( pos - 1 );
            termDen = pos;
        } else {
            // Going down
            termNum = pos;
            termDen = j - ( pos - 1 );
        }
        printf( "TERM %d IS %d/%d\n", n, termNum, termDen );
    }
    return 0;
}
