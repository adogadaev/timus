#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
	double n, r;
	cin >> n >> r;
	double diag = n * sqrt(2);
	double area;
	if (n/2 < r && r < diag/2) {
		double segm_len = 2 * sqrt(pow(r,2) - pow(n,2)/4);
		double segm_angle = 2 * asin(segm_len / (2*r));
		double segm_area = pow(r,2)/2 * (segm_angle - sin(segm_angle));
		area = atan(1)*4 * pow(r,2) - 4*segm_area;
	} else if (r >= diag/2)
		area = n*n;
	else
		area = atan(1)*4 * pow(r,2);

	cout << setprecision(3) << fixed << area << endl;

	return 0;
}
