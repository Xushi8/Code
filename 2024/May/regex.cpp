#include <iostream>
#include <regex>
#include <string>
using namespace std;


int main()
{
	string s;
	cin >> s;
	regex ex(R"(((25[0-5]|2[0-4]\d|[01]?\d?\d)\.){3}(25[0-5]|2[0-4]\d|[01]?\d?\d))");
	cout << (regex_match(s, ex) ? "Yes" : "No") << '\n';
	return 0;
}