#include <iostream>

using namespace std;

unsigned int getComb(int sum, int level)
{
	unsigned int nCombNum = 0;
	if (level == 0 && sum != 0)
		return 0;
	else if (level == 0 && sum == 0)
		return 1;

	for (int i = 0; i <= 9; i++)
		nCombNum += getComb(sum-i,level-1);
	return nCombNum;
}

int main()
{
	int n;
	cin >> n;

	unsigned int nTotalComb = 0;
	for (int sum = 0; sum <= 9*(n/2); sum++)
	{
		unsigned int comb = getComb(sum, n/2);
		nTotalComb += comb*comb;
	}
	cout << nTotalComb << endl;
	return 0;
}
