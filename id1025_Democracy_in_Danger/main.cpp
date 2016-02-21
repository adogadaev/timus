#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	unsigned int uiGroupNum;
	vector<unsigned int> vGroups;
	unsigned int uiCurGroup;
	unsigned int uiSum;

	cin >> uiGroupNum;
	for (unsigned int i = 0; i < uiGroupNum; i++){
		cin >> uiCurGroup;
		vGroups.push_back(uiCurGroup);
	}

	sort(vGroups.begin(), vGroups.end());

	uiSum = 0;
	for (unsigned int i = 0; i < (uiGroupNum/2+1); i++)
		uiSum += (vGroups[i]/2+1);

	cout << uiSum << endl;

	return 0;
}

/*
for (unsigned int i = 0; i < uiGroupNum; i++){
		cout << vGroups[i] << " ";
	}
	cout << endl;

int main() {
	int a,b;
	cin >> a >> b;
	cout << (a+b) << endl;

	return 0;
}
*/