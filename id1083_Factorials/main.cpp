#include <iostream>
#include <string>

using namespace std;

int main() {
	int nNum, nK, nRes;
	string sKvals;

	cin >> nNum;
	getline(cin, sKvals);

	nK = sKvals.length() - 1;

	nRes = nNum;
	for (unsigned int i = 1; nNum - (int)i*nK > 0; i++)
		nRes *= (nNum - (int)i*nK);

	cout << nRes << endl;

	return 0;
}