#include <iostream>

using namespace std;

int main() {
	int N, x, y;
	cin >> N;
	while ( N-- ) {
		cin >> x >> y;
		if ( !x && !y ) {
			cout << "0\n";
		}
		else if ( ( y == x ) || ( y == ( x - 2 ) ) ) {
			if ( x % 2 ) {
				cout << x + y - 1 << "\n"; 
			}
			else {
				cout << x + y << "\n";
			}
		}
		else {
			cout << "No Number" << "\n";
		}
	}
	return 0;
}
