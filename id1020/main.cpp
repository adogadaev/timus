#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	int n;
	double r, x, y, len;
	vector<double> vCoordX;
	vector<double> vCoordY;

	cin >> n >> r;
	for (unsigned int i = 0; i < n; i++) {
		cin >> x >> y;
		vCoordX.push_back(x);
		vCoordY.push_back(y);
	}

	len = 2 * atan(1) * 4 * r;
	for (unsigned int i = 1; i < vCoordX.size(); i++) {
		len += sqrt(pow((vCoordX[i] - vCoordX[i-1]), 2) + pow((vCoordY[i] - vCoordY[i-1]), 2));
	}
	len += sqrt(pow((vCoordX[vCoordX.size()-1] - vCoordX[0]), 2) + pow((vCoordY[vCoordX.size()-1] - vCoordY[0]), 2));

	cout << setprecision(2) << fixed << len;

	return 0;
}
