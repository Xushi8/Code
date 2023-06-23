// 2023/04/27 11:37:52
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);
    if (a + b <= c)
    {
        cout << "Not triangle\n";
        return 0;
    }
    
    if (a * a + b * b == c * c)
        cout << "Right triangle\n";
    else if (a * a + b * b > c * c)
        cout << "Acute triangle\n";
    else
        cout << "Obtuse triangle\n";
    
    if (a == b)
        cout << "Isosceles triangle\n";
    if (a == b && b == c)
        cout << "Equilateral triangle\n";

    cout << endl;
    return 0;
}