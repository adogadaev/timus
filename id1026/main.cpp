#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n;
	int aNum[100000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> aNum[i];
	sort(aNum, aNum+n);

	int k;
	int idx;
	string str;
	cin >> str;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> idx;
		cout << aNum[idx-1] << endl;
	}

	return 0;
}
