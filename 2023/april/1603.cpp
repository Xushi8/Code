// 2023/04/28 15:26:56
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string tmp;
    getline(cin, tmp);
    vector<string> str{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
    stringstream ss;
    int arr[23] = { 0 };
    while (ss << tmp)
    {
        string a;
        ss >> a;
        for (int i = 0; i < 20; i++)
        {
            if (a == str[i])
            {
                arr[i + 1]++;
            }
        }
    }
    string ans = "";
    bool flag = 1;
    for (int i = 0; i < 22; i++)
    {
        while (arr[i] != 0)
        {
            if (i < 10 && flag)
            {
                ans += i;
                flag = 0;
            }
            else if(i < 10 && !flag)
            {
                ans += '0' + i;
            }
            else
            {
                ans += i;
            }
        }
    }
    cout << ans;

    cout << endl;
    return 0;
}