// 2023/04/25 10:36:14
#include <bits/stdc++.h>
using namespace std;

const long long mod = 100003;

typedef vector<int> vec;
typedef vector<vector<int>> mat;

vector<vector<int>> mul(const mat& a, const mat& b)
{
    vector<vector<int>> c(a.size(), vector<int>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++)
    {
        for (int k = 0; k < b.size(); k++)
        {
            for (int j = 0; j < b[0].size(); j++)
            {
                c[i][j] += a[i][k] * b[k][j] % mod;
            }
        }
    }
    return c;
}

mat pow(mat A, int n)
{
    mat B(A.size(), vec(A.size(), 0));
    for (int i = 0; i < A.size(); i++)
        B[i][i] = 1;
    while (n)
    {
        if (n & 1)
            B = mul(A, B);

        A = mul(A, A);
        n /= 2;
    }
    return B;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    mat A(2, vec(2));
    A[0][0] = 1;
    A[0][1] = 1;
    A[1][0] = 1;
    A[1][1] = 0;
    A = pow(A, n);
    cout << A[1][0] << endl;

    cout << flush;
    return 0;
}