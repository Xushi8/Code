#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (r + l) / 2;
        cout << '?' << ' ' << mid << endl;
        int x;
        cin >> x;
        if (x == 1)
        {
            r = mid - 1;
        }
        else if (x == -1)
        {
            l = mid + 1;
        }
        else
        {
            cout << '!' << ' ' << mid << endl;
            break;
        }
    }
    return 0;
}