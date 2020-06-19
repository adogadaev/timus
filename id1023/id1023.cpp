/*
 * id1023.cpp
 *
 *  Created on: Jun 19, 2020
 *      Author: ado
 */
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	unsigned int num;
	unsigned int result = 0;

	cin >> num;
	for (unsigned int i = 3; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			result = i - 1;
			break;
		}
	}
	if (result == 0)
		result = (num > 4 && num % 2 == 0) ? num / 2 - 1 : num - 1;
	cout << result << endl;

	return 0;
}
