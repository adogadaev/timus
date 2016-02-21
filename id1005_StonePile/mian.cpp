#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	unsigned long int nSize;
	unsigned long int inval;
	vector <unsigned long int> vNum;
	unsigned int nSum;
	unsigned int nMinDiff;
	unsigned int nCurMinDiff;

	nSum = 0;
	cin >> nSize;
	for (unsigned long int i = 0; i < nSize; i++) {
		cin >> inval;
		vNum.push_back(inval);
		nSum += inval;
	}
	
	nMinDiff = nSum;
	unsigned int nMaxPile = (1 << nSize) - 1;
	for (unsigned int nCurPile = 1; nCurPile <= nMaxPile; nCurPile++) {
		unsigned int nCurSum = 0;
		for (unsigned int j = 0; j < nSize; j++) {
			unsigned int nInPile = (nCurPile >> j) & 1;
			if (nInPile == 1) {
				nCurSum += vNum[j];
			}
		}
		nCurMinDiff = nSum - 2*nCurSum;
		if (nCurMinDiff < 0) {
			nCurMinDiff *= (-1);
		}
		if (nCurMinDiff < nMinDiff) {
			nMinDiff = nCurMinDiff;
		}
	}

	cout << nMinDiff << endl;

	return 0;
}