#include <iostream>

using namespace std;

int getRes(int n, int k);

int main(){
	int n, k;
	int nRes;

	cin >> n >> k;
	nRes = getRes(n, k);

	cout << nRes;

	return 0;
}

int getRes(int n, int k) {
	if (n == 2)
		return (k-1)*k;
	if (n == 1)
		return (k-1);

	return (k-1)*(getRes(n-1, k) + getRes(n-2,k));
}
