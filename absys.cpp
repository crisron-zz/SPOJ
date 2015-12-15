#include <cstdio>

void calculateMachula( char equation[], int& a, int& b, int& c ) {
    // machulaFlag = 1 -> a has machula
    // machulaFlag = 2 -> b has machula
    // machulaFlag = 3 -> c has machula
    int i = 0, machulaFlag = 0;
    // Process a
    while( equation[ i ] != ' ' ) {
        if( !machulaFlag ) {
            if( equation[ i ] == 'm' ) {
                machulaFlag = 1;
            }
            if( !machulaFlag ) {
                a = 10 * a + equation[ i ] - '0';
            }
        }
        i++;
    }
    // i will now be at the space before +
    // Take i to first character of b
    i += 3;
    // Process b
    while( equation[ i ] != ' ' ) {
        // machula was not in a
        if( equation[ i ] == 'm' ) {
            machulaFlag = 2;
        }
        if( machulaFlag != 2 ) {
            b = 10 * b + equation[ i ] - '0';
        }
        i++;
    }
    // i will now be at the space before =
    // Take i to the first character of c
    i += 3;
    while( equation[ i ] != '\0' ) {
        // machula was not in b
        if( equation[ i ] == 'm' ) {
            machulaFlag = 3;
        }
        if( machulaFlag != 3 ) {
            c = 10 * c + equation[ i ] - '0';
        }
        i++;
    }
    if( machulaFlag == 1 ) {
        a = c - b;
    } else if( machulaFlag == 2 ) {
        b = c - a;
    } else {
        c = a + b;
    }
}

int main() {
    int t;
    char equation[ 100 ];
    scanf( "%d", &t );
    while( t-- ) {
        int a = 0, b = 0, c = 0;
        // equation is of the form a + b = c
        scanf( "\n%[^\n]", equation );
        calculateMachula( equation, a, b, c );
        printf( "%d + %d = %d\n", a, b, c );
    }
    return 0;
}
