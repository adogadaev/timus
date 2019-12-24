//============================================================================
// Name        : id1073.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : ID 1073 Square Country
//============================================================================

#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define MAXNUM 60001
#define INFINITE 0xffffffff

unsigned int getMinCertificates(unsigned int k, unsigned int (&minCerts)[MAXNUM]) {
	//cout << "Checking k(" << k << ")" << endl;
	if (minCerts[k] != INFINITE)
		return minCerts[k];
	if ((unsigned int)sqrt(k)*(unsigned int)sqrt(k) == k) {
		minCerts[k] = 1;
		return minCerts[k];
	}
	for (unsigned int i = 1; i <= ((unsigned int)sqrt(k)/2 + 1); i++) {
		//cout << "Checking k(" << k << ") with pairs " << k - i*i << " and " << i*i << endl;
		unsigned int curCerts = getMinCertificates(k - i*i, minCerts) + getMinCertificates(i*i, minCerts);
		minCerts[k] =  (curCerts < minCerts[k]) ? curCerts : minCerts[k];
	}
	return minCerts[k];
}

int main() {
	unsigned int k;
	unsigned int minCerts[MAXNUM];
	fill_n(minCerts, MAXNUM, INFINITE);
	minCerts[0] = 0;
	minCerts[1] = 1;
	cin >> k;
	cout << getMinCertificates(k, minCerts);

	return 0;
}
