#include <iostream>
#define endl '\n'
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	// freopen("answer.txt", "w", stdout); //去掉注释，就可以输出到文件; 保持这行注释，就可以输出到控制台。由于答案数量较多，输出到控制台的话，不一定能显示完全
	for (int c = 10; c < 100; c++)
	{
		for (int b1 = 1; b1 < 10; b1++)
		{
			for (int b2 = 0; b2 < 100; b2++)
			{
				int b = b1 * 1000 + 800 + b2;
				int a = b * c;
				if (a >= 100000 && a < 1000000)
				{
					cout << "a=" << a << ",b=" << b << ",c=" << c << endl;
				}
			}
		}
	}
	return 0;
}