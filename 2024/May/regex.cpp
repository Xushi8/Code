#include <iostream>
#include <regex>
#include <string>
using namespace std;


int main()
{
	string s = "ab123cd46ef"; // ①
	regex ex("\\d+");		// ②

	smatch match;				// ③
	regex_search(s, match, ex); // ④

	cout << s << " contains digit: " << match[0] << endl; // ⑤

	for (auto const& x : match)
	{
		cout << x << endl;
    }
	return 0;
}