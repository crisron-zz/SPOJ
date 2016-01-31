#include <iostream>
#include <cstdio>

#define PLUS '+'
#define MINUS '-'
#define DIVIDE '/'
#define MULTIPLY '*'
#define MODULUS '%'
#define EQUALTO '='
#define SPACE ' '
#define EMPTY '#'

using namespace std;

int main() {
    int t;
    cin >> t;
    while( t-- ) {
        long long num, result = -1;
        char op;
        cin >> result;
        while( true ) {
            cin >> op;
            if( op == EQUALTO ) {
                break;
            }
            scanf( "%lld", &num );
            switch( op ) {
                case PLUS:
                    result = result + num;
                    break;
                case MINUS:
                    result = result - num;
                    break;
                case DIVIDE:
                    result = result / num;
                    break;
                case MULTIPLY:
                    result = result * num;
                    break;
                case MODULUS:
                    result = result % num;
                    break;
            }
        }
        cout << result << endl;
    }
    return 0;
}
