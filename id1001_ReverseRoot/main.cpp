#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
	long double inval;
	long double out;
	vector <long double> vin;

	while (cin >> inval) {
		vin.push_back(sqrt(inval));
	}
	cout << fixed;
	while (vin.size() != 0) {
		out = vin[vin.size()-1];
		vin.pop_back();
		cout << setprecision(4) << out << endl;
	}

	return 0;
}
