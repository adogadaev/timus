/*
 * id1048.cpp
 *
 *  Created on: Jun 17, 2020
 *      Author: ado
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	unsigned int num;
	cin >> num;
	unsigned int a, b;
	vector<int> sum;
	for (unsigned int i = 0; i < num; i++)
	{
		cin >> a >> b;
		sum.push_back(a + b);
	}
	for (unsigned int i = sum.size() - 1; i > 0; i--)
	{
		sum[i-1] += sum[i] / 10;
		sum[i] %= 10;
	}
	for (auto el : sum)
		cout << el;

	return 0;
}


