#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	vector<int> vN;
	do {
		cin >> n;
		if (n!=0)
			vN.push_back(n);
	} while (n != 0);

	int vA[100002];
	int vMax[100002];
	int curMax = 1;
	vA[0] = 0;
	vA[1] = 1;
	vMax[0] = 0;
	vMax[1] = 1;
	for (int i = 1; i < 50000; i++) {
		vA[2*i] = vA[i];
		if (vA[2*i] > curMax)
			curMax = vA[2*i];
		vMax[2*i] = curMax;

		vA[2*i+1] = vA[i] + vA[i+1];
		if (vA[2*i+1] > curMax)
					curMax = vA[2*i+1];
		vMax[2*i+1] = curMax;
	}

	for (int i = 0; i < vN.size(); i++)
		cout << vMax[vN[i]] << endl;

	return 0;
}
