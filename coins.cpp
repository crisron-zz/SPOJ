#include <iostream>
#include <cstdio>

using namespace std;

long long dp[ 1000000000 + 5 ];

long long max( long long a, long long b ) {
    if( a >= b ) {
        return a;
    }
    return b;
}

long long maxVal( long long dp[], long long coin ) {
    if( dp[ coin ] != -1 ) {
        return dp[ coin ];
    }
    if( coin <= 4 ) {
        dp[ coin ] = coin;
        return dp[ coin ];
    }
    long long by2, by3, by4;
    if( dp[ coin / 2 ] != -1 ) {
        by2 = dp[ coin / 2 ];
    } else {
        by2 = maxVal( dp, coin / 2 );
    }
    if( dp[ coin / 3 ] != -1 ) {
        by3 = dp[ coin / 3 ];
    } else {
        by3 = maxVal( dp, coin / 3 );
    }
    if( dp[ coin / 4 ] != -1 ) {
        by4 = dp[ coin / 4 ];
    } else {
        by4 = maxVal( dp, coin / 4 );
    }
    dp[ coin ] = max( coin, by2 + by3 + by4 );
    return dp[ coin ];
}

int main() {
    memset( dp, -1, sizeof( int ) * ( 1000000000 + 2 ) );
    long long num;
    while ( scanf( "%lld", &num ) ) {
        printf( "%lld\n", maxVal( dp, num ) );
    }
    return 0;
}
