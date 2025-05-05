#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

void printKeywordLinesByFrequencyOfOccurrence(const char *filename, const char *keyword) {
    ifstream ifs(filename);
    string s;
    vector<string> all;
    while (getline(ifs, s))
    {
        if (s.find(keyword) != string::npos) {
            all.emplace_back(std::move(s));
        }
    }

    sort(all.begin(), all.end());
    unordered_map<string, int> cnt;
    for(string const& s : all) {
        cnt[s]++;
    }

    vector<pair<int, string>> ans;
    for(auto const& [s, c] : cnt) {
        ans.emplace_back(c, s);
    }

    sort(ans.begin(), ans.end(), greater<>());

    for(auto const& [c, s] : ans) {
        cout << c << ' ' << s << '\n';
    }
}

int main() {
    printKeywordLinesByFrequencyOfOccurrence("a.txt", "test");
}