#include <iostream>

using namespace std;

int main()
{
	int n1, n2;
	int aAsc[50000];
	int aDesc[50000];

	cin >> n1;
	for (int i = 0; i < n1; i++)
		cin >> aAsc[i];

	cin >> n2;
	cin >> aDesc[0];
	bool found = false;
	for (int i = 0, j = 0; i < n1 && j < n2;)
	{
		if (aAsc[i] + aDesc[j] < 10000)
			i++;
		else if (aAsc[i] + aDesc[j] > 10000)
			cin >> aDesc[++j];
		else
		{
			found = true;
			break;
		}
	}
	if (found)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
