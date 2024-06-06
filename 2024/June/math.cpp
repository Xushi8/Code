#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	constexpr long double a = 1, b = 2;
	long double ans2 = ((b - a) / 8) * (log(a) + 3 * log((2 * a + b) / 3) + 3 * log((a + 2 * b) / 3) + log(b));
	cout << ans2 << endl;

	long double ans4 = ((b - a) / 90) * (7 * log(a) + 32 * log((3 * a + b) / 4) + 12 * log((2 * a + 2 * b) / 4) + 32 * log((a + 3 * b) / 4) + 7 * log(b));
	cout << ans4 << endl;

	cout << setprecision(10) << fixed;
	cout << static_cast<long double>(120) / static_cast<long double>(1935360) << endl;
}