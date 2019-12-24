#include <iostream>

using namespace std;

int main()
{
	int nPrimes[15000];
	nPrimes[0] = 2;

	int nCurPrime = 1;
	for (int i = 3; nCurPrime != 15000; i++)
	{
		bool isPrime = true;
		for (int j = 0; j < nCurPrime; j++)
		{
			if (i % nPrimes[j] == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			nPrimes[nCurPrime++] = i;
	}

	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;
		cout << nPrimes[n-1] << endl;
	}

	return 0;
}
