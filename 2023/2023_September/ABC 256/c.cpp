// 2023/09/18 18:46:47
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int h1, h2, h3, w1, w2, w3;
int arr[3][3];

bool check()
{
    int h11 = arr[0][0] + arr[0][1] + arr[0][2];
    int h22 = arr[1][0] + arr[1][1] + arr[1][2];
    int h33 = arr[2][0] + arr[2][1] + arr[2][2];
    int w11 = arr[0][0] + arr[1][0] + arr[2][0];
    int w22 = arr[0][1] + arr[1][1] + arr[2][1];
    int w33 = arr[0][2] + arr[1][2] + arr[2][2];
    return h11 == h1 && h22 == h2 && h33 == h3 && w11 == w1 && w22 == w2 && w33 == w3 && arr[0][2] > 0 && arr[1][2] > 0 && arr[2][2] > 0 && arr[2][1] > 0 && arr[2][0] > 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

    int ans = 0;
    for (int i = 1; i < 30; i++)
    {
        arr[0][0] = i;
        for (int j = 1; j < 30; j++)
        {
            arr[0][1] = j;

            for (int k = 1; k < 30; k++)
            {
                arr[1][0] = k;

                for (int l = 1; l < 30; l++)
                {
                    arr[1][1] = l;

                    arr[0][2] = h1 - (arr[0][0] + arr[0][1]);
                    arr[1][2] = h2 - (arr[1][0] + arr[1][1]);
                    arr[2][0] = w1 - (arr[1][0] + arr[0][0]);
                    arr[2][1] = w2 - (arr[0][1] + arr[1][1]);
                    arr[2][2] = w3 - (arr[0][2] + arr[1][2]);
                    ans += check();
                }
            }
        }
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}