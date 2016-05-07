#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int nNum;
	int nSize;

	cin >> nNum;

	nSize = (nNum <= 0) ? (abs(nNum) + 2) : nNum;

	cout << nSize*(1+nNum)/2 << endl;
	
	return 0;
}