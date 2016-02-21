#include <iostream>
#include <vector>

using namespace std;

int main() {
	unsigned long int n;
	unsigned long int nNums[10] = {0,0,0,0,0,0,0,0,0,0};

	cin >> n;
	if (n == 0) {
		cout << "10";
		return 0;
	}
	if (n == 1) {
		cout << "1";
		return 0;
	}

	while (n%2 == 0) {
		n /= 2;
		nNums[2]++;
	}
	while (n%3 == 0) {
		n /= 3;
		nNums[3]++;
	}
	while (n%5 == 0) {
		n /= 5;
		nNums[5]++;
	}
	while (n%7 == 0) {
		n /= 7;
		nNums[7]++;
	}

	if (n != 1) {
		cout << "-1";
		return 0;
	}

	while (nNums[3] >= 2) {
		nNums[3] -= 2;
		nNums[9]++;
	}
	while (nNums[2] >= 3) {
		nNums[2] -= 3;
		nNums[8]++;
	}
	while (nNums[2] >= 1 && nNums[3] >= 1) {
		nNums[2]--;
		nNums[3]--;
		nNums[6]++;
	}
	while (nNums[2] >= 2) {
		nNums[2] -= 2;
		nNums[4]++;
	}

	for (unsigned int i = 0; i < 10; i++) {
		while (nNums[i] != 0) {
			cout << i;
			nNums[i]--;
		}
	}

	return 0;
}