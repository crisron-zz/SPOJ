#include <cstdio>

#define MAX 200000

void merge( int a[], int left, int mid, int right, long long& inversions ) {
    int i = left, j = mid + 1, k = left;
    int temp[ MAX + 2 ];

    while( ( i <= mid ) && ( j <= right ) ) {
        if( a[ i ] <= a[ j ] ) {
            temp[ k++ ] = a[ i++ ];
        } else {
            temp[ k++ ] = a[ j++ ];
            // a[ i ] to a[ mid ] are bigger than a[ j ] since
            // both the halves are sorted
            inversions += ( long long ) ( mid - i + 1 );
        }
    }
    while( i <= mid ) {
        temp[ k++ ] = a[ i++ ];
    }
    while( j <= right ) {
        temp[ k++ ] = a[ j++ ];
    }
    for( i = left; i <= right; ++i ) {
        a[ i ] = temp[ i ];
    }
}

void mergeSort( int a[], int left, int right, long long& inversions ) {
    if( left < right ) {
        int mid = ( left + right ) / 2;
        mergeSort( a, left, mid, inversions );
        mergeSort( a, mid + 1, right, inversions );
        merge( a, left, mid, right, inversions );
    }
}

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        int n;
        scanf( "%d", &n );
        int a[ MAX + 2 ];
        for( int i = 0; i < n; ++i ) {
            scanf( "%d", &a[ i ] );
        }
        long long inversions = 0;
        mergeSort( a, 0, n - 1, inversions );
        printf( "%lld\n", inversions );
    }
    return 0;
}
