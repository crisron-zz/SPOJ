#include <cstdio>

#define MAX 500000 

int main() {
    int n;
    scanf( "%d", &n );
    int i;
    int p[ MAX + 2 ];
    int ans = 0;
    for( i = 0; i < n; ++i ) {
        scanf( "%d", &p[ i ] );
        ans = ans ^ p[ i ];
    }
    printf( "%d\n", ans );
    return 0;
}
