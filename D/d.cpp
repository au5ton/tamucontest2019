#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	vector<bool> primes((a > b ? a : b) + 1, true);
	// vector<int> pA, pB, pAB;
	int pA = 0, pB = 0, pAB = 0;
	for (int i = 2; i <= (a > b ? a : b); ++i) {
		if (primes[i]) {
			for (int k = i + i; k <= (a > b ? a : b); k += i) {
				primes[k] = false;
			}
			if (a % i == 0) {
				if ( b % i == 0) {
					++pAB;
				} else {
					++pA;
				}
			} else if (b % i == 0) {
				++pB;
			}
		}
	}

	cout << double(pAB) / (pA + pAB + pB) << endl;
}
