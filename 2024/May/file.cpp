#include <filesystem>
#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include <set>
#include <algorithm>
#include <iostream>
using std::sort;
using std::regex;
using std::regex_search;
using std::smatch;
using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;
using std::string_view;
using std::set;
using std::cout;
namespace fs = std::filesystem;

vector<string> get_submitted(fs::path const& path)
{
	vector<string> submitted;
	for (auto const& entry : fs::directory_iterator(path))
	{
		if (!fs::is_directory(entry))
		{
			submitted.emplace_back(entry.path().filename());
		}
	}
	return submitted;
}

void to_submitted_file(vector<string> const& submitted)
{
	ofstream ofs("submitted.txt");
	regex ex("20[0-9]{6}");
	smatch match;
	for (auto const& s : submitted)
	{
		regex_search(s, match, ex);
		ofs << match[0].str() << '\n';
	}
}

vector<int> get_nosubmitted()
{
	vector<int> res;
	ifstream ifs("submitted.txt");
	set<int> submitted;
	int x;
	while (ifs >> x)
	{
		submitted.emplace(x);
	}
	ifs.open("all.txt");
	while (ifs >> x)
	{
		if (!submitted.contains(x))
		{
			res.emplace_back(x);
		}
	}
	return res;
}

int main(int argc, char* argv[])
{
	fs::path path;
	if (argc == 1)
	{
		path = fs::current_path();
	}
	else
	{
		path = argv[1];
	}

	auto submitted = get_submitted(path);

	to_submitted_file(submitted);

	auto no_submitted = get_nosubmitted();

	ofstream ofs("no_sumbitted.txt");
	sort(no_submitted.begin(), no_submitted.end());
	for (auto const& x : no_submitted)
	{
		cout << x << '\n';
		ofs << x << '\n';
	}

	return 0;
}